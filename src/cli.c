/*
 *      Copyright (C) 2000,2001 Nikos Mavroyanopoulos
 *
 * This file is part of GNUTLS.
 *
 * GNUTLS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GNUTLS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include "../lib/gnutls.h"
#include <sys/time.h>
#include <signal.h>
#include <netdb.h>
#include <common.h>

#ifndef SHUT_WR
# define SHUT_WR 1
#endif

#ifndef SHUT_RDWR
# define SHUT_RDWR 2
#endif

#define SA struct sockaddr
#define ERR(err,s) if (err==-1) {perror(s);return(1);}
#define MAX_BUF 4096

#define RESUME

#define MAX(X,Y) (X >= Y ? X : Y);
#define CAFILE "x509/ca.pem"
#define CRLFILE NULL
#define CLIKEYFILE "x509/clikey.pem"
#define CLICERTFILE "x509/clicert.pem"

static int print_info( GNUTLS_STATE state) {
const char *tmp;
CredType cred;
gnutls_DN dn;
const gnutls_datum* cert_list;
CertificateStatus status;
int cert_list_size = 0;

	tmp = gnutls_kx_get_name(gnutls_kx_get_algo( state));
	printf("- Key Exchange: %s\n", tmp);

	cred = gnutls_get_auth_type(state);
	switch(cred) {
		case GNUTLS_ANON:
			printf("- Anonymous DH using prime of %d bits\n",
			       gnutls_anon_client_get_dh_bits( state));

		case GNUTLS_X509PKI:
			cert_list = gnutls_x509pki_client_get_peer_certificate_list( state, &cert_list_size);
			status = gnutls_x509pki_client_get_peer_certificate_status( state);
			
			switch( status) {
			case GNUTLS_CERT_NOT_TRUSTED:
				printf("- Peer's X509 Certificate was NOT verified\n");
				break;
			case GNUTLS_CERT_EXPIRED:
				printf("- Peer's X509 Certificate was verified but is expired\n");
				break;
			case GNUTLS_CERT_TRUSTED:
				printf("- Peer's X509 Certificate was verified\n");
				break;
			case GNUTLS_CERT_NONE:
				printf("- Peer did not send any X509 Certificate.\n");
				break;
			case GNUTLS_CERT_INVALID:
				printf("- Peer's X509 Certificate was invalid\n");
				break;
			}
			
			if (cert_list_size > 0) {
				printf(" - Certificate info:\n");
				printf(" - Certificate version: #%d\n", gnutls_x509pki_extract_certificate_version( &cert_list[0]));

				gnutls_x509pki_extract_certificate_dn( &cert_list[0], &dn);
				PRINT_DN( dn);

				gnutls_x509pki_extract_certificate_issuer_dn( &cert_list[0], &dn);
				printf(" - Certificate Issuer's info:\n");
				PRINT_DN( dn);
			}
	}

	tmp = gnutls_protocol_get_name(gnutls_protocol_get_version(state));
	printf("- Version: %s\n", tmp);

	tmp = gnutls_compression_get_name(gnutls_compression_get_algo( state));
	printf("- Compression: %s\n", tmp);

	tmp = gnutls_cipher_get_name(gnutls_cipher_get_algo( state));
	printf("- Cipher: %s\n", tmp);

	tmp = gnutls_mac_get_name(gnutls_mac_get_algo( state));
	printf("- MAC: %s\n", tmp);

	return 0;
}

int cert_callback( const gnutls_datum *client_certs, int ncerts, const gnutls_datum* req_ca_cert, int nreqs) {

	if (client_certs==NULL) {
		return 0; /* means the we will only be called again
		           * if the library cannot determine which
		           * certificate to send
		           */
	}

#if 0
	/* here we should prompt the user and ask him
	 * which certificate to choose. Too bored to 
	 * implement that. --nmav
	 */
	for (i=0;i<ncerts;i++){
		fprintf(stderr, "%s.", client_cert->common_name);
		fprintf(stderr, "%s\n", issuer_cert->common_name);
	}
	for (i=0;i<nreqs;i++){
		fprintf(stderr, "%s.", req_ca_cert->common_name);
	}
	fprintf(stderr, "\n");
	return 0;
#endif

	return -1; /* send no certificate to the peer */
}

int main(int argc, char** argv)
{
	int err, ret;
	int sd, ii;
	struct sockaddr_in sa;
	GNUTLS_STATE state;
	char buffer[MAX_BUF+1];
	char *session;
	char* session_id;
	int session_size;
	int session_id_size;
	char* tmp_session_id;
	int tmp_session_id_size;
	fd_set rset;
	int maxfd;
	struct timeval tv;
	int user_term = 0;
	SRP_CLIENT_CREDENTIALS cred;
	X509PKI_CLIENT_CREDENTIALS xcred;
	struct hostent* server_host;
	
	signal( SIGPIPE, SIG_IGN);
	
	if (argc!=3) {
		fprintf(stderr, "Usage: cli [HOST] [PORT]\n");
		exit(1);
	}
	
	if (gnutls_global_init() < 0) {
		fprintf(stderr, "global state initialization error\n");
		exit(1);
	}

	/* get server name */
	server_host = gethostbyname( argv[1]);
	if (server_host==NULL) {
		fprintf(stderr, "Cannot resolve %s\n", argv[1]);
		exit(1);
	}

	/* X509 stuff */
	if (gnutls_x509pki_allocate_client_sc( &xcred, 1) < 0) {  /* space for 1 certificate */
		fprintf(stderr, "memory error\n");
		exit(1);
	}
	gnutls_x509pki_set_client_trust( xcred, CAFILE, CRLFILE);
	gnutls_x509pki_set_client_key( xcred, CLICERTFILE, CLIKEYFILE);
	gnutls_x509pki_set_client_cert_callback( xcred, cert_callback);

	/* SRP stuff */
	if (gnutls_srp_allocate_client_sc( &cred)<0) {
		fprintf(stderr, "memory error\n");
		exit(1);
	}
	gnutls_srp_set_client_cred( cred, "test", "test");
	
	sd = socket(AF_INET, SOCK_STREAM, 0);
	ERR(sd, "socket");

	memset(&sa, '\0', sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(atoi(argv[2]));

	sa.sin_addr.s_addr = *((unsigned int*)server_host->h_addr);

	inet_ntop( AF_INET, &sa.sin_addr, buffer, MAX_BUF);
	fprintf(stderr, "Connecting to '%s'...\n", buffer);
	
	err = connect(sd, (SA *) & sa, sizeof(sa));
	ERR(err, "connect");

#ifdef RESUME
	gnutls_init(&state, GNUTLS_CLIENT);
	
	gnutls_protocol_set_priority( state, GNUTLS_TLS1, GNUTLS_SSL3, 0);
	gnutls_cipher_set_priority( state, GNUTLS_3DES_CBC, GNUTLS_RIJNDAEL_CBC, 0);
	gnutls_compression_set_priority( state, GNUTLS_ZLIB, GNUTLS_NULL_COMPRESSION, 0);
	gnutls_kx_set_priority( state, GNUTLS_KX_DHE_RSA, GNUTLS_KX_RSA, GNUTLS_KX_SRP, GNUTLS_KX_DH_ANON, 0);
	gnutls_mac_set_priority( state, GNUTLS_MAC_SHA, GNUTLS_MAC_MD5, 0);

	gnutls_set_cred( state, GNUTLS_ANON, NULL);
	gnutls_set_cred( state, GNUTLS_SRP, cred);
	gnutls_set_cred( state, GNUTLS_X509PKI, xcred);

/* This TLS extension may break old implementations.
 */
	gnutls_ext_set_name_ind( state, GNUTLS_DNSNAME, "localhost"); 

	gnutls_transport_set_ptr( state, sd);
	do {
		ret = gnutls_handshake( state);
	} while( ret==GNUTLS_E_INTERRUPTED || ret==GNUTLS_E_AGAIN);

	if (ret < 0) {
		if (ret==GNUTLS_E_WARNING_ALERT_RECEIVED || ret==GNUTLS_E_FATAL_ALERT_RECEIVED)
			printf("*** Received alert [%d]\n", gnutls_get_last_alert(state));

		fprintf(stderr, "*** Handshake has failed\n");
		gnutls_perror(ret);
		gnutls_deinit(state);
		return 1;
	} else {
		printf("- Handshake was completed\n");
	}
	
	gnutls_session_get_data( state, NULL, &session_size);
	session = malloc(session_size);
	gnutls_session_get_data( state, session, &session_size);

	gnutls_session_get_id( state, NULL, &session_id_size);
	session_id = malloc(session_id_size);
	gnutls_session_get_id( state, session_id, &session_id_size);

/* print some information */
 	print_info( state);

	printf("- Disconnecting\n");
	do {
		ret = gnutls_bye( state, GNUTLS_SHUT_RDWR);
	} while( ret==GNUTLS_E_INTERRUPTED || ret==GNUTLS_E_AGAIN);
	
	shutdown( sd, SHUT_WR);
	close(sd);
	gnutls_deinit( state);	

	printf("\n\n- Connecting again- trying to resume previous session\n");
	sd = socket(AF_INET, SOCK_STREAM, 0);
	ERR(sd, "socket");

	err = connect(sd, (SA *) & sa, sizeof(sa));
	ERR(err, "connect");

#endif

	/* Begin handshake again */
	gnutls_init(&state, GNUTLS_CLIENT);
	
	gnutls_protocol_set_priority( state, GNUTLS_TLS1, GNUTLS_SSL3, 0);
	gnutls_cipher_set_priority( state, GNUTLS_3DES_CBC, GNUTLS_RIJNDAEL_CBC, 0);
	gnutls_compression_set_priority( state, GNUTLS_ZLIB, GNUTLS_NULL_COMPRESSION, 0);
	gnutls_kx_set_priority( state, GNUTLS_KX_DHE_RSA, GNUTLS_KX_RSA, GNUTLS_KX_SRP, GNUTLS_KX_DH_ANON, 0);
	gnutls_mac_set_priority( state, GNUTLS_MAC_SHA, GNUTLS_MAC_MD5, 0);

	gnutls_set_cred( state, GNUTLS_ANON, NULL);
	gnutls_set_cred( state, GNUTLS_SRP, cred);
	gnutls_set_cred( state, GNUTLS_X509PKI, xcred);

	gnutls_ext_set_name_ind( state, GNUTLS_DNSNAME, "hello.server.org");

#ifdef RESUME
	gnutls_session_set_data( state, session, session_size);
	free(session);
#endif

	gnutls_transport_set_ptr( state, sd);
	do {
		ret = gnutls_handshake( state);
	} while( ret==GNUTLS_E_INTERRUPTED || ret==GNUTLS_E_AGAIN);

	if (ret < 0) {
		if (ret==GNUTLS_E_WARNING_ALERT_RECEIVED || ret==GNUTLS_E_FATAL_ALERT_RECEIVED)
			printf("*** Received alert [%d]\n", gnutls_get_last_alert(state));
		fprintf(stderr, "*** Handshake failed\n");
		gnutls_perror(ret);
		gnutls_deinit(state);
		return 1;
	} else {
		printf("- Handshake was completed\n");
	}

	/* check if we actually resumed the previous session */
	gnutls_session_get_id( state, NULL, &tmp_session_id_size);
	tmp_session_id = malloc(tmp_session_id_size);
	gnutls_session_get_id( state, tmp_session_id, &tmp_session_id_size);

	if (memcmp( tmp_session_id, session_id, session_id_size)==0) {
		printf("- Previous session was resumed\n");
	} else {
		fprintf(stderr, "*** Previous session was NOT resumed\n");	
	}
	free(tmp_session_id);
	free(session_id);

/* print some information */
	print_info( state);
	
	printf("\n- Simple Client Mode:\n\n");

	FD_ZERO(&rset);
	for(;;) {
		FD_SET(fileno(stdin), &rset);
		FD_SET(sd, &rset);
		
		maxfd = MAX(fileno(stdin), sd);
		tv.tv_sec = 3;
		tv.tv_usec = 0;
		select(maxfd+1, &rset, NULL, NULL, &tv);

		if (FD_ISSET(sd, &rset)) {
			bzero(buffer, MAX_BUF+1);
			do {
				ret = gnutls_read( state, buffer, MAX_BUF);
			} while( ret==GNUTLS_E_INTERRUPTED || ret==GNUTLS_E_AGAIN);
			/* remove new line */

			if (gnutls_is_fatal_error(ret) == 1 || ret==0) {
				if (ret == 0) {
					printf("- Peer has closed the GNUTLS connection\n");
					break;
				} else {
					fprintf(stderr, "*** Received corrupted data(%d) - server has terminated the connection abnormally\n",
						ret);
					break;
				}
			} else {
				if (ret==GNUTLS_E_WARNING_ALERT_RECEIVED || ret==GNUTLS_E_FATAL_ALERT_RECEIVED)
					printf("* Received alert [%d]\n", gnutls_get_last_alert(state));
				if (ret==GNUTLS_E_REHANDSHAKE) {
					do {
						ret = gnutls_handshake( state);
					} while( ret==GNUTLS_E_AGAIN || ret==GNUTLS_E_INTERRUPTED);
					if (ret==0) printf("* Rehandshake was performed\n");
					else {
						printf("* Rehandshake Failed [%d]\n", ret);
					}
				}
				if (ret > 0) {
					printf("- Received[%d]: ", ret);
					for (ii=0;ii<ret;ii++) {
						fputc(buffer[ii], stdout);
					}
					fputs("\n", stdout);
				}
			}
			if (user_term!=0) break;
		}
		if (FD_ISSET(fileno(stdin), &rset)) {
	
			if( fgets(buffer, MAX_BUF, stdin) == NULL) {
				do {
					ret = gnutls_bye( state, GNUTLS_SHUT_WR);
				} while( ret==GNUTLS_E_INTERRUPTED || ret==GNUTLS_E_AGAIN);
				user_term = 1;
				continue;
			}
			do {
				ret = gnutls_write( state, buffer, strlen(buffer));
			} while(ret==GNUTLS_E_AGAIN || ret==GNUTLS_E_INTERRUPTED);
			printf("- Sent: %d bytes\n", ret);

		}
	}
	if (user_term!=0) do ret = gnutls_bye( state, GNUTLS_SHUT_RDWR);
	while( ret==GNUTLS_E_INTERRUPTED || ret==GNUTLS_E_AGAIN);

	shutdown( sd, SHUT_RDWR); /* no more receptions */
	close(sd);
	
	gnutls_deinit( state);

	gnutls_srp_free_client_sc( cred);
	gnutls_x509pki_free_client_sc( xcred);

	gnutls_global_deinit();
	
	return 0;
}
