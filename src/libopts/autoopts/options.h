/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (options.h)
 *  
 *  It has been AutoGen-ed  February 25, 2012 at 01:14:45 PM by AutoGen 5.15pre14
 *  From the definitions    funcs.def
 *  and the template file   options_h
 *
 *  This file defines all the global structures and special values
 *  used in the automated option processing library.
 *
 *  Automated Options Copyright (C) 1992-2012 by Bruce Korb
 *
 *   *  AutoOpts is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  AutoOpts is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU Lesser General Public License for more details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */
#ifndef AUTOOPTS_OPTIONS_H_GUARD
#define AUTOOPTS_OPTIONS_H_GUARD 1
#include <sys/types.h>
#include <stdio.h>

#if defined(HAVE_STDINT_H)
# include <stdint.h>
#elif defined(HAVE_INTTYPES_H)
# include <inttypes.h>
#endif /* HAVE_STDINT/INTTYPES_H */

#if defined(HAVE_LIMITS_H)
# include <limits.h>
#elif defined(HAVE_SYS_LIMITS_H)
# include <sys/limits.h>
#endif /* HAVE_LIMITS/SYS_LIMITS_H */

#if defined(HAVE_SYSEXITS_H)
#  include <sysexits.h>
#endif /* HAVE_SYSEXITS_H */
// END-CONFIGURED-HEADERS
#ifndef  EX_USAGE
# define EX_USAGE               64
#endif

/*
 *  PUBLIC DEFINES
 *
 *  The following defines may be used in applications that need to test the
 *  state of an option.  To test against these masks and values, a pointer
 *  to an option descriptor must be obtained.  There are two ways:
 *
 *  1. inside an option processing procedure, it is the second argument,
 *     conventionally "tOptDesc* pOD".
 *
 *  2. Outside of an option procedure (or to reference a different option
 *     descriptor), use either "&DESC( opt_name )" or "&pfx_DESC( opt_name )".
 *
 *  See the relevant generated header file to determine which and what
 *  values for "opt_name" are available.
 */
#define OPTIONS_STRUCT_VERSION      147459
#define OPTIONS_VERSION_STRING      "36:3:11"
#define OPTIONS_MINIMUM_VERSION     102400
#define OPTIONS_MIN_VER_STRING      "25:0:0"
#define OPTIONS_VER_TO_NUM(_v, _r)  (((_v) * 4096) + (_r))
	
typedef enum {
    OPARG_TYPE_NONE             =  0,
    OPARG_TYPE_STRING           =  1,    /* default type/ vanilla string      */
    OPARG_TYPE_ENUMERATION      =  2,    /* opt arg is an enum (keyword list) */
    OPARG_TYPE_BOOLEAN          =  3,    /* opt arg is boolean-valued         */
    OPARG_TYPE_MEMBERSHIP       =  4,    /* opt arg sets set membership bits  */
    OPARG_TYPE_NUMERIC          =  5,    /* opt arg is a long int             */
    OPARG_TYPE_HIERARCHY        =  6,    /* option arg is hierarchical value  */
    OPARG_TYPE_FILE             =  7,    /* option arg names a file           */
    OPARG_TYPE_TIME             =  8,    /* opt arg is a time duration        */
    OPARG_TYPE_FLOAT            =  9,    /* opt arg is a floating point num   */
    OPARG_TYPE_DOUBLE           = 10,    /* opt arg is a double prec. float   */
    OPARG_TYPE_LONG_DOUBLE      = 11,    /* opt arg is a long double prec.    */
    OPARG_TYPE_LONG_LONG        = 12     /* opt arg is a long long int        */
} teOptArgType;

typedef struct optionValue {
    teOptArgType        valType;
    char*               pzName;
    union {
        char            strVal[1];      /* OPARG_TYPE_STRING      */
        unsigned int    enumVal;        /* OPARG_TYPE_ENUMERATION */
        unsigned int    boolVal;        /* OPARG_TYPE_BOOLEAN     */
        unsigned long   setVal;         /* OPARG_TYPE_MEMBERSHIP  */
        long            longVal;        /* OPARG_TYPE_NUMERIC     */
        void*           nestVal;        /* OPARG_TYPE_HIERARCHY   */
    } v;
} tOptionValue;

typedef enum {
    FTYPE_MODE_MAY_EXIST        = 0x00,
    FTYPE_MODE_MUST_EXIST       = 0x01,
    FTYPE_MODE_MUST_NOT_EXIST   = 0x02,
    FTYPE_MODE_EXIST_MASK       = 0x03,
    FTYPE_MODE_NO_OPEN          = 0x00,
    FTYPE_MODE_OPEN_FD          = 0x10,
    FTYPE_MODE_FOPEN_FP         = 0x20,
    FTYPE_MODE_OPEN_MASK        = 0x30
} teOptFileType;

typedef union {
    int             file_flags;
    char const *    file_mode;
} tuFileMode;

typedef struct argList tArgList;
#define MIN_ARG_ALLOC_CT   6
#define INCR_ARG_ALLOC_CT  8
struct argList {
    int             useCt;
    int             allocCt;
    char const *    apzArgs[MIN_ARG_ALLOC_CT];
};

/*
 *  Bits in the fOptState option descriptor field.
 */
typedef enum {
    OPTST_SET_ID             =   0, /* Set via the "SET_OPT()" macro */
    OPTST_PRESET_ID          =   1, /* Set via an RC/INI file        */
    OPTST_DEFINED_ID         =   2, /* Set via a command line option */
    OPTST_RESET_ID           =   3, /* Reset via command line option */
    OPTST_EQUIVALENCE_ID     =   4, /* selected by equiv'ed option   */
    OPTST_DISABLED_ID        =   5, /* option is in disabled state   */
    OPTST_ALLOC_ARG_ID       =   6, /* pzOptArg was allocated        */
    OPTST_NO_INIT_ID         =   8, /* option cannot be preset       */
    OPTST_NUMBER_OPT_ID      =   9, /* opt value (flag) is any digit */
    OPTST_STACKED_ID         =  10, /* opt uses optionStackArg proc  */
    OPTST_INITENABLED_ID     =  11, /* option defaults to enabled    */
    OPTST_ARG_TYPE_1_ID      =  12, /* bit 1 of arg type enum        */
    OPTST_ARG_TYPE_2_ID      =  13, /* bit 2 of arg type enum        */
    OPTST_ARG_TYPE_3_ID      =  14, /* bit 3 of arg type enum        */
    OPTST_ARG_TYPE_4_ID      =  15, /* bit 4 of arg type enum        */
    OPTST_ARG_OPTIONAL_ID    =  16, /* the option arg not required   */
    OPTST_IMM_ID             =  17, /* process opt on first pass     */
    OPTST_DISABLE_IMM_ID     =  18, /* process disablement immed.    */
    OPTST_OMITTED_ID         =  19, /* compiled out of program       */
    OPTST_MUST_SET_ID        =  20, /* must be set or pre-set        */
    OPTST_DOCUMENT_ID        =  21, /* opt is for doc only           */
    OPTST_TWICE_ID           =  22, /* process opt twice - imm + reg */
    OPTST_DISABLE_TWICE_ID   =  23, /* process disabled option twice */
    OPTST_SCALED_NUM_ID      =  24, /* scaled integer value          */
    OPTST_NO_COMMAND_ID      =  25, /* disable from cmd line         */
    OPTST_DEPRECATED_ID      =  26, /* support is being removed      */
    OPTST_ALIAS_ID           =  27  /* alias for other option        */
} opt_state_enum_t;

#define OPTST_INIT               0U
#define OPTST_SET            (1U << OPTST_SET_ID)
#define OPTST_PRESET         (1U << OPTST_PRESET_ID)
#define OPTST_DEFINED        (1U << OPTST_DEFINED_ID)
#define OPTST_RESET          (1U << OPTST_RESET_ID)
#define OPTST_EQUIVALENCE    (1U << OPTST_EQUIVALENCE_ID)
#define OPTST_DISABLED       (1U << OPTST_DISABLED_ID)
#define OPTST_ALLOC_ARG      (1U << OPTST_ALLOC_ARG_ID)
#define OPTST_NO_INIT        (1U << OPTST_NO_INIT_ID)
#define OPTST_NUMBER_OPT     (1U << OPTST_NUMBER_OPT_ID)
#define OPTST_STACKED        (1U << OPTST_STACKED_ID)
#define OPTST_INITENABLED    (1U << OPTST_INITENABLED_ID)
#define OPTST_ARG_TYPE_1     (1U << OPTST_ARG_TYPE_1_ID)
#define OPTST_ARG_TYPE_2     (1U << OPTST_ARG_TYPE_2_ID)
#define OPTST_ARG_TYPE_3     (1U << OPTST_ARG_TYPE_3_ID)
#define OPTST_ARG_TYPE_4     (1U << OPTST_ARG_TYPE_4_ID)
#define OPTST_ARG_OPTIONAL   (1U << OPTST_ARG_OPTIONAL_ID)
#define OPTST_IMM            (1U << OPTST_IMM_ID)
#define OPTST_DISABLE_IMM    (1U << OPTST_DISABLE_IMM_ID)
#define OPTST_OMITTED        (1U << OPTST_OMITTED_ID)
#define OPTST_MUST_SET       (1U << OPTST_MUST_SET_ID)
#define OPTST_DOCUMENT       (1U << OPTST_DOCUMENT_ID)
#define OPTST_TWICE          (1U << OPTST_TWICE_ID)
#define OPTST_DISABLE_TWICE  (1U << OPTST_DISABLE_TWICE_ID)
#define OPTST_SCALED_NUM     (1U << OPTST_SCALED_NUM_ID)
#define OPTST_NO_COMMAND     (1U << OPTST_NO_COMMAND_ID)
#define OPTST_DEPRECATED     (1U << OPTST_DEPRECATED_ID)
#define OPTST_ALIAS          (1U << OPTST_ALIAS_ID)
#define OPT_STATE_MASK       0x0FFFFF7FU

#define OPTST_SET_MASK       ( \
        OPTST_DEFINED | OPTST_PRESET |  OPTST_RESET | \
        OPTST_SET \
        /* 0x0000000FU */ )

#define OPTST_MUTABLE_MASK   ( \
        OPTST_ALLOC_ARG |   OPTST_DEFINED | \
        OPTST_DISABLED |    OPTST_EQUIVALENCE | \
        OPTST_PRESET |      OPTST_RESET | \
        OPTST_SET \
        /* 0x0000007FU */ )

#define OPTST_SELECTED_MASK  ( \
        OPTST_DEFINED | OPTST_SET \
        /* 0x00000005U */ )

#define OPTST_ARG_TYPE_MASK  ( \
        OPTST_ARG_TYPE_1 | OPTST_ARG_TYPE_2 | OPTST_ARG_TYPE_3 | \
        OPTST_ARG_TYPE_4 \
        /* 0x0000F000U */ )

#define OPTST_NO_USAGE_MASK  ( \
        OPTST_DEPRECATED | OPTST_NO_COMMAND | OPTST_OMITTED \
        /* 0x06080000U */ )

#define OPTST_IMMUTABLE_MASK ( \
        OPTST_DOCUMENT | OPTST_OMITTED \
        /* 0x00280000U */ )

#define OPTST_DO_NOT_SAVE_MASK   ( \
        OPTST_DOCUMENT | OPTST_NO_INIT |  OPTST_OMITTED \
        /* 0x00280100U */ )

#define OPTST_NO_OUTPUT_MASK ( \
        OPTST_ALIAS |    OPTST_DOCUMENT | OPTST_OMITTED \
        /* 0x08280000U */ )

#ifdef NO_OPTIONAL_OPT_ARGS
# undef  OPTST_ARG_OPTIONAL
# define OPTST_ARG_OPTIONAL   0
#endif

#define VENDOR_OPTION_VALUE   'W'

#define OPTST_PERSISTENT_MASK (~OPTST_MUTABLE_MASK)

#define SELECTED_OPT(_od)     ((_od)->fOptState  & OPTST_SELECTED_MASK)
#define UNUSED_OPT(  _od)     (((_od)->fOptState & OPTST_SET_MASK) == 0)
#define DISABLED_OPT(_od)     ((_od)->fOptState  & OPTST_DISABLED)
#define OPTION_STATE(_od)     ((_od)->fOptState)
#define OPTST_SET_ARGTYPE(_n) ((_n) << OPTST_ARG_TYPE_1_ID)
#define OPTST_GET_ARGTYPE(_f) (((_f)&OPTST_ARG_TYPE_MASK)>>OPTST_ARG_TYPE_1_ID)

/*
 *  PRIVATE INTERFACES
 *
 *  The following values are used in the generated code to communicate
 *  with the option library procedures.  They are not for public use
 *  and may be subject to change.
 */

/*
 *  Define the processing state flags
 */
typedef enum {
    OPTPROC_LONGOPT_ID         =   0, /* Process long style options     */
    OPTPROC_SHORTOPT_ID        =   1, /* Process short style "flags"    */
    OPTPROC_ERRSTOP_ID         =   2, /* Stop on argument errors        */
    OPTPROC_DISABLEDOPT_ID     =   3, /* Current option is disabled     */
    OPTPROC_NO_REQ_OPT_ID      =   4, /* no options are required        */
    OPTPROC_NUM_OPT_ID         =   5, /* there is a number option       */
    OPTPROC_INITDONE_ID        =   6, /* have inits been done?          */
    OPTPROC_NEGATIONS_ID       =   7, /* any negation options?          */
    OPTPROC_ENVIRON_ID         =   8, /* check environment?             */
    OPTPROC_NO_ARGS_ID         =   9, /* Disallow remaining arguments   */
    OPTPROC_ARGS_REQ_ID        =  10, /* Require args after options     */
    OPTPROC_REORDER_ID         =  11, /* reorder operands after opts    */
    OPTPROC_GNUUSAGE_ID        =  12, /* emit usage in GNU style        */
    OPTPROC_TRANSLATE_ID       =  13, /* Translate strings in tOptions  */
    OPTPROC_MISUSE_ID          =  14, /* no usage on usage error        */
    OPTPROC_IMMEDIATE_ID       =  15, /* immediate options active       */
    OPTPROC_NXLAT_OPT_CFG_ID   =  16, /* suppress for config only       */
    OPTPROC_NXLAT_OPT_ID       =  17, /* suppress xlation always        */
    OPTPROC_VENDOR_OPT_ID      =  18, /* vendor options active          */
    OPTPROC_PRESETTING_ID      =  19  /* opt processing in preset state */
} optproc_state_enum_t;

#define OPTPROC_NONE               0U
#define OPTPROC_LONGOPT        (1U << OPTPROC_LONGOPT_ID)
#define OPTPROC_SHORTOPT       (1U << OPTPROC_SHORTOPT_ID)
#define OPTPROC_ERRSTOP        (1U << OPTPROC_ERRSTOP_ID)
#define OPTPROC_DISABLEDOPT    (1U << OPTPROC_DISABLEDOPT_ID)
#define OPTPROC_NO_REQ_OPT     (1U << OPTPROC_NO_REQ_OPT_ID)
#define OPTPROC_NUM_OPT        (1U << OPTPROC_NUM_OPT_ID)
#define OPTPROC_INITDONE       (1U << OPTPROC_INITDONE_ID)
#define OPTPROC_NEGATIONS      (1U << OPTPROC_NEGATIONS_ID)
#define OPTPROC_ENVIRON        (1U << OPTPROC_ENVIRON_ID)
#define OPTPROC_NO_ARGS        (1U << OPTPROC_NO_ARGS_ID)
#define OPTPROC_ARGS_REQ       (1U << OPTPROC_ARGS_REQ_ID)
#define OPTPROC_REORDER        (1U << OPTPROC_REORDER_ID)
#define OPTPROC_GNUUSAGE       (1U << OPTPROC_GNUUSAGE_ID)
#define OPTPROC_TRANSLATE      (1U << OPTPROC_TRANSLATE_ID)
#define OPTPROC_MISUSE         (1U << OPTPROC_MISUSE_ID)
#define OPTPROC_IMMEDIATE      (1U << OPTPROC_IMMEDIATE_ID)
#define OPTPROC_NXLAT_OPT_CFG  (1U << OPTPROC_NXLAT_OPT_CFG_ID)
#define OPTPROC_NXLAT_OPT      (1U << OPTPROC_NXLAT_OPT_ID)
#define OPTPROC_VENDOR_OPT     (1U << OPTPROC_VENDOR_OPT_ID)
#define OPTPROC_PRESETTING     (1U << OPTPROC_PRESETTING_ID)
#define OPTPROC_STATE_MASK     0x000FFFFFU

#define OPTPROC_NO_XLAT_MASK   ( \
        OPTPROC_NXLAT_OPT |     OPTPROC_NXLAT_OPT_CFG \
        /* 0x00030000U */ )

#define STMTS(s)  do { s; } while (0)

/*
 *  The following must be #defined instead of typedef-ed
 *  because "static const" cannot both be applied to a type,
 *  tho each individually can...so they all are
 */
#define tSCC        static char const
#define tCC         char const
#define tAoSC       static char
#define tAoUC       unsigned char
#define tAoUI       unsigned int
#define tAoUL       unsigned long
#define tAoUS       unsigned short

/*
 *  It is so disgusting that there must be so many ways
 *  of specifying TRUE and FALSE.
 */
typedef enum { AG_FALSE = 0, AG_TRUE } ag_bool;

/*
 *  Define a structure that describes each option and
 *  a pointer to the procedure that handles it.
 *  The argument is the count of this flag previously seen.
 */
typedef struct options  tOptions;
typedef struct optDesc  tOptDesc;
typedef struct optNames tOptNames;
#define OPTPROC_EMIT_USAGE      ((tOptions *)0x01UL)
#define OPTPROC_EMIT_SHELL      ((tOptions *)0x02UL)
#define OPTPROC_RETURN_VALNAME  ((tOptions *)0x03UL)
#define OPTPROC_EMIT_LIMIT      ((tOptions *)0x0FUL)

/*
 *  The option procedures do the special processing for each
 *  option flag that needs it.
 */
typedef void (tOptProc)(tOptions*  pOpts, tOptDesc* pOptDesc);
typedef tOptProc*  tpOptProc;

/*
 *  The usage procedure will never return.  It calls "exit(2)"
 *  with the "exitCode" argument passed to it.
 */
// coverity[+kill]
typedef void (tUsageProc)(tOptions* pOpts, int exitCode);
typedef tUsageProc * tpUsageProc;

/*
 *  Special definitions.  "NOLIMIT" is the 'max' value to use when
 *  a flag may appear multiple times without limit.  "NO_EQUIVALENT"
 *  is an illegal value for 'optIndex' (option description index).
 */
#define NOLIMIT          USHRT_MAX
#define OPTION_LIMIT     SHRT_MAX
#define NO_EQUIVALENT    (OPTION_LIMIT+1)

typedef union {
    char const *    argString;
    uintptr_t       argEnum;
    uintptr_t       argIntptr;
    long            argInt;
    unsigned long   argUint;
    unsigned int    argBool;
    FILE *          argFp;
    int             argFd;
} optArgBucket_t;

#define             pzLastArg   optArg.argString

/*
 *  Descriptor structure for each option.
 *  Only the fields marked "PUBLIC" are for public use.
 */
struct optDesc {
    tAoUS const     optIndex;         /* PUBLIC */
    tAoUS const     optValue;         /* PUBLIC */
    tAoUS           optActualIndex;   /* PUBLIC */
    tAoUS           optActualValue;   /* PUBLIC */

    tAoUS const     optEquivIndex;    /* PUBLIC */
    tAoUS const     optMinCt;
    tAoUS const     optMaxCt;
    tAoUS           optOccCt;         /* PUBLIC */

    tAoUI           fOptState;        /* PUBLIC */
    tAoUI           reserved;
    optArgBucket_t  optArg;           /* PUBLIC */
    void*           optCookie;        /* PUBLIC */

    int const * const   pOptMust;
    int const * const   pOptCant;
    tpOptProc   const   pOptProc;
    char const* const   pzText;

    char const* const   pz_NAME;
    char const* const   pz_Name;
    char const* const   pz_DisableName;
    char const* const   pz_DisablePfx;
};

/*
 *  Some options need special processing, so we store their
 *  indexes in a known place:
 */
typedef struct optSpecIndex tOptSpecIndex;
struct optSpecIndex {
    const tAoUS         more_help;
    const tAoUS         save_opts;
    const tAoUS         number_option;
    const tAoUS         default_opt;
};

/*
 *  The procedure generated for translating option text
 */
typedef void (tOptionXlateProc)(void);

/*
 * Everything marked "PUBLIC" is also marked "const".  Public access is not
 * a license to modify.  Other fields are used and modified by the library.
 * They are also subject to change without any notice.
 * Do not even look at these outside of libopts.
 */
struct options {
    int const           structVersion;
    unsigned int        origArgCt;
    char**              origArgVect;
    unsigned int        fOptSet;
    unsigned int        curOptIdx;
    char*               pzCurOpt;

    char const* const   pzProgPath;         /* PUBLIC */
    char const* const   pzProgName;         /* PUBLIC */
    char const* const   pzPROGNAME;         /* PUBLIC */
    char const* const   pzRcName;           /* PUBLIC */
    char const* const   pzCopyright;        /* PUBLIC */
    char const* const   pzCopyNotice;       /* PUBLIC */
    char const* const   pzFullVersion;      /* PUBLIC */
    char const* const* const papzHomeList;
    char const* const   pzUsageTitle;
    char const* const   pzExplain;
    char const* const   pzDetail;
    tOptDesc*   const   pOptDesc;           /* PUBLIC */
    char const* const   pzBugAddr;          /* PUBLIC */

    void*               pExtensions;
    void*               pSavedState;

    // coverity[+kill]
    tpUsageProc         pUsageProc;
    tOptionXlateProc*   pTransProc;

    tOptSpecIndex       specOptIdx;
    int const           optCt;
    int const           presetOptCt;
    char const *        pzFullUsage;
    char const *        pzShortUsage;
    /* PUBLIC: */
    optArgBucket_t const * const originalOptArgArray;
    void * const * const originalOptArgCookie;
    char const * const  pzPkgDataDir;
    char const * const  pzPackager;
};

/*
 *  Versions where in various fields first appear:
 *  ($AO_CURRENT * 4096 + $AO_REVISION, but $AO_REVISION must be zero)
 */
#define originalOptArgArray_STRUCT_VERSION  131072 /* AO_CURRENT = 32 */
#define HAS_originalOptArgArray(_opt) \
    ((_opt)->structVersion >= originalOptArgArray_STRUCT_VERSION)

#define pzPkgDataDir_STRUCT_VERSION  139264 /* AO_CURRENT = 34 */
#define HAS_pzPkgDataDir(_opt) \
    ((_opt)->structVersion >= pzPkgDataDir_STRUCT_VERSION)

/*
 *  "token list" structure returned by "string_tokenize()"
 */
typedef struct {
    unsigned long   tkn_ct;
    unsigned char*  tkn_list[1];
} token_list_t;

/*
 *  Hide the interface - it pollutes a POSIX claim, but leave it for
 *  anyone #include-ing this header
 */
#define strneqvcmp      option_strneqvcmp
#define streqvcmp       option_streqvcmp
#define streqvmap       option_streqvmap
#define strequate       option_strequate
#define strtransform    option_strtransform

/**
 *  Everything needed to be known about an mmap-ed file.
 *
 *  This is an output only structure used by text_mmap and text_munmap.
 *  Clients must not alter the contents and must provide it to both
 *  the text_mmap and text_munmap procedures.  BE ADVISED: if you are
 *  mapping the file with PROT_WRITE the NUL byte at the end MIGHT NOT
 *  BE WRITABLE.  In any event, that byte is not be written back
 *  to the source file.  ALSO: if "txt_data" is valid and "txt_errno"
 *  is not zero, then there *may* not be a terminating NUL.
 */
typedef struct {
    void *      txt_data;      /*@< text file data   */
    size_t      txt_size;      /*@< actual file size */
    size_t      txt_full_size; /*@< mmaped mem size  */
    int         txt_fd;        /*@< file descriptor  */
    int         txt_zero_fd;   /*@< fd for /dev/zero */
    int         txt_errno;     /*@< warning code     */
    int         txt_prot;      /*@< "prot" flags     */
    int         txt_flags;     /*@< mapping type     */
} tmap_info_t;

#define TEXT_MMAP_FAILED_ADDR(a)  ((void*)(a) ==  (void*)MAP_FAILED)

#ifdef  __cplusplus
#define CPLUSPLUS_OPENER extern "C" {
CPLUSPLUS_OPENER
#define CPLUSPLUS_CLOSER }
#else
#define CPLUSPLUS_CLOSER
#endif

/*
 *  The following routines may be coded into AutoOpts client code:
 */

/* From: tokenize.c line 166
 *
 * ao_string_tokenize - tokenize an input string
 *
 * Arguments:
 *   string       string to be tokenized
 *
 * Returns: token_list_t* - pointer to a structure that lists each token
 *
 *  This function will convert one input string into a list of strings.
 *  The list of strings is derived by separating the input based on
 *  white space separation.  However, if the input contains either single
 *  or double quote characters, then the text after that character up to
 *  a matching quote will become the string in the list.
 *  
 *  The returned pointer should be deallocated with @code{free(3C)} when
 *  are done using the data.  The data are placed in a single block of
 *  allocated memory.  Do not deallocate individual token/strings.
 *  
 *  The structure pointed to will contain at least these two fields:
 *  @table @samp
 *  @item tkn_ct
 *  The number of tokens found in the input string.
 *  @item tok_list
 *  An array of @code{tkn_ct + 1} pointers to substring tokens, with
 *  the last pointer set to NULL.
 *  @end table
 *  
 *  There are two types of quoted strings: single quoted (@code{'}) and
 *  double quoted (@code{"}).  Singly quoted strings are fairly raw in that
 *  escape characters (@code{\\}) are simply another character, except when
 *  preceding the following characters:
 *  @example
 *  @code{\\}  double backslashes reduce to one
 *  @code{'}   incorporates the single quote into the string
 *  @code{\n}  suppresses both the backslash and newline character
 *  @end example
 *  
 *  Double quote strings are formed according to the rules of string
 *  constants in ANSI-C programs.
 */
extern token_list_t* ao_string_tokenize(char const*);


/* From: configfile.c line 77
 *
 * configFileLoad - parse a configuration file
 *
 * Arguments:
 *   pzFile       the file to load
 *
 * Returns: const tOptionValue* - An allocated, compound value structure
 *
 *  This routine will load a named configuration file and parse the
 *  text as a hierarchically valued option.  The option descriptor
 *  created from an option definition file is not used via this interface.
 *  The returned value is "named" with the input file name and is of
 *  type "@code{OPARG_TYPE_HIERARCHY}".  It may be used in calls to
 *  @code{optionGetValue()}, @code{optionNextValue()} and
 *  @code{optionUnloadNested()}.
 */
extern const tOptionValue* configFileLoad(char const*);


/* From: configfile.c line 1059
 *
 * optionFileLoad - Load the locatable config files, in order
 *
 * Arguments:
 *   pOpts        program options descriptor
 *   pzProg       program name
 *
 * Returns: int - 0 -> SUCCESS, -1 -> FAILURE
 *
 *  This function looks in all the specified directories for a configuration
 *  file ("rc" file or "ini" file) and processes any found twice.  The first
 *  time through, they are processed in reverse order (last file first).  At
 *  that time, only "immediate action" configurables are processed.  For
 *  example, if the last named file specifies not processing any more
 *  configuration files, then no more configuration files will be processed.
 *  Such an option in the @strong{first} named directory will have no effect.
 *  
 *  Once the immediate action configurables have been handled, then the
 *  directories are handled in normal, forward order.  In that way, later
 *  config files can override the settings of earlier config files.
 *  
 *  See the AutoOpts documentation for a thorough discussion of the
 *  config file format.
 *  
 *  Configuration files not found or not decipherable are simply ignored.
 */
extern int optionFileLoad(tOptions*, char const*);


/* From: configfile.c line 211
 *
 * optionFindNextValue - find a hierarcicaly valued option instance
 *
 * Arguments:
 *   pOptDesc     an option with a nested arg type
 *   pPrevVal     the last entry
 *   name         name of value to find
 *   value        the matching value
 *
 * Returns: const tOptionValue* - a compound value structure
 *
 *  This routine will find the next entry in a nested value option or
 *  configurable.  It will search through the list and return the next entry
 *  that matches the criteria.
 */
extern const tOptionValue* optionFindNextValue(const tOptDesc*, const tOptionValue*, char const*, char const*);


/* From: configfile.c line 137
 *
 * optionFindValue - find a hierarcicaly valued option instance
 *
 * Arguments:
 *   pOptDesc     an option with a nested arg type
 *   name         name of value to find
 *   value        the matching value
 *
 * Returns: const tOptionValue* - a compound value structure
 *
 *  This routine will find an entry in a nested value option or configurable.
 *  It will search through the list and return a matching entry.
 */
extern const tOptionValue* optionFindValue(const tOptDesc*, char const*, char const*);


/* From: restore.c line 166
 *
 * optionFree - free allocated option processing memory
 *
 * Arguments:
 *   pOpts        program options descriptor
 *
 *  AutoOpts sometimes allocates memory and puts pointers to it in the
 *  option state structures.  This routine deallocates all such memory.
 */
extern void optionFree(tOptions*);


/* From: configfile.c line 280
 *
 * optionGetValue - get a specific value from a hierarcical list
 *
 * Arguments:
 *   pOptValue    a hierarchcal value
 *   valueName    name of value to get
 *
 * Returns: const tOptionValue* - a compound value structure
 *
 *  This routine will find an entry in a nested value option or configurable.
 *  If "valueName" is NULL, then the first entry is returned.  Otherwise,
 *  the first entry with a name that exactly matches the argument will be
 *  returned.  If there is no matching value, NULL is returned and errno is
 *  set to ENOENT. If the provided option value is not a hierarchical value,
 *  NULL is also returned and errno is set to EINVAL.
 */
extern const tOptionValue* optionGetValue(const tOptionValue*, char const*);


/* From: load.c line 476
 *
 * optionLoadLine - process a string for an option name and value
 *
 * Arguments:
 *   pOpts        program options descriptor
 *   pzLine       NUL-terminated text
 *
 *  This is a client program callable routine for setting options from, for
 *  example, the contents of a file that they read in.  Only one option may
 *  appear in the text.  It will be treated as a normal (non-preset) option.
 *  
 *  When passed a pointer to the option struct and a string, it will find
 *  the option named by the first token on the string and set the option
 *  argument to the remainder of the string.  The caller must NUL terminate
 *  the string.  Any embedded new lines will be included in the option
 *  argument.  If the input looks like one or more quoted strings, then the
 *  input will be "cooked".  The "cooking" is identical to the string
 *  formation used in AutoGen definition files (@pxref{basic expression}),
 *  except that you may not use backquotes.
 */
extern void optionLoadLine(tOptions*, char const*);


/* From: configfile.c line 340
 *
 * optionNextValue - get the next value from a hierarchical list
 *
 * Arguments:
 *   pOptValue    a hierarchcal list value
 *   pOldValue    a value from this list
 *
 * Returns: const tOptionValue* - a compound value structure
 *
 *  This routine will return the next entry after the entry passed in.  At the
 *  end of the list, NULL will be returned.  If the entry is not found on the
 *  list, NULL will be returned and "@var{errno}" will be set to EINVAL.
 *  The "@var{pOldValue}" must have been gotten from a prior call to this
 *  routine or to "@code{opitonGetValue()}".
 */
extern const tOptionValue* optionNextValue(const tOptionValue*, const tOptionValue*);


/* From: usage.c line 202
 *
 * optionOnlyUsage - Print usage text for just the options
 *
 * Arguments:
 *   pOpts        program options descriptor
 *   ex_code      exit code for calling exit(3)
 *
 *  This routine will print only the usage for each option.
 *  This function may be used when the emitted usage must incorporate
 *  information not available to AutoOpts.
 */
extern void optionOnlyUsage(tOptions*, int);


/* From: autoopts.c line 598
 *
 * optionProcess - this is the main option processing routine
 *
 * Arguments:
 *   pOpts        program options descriptor
 *   argc         program arg count
 *   argv         program arg vector
 *
 * Returns: int - the count of the arguments processed
 *
 *  This is the main entry point for processing options.  It is intended
 *  that this procedure be called once at the beginning of the execution of
 *  a program.  Depending on options selected earlier, it is sometimes
 *  necessary to stop and restart option processing, or to select completely
 *  different sets of options.  This can be done easily, but you generally
 *  do not want to do this.
 *  
 *  The number of arguments processed always includes the program name.
 *  If one of the arguments is "--", then it is counted and the processing
 *  stops.  If an error was encountered and errors are to be tolerated, then
 *  the returned value is the index of the argument causing the error.
 *  A hyphen by itself ("-") will also cause processing to stop and will
 *  @emph{not} be counted among the processed arguments.  A hyphen by itself
 *  is treated as an operand.  Encountering an operand stops option
 *  processing.
 */
extern int optionProcess(tOptions*, int, char**);


/* From: restore.c line 123
 *
 * optionRestore - restore option state from memory copy
 *
 * Arguments:
 *   pOpts        program options descriptor
 *
 *  Copy back the option state from saved memory.
 *  The allocated memory is left intact, so this routine can be
 *  called repeatedly without having to call optionSaveState again.
 *  If you are restoring a state that was saved before the first call
 *  to optionProcess(3AO), then you may change the contents of the
 *  argc/argv parameters to optionProcess.
 */
extern void optionRestore(tOptions*);


/* From: save.c line 648
 *
 * optionSaveFile - saves the option state to a file
 *
 * Arguments:
 *   pOpts        program options descriptor
 *
 *  This routine will save the state of option processing to a file.  The name
 *  of that file can be specified with the argument to the @code{--save-opts}
 *  option, or by appending the @code{rcfile} attribute to the last
 *  @code{homerc} attribute.  If no @code{rcfile} attribute was specified, it
 *  will default to @code{.@i{programname}rc}.  If you wish to specify another
 *  file, you should invoke the @code{SET_OPT_SAVE_OPTS(@i{filename})} macro.
 *  
 *  The recommend usage is as follows:
 *  @example
 *  optionProcess(&progOptions, argc, argv);
 *  if (i_want_a_non_standard_place_for_this)
 *  SET_OPT_SAVE_OPTS("myfilename");
 *  optionSaveFile(&progOptions);
 *  @end example
 */
extern void optionSaveFile(tOptions*);


/* From: restore.c line 71
 *
 * optionSaveState - saves the option state to memory
 *
 * Arguments:
 *   pOpts        program options descriptor
 *
 *  This routine will allocate enough memory to save the current option
 *  processing state.  If this routine has been called before, that memory
 *  will be reused.  You may only save one copy of the option state.  This
 *  routine may be called before optionProcess(3AO).  If you do call it
 *  before the first call to optionProcess, then you may also change the
 *  contents of argc/argv after you call optionRestore(3AO)
 *  
 *  In fact, more strongly put: it is safest to only use this function
 *  before having processed any options.  In particular, the saving and
 *  restoring of stacked string arguments and hierarchical values is
 *  disabled.  The values are not saved.
 */
extern void optionSaveState(tOptions*);


/* From: nested.c line 562
 *
 * optionUnloadNested - Deallocate the memory for a nested value
 *
 * Arguments:
 *   pOptVal      the hierarchical value
 *
 *  A nested value needs to be deallocated.  The pointer passed in should
 *  have been gotten from a call to @code{configFileLoad()} (See
 *  @pxref{libopts-configFileLoad}).
 */
extern void optionUnloadNested(tOptionValue const *);


/* From: version.c line 31
 *
 * optionVersion - return the compiled AutoOpts version number
 *
 * Returns: char const* - the version string in constant memory
 *
 *  Returns the full version string compiled into the library.
 *  The returned string cannot be modified.
 */
extern char const* optionVersion(void);


/* From: ../compat/pathfind.c line 29
 *
 * pathfind - fild a file in a list of directories
 *
 * Arguments:
 *   path         colon separated list of search directories
 *   file         the name of the file to look for
 *   mode         the mode bits that must be set to match
 *
 * Returns: char* - the path to the located file
 *
 * the pathfind function is available only if HAVE_PATHFIND is not defined
 *
 *  pathfind looks for a a file with name "FILE" and "MODE" access
 *  along colon delimited "PATH", and returns the full pathname as a
 *  string, or NULL if not found.  If "FILE" contains a slash, then
 *  it is treated as a relative or absolute path and "PATH" is ignored.
 *  
 *  @strong{NOTE}: this function is compiled into @file{libopts} only if
 *  it is not natively supplied.
 *  
 *  The "MODE" argument is a string of option letters chosen from the
 *  list below:
 *  @example
 *  Letter    Meaning
 *  r         readable
 *  w         writable
 *  x         executable
 *  f         normal file       (NOT IMPLEMENTED)
 *  b         block special     (NOT IMPLEMENTED)
 *  c         character special (NOT IMPLEMENTED)
 *  d         directory         (NOT IMPLEMENTED)
 *  p         FIFO (pipe)       (NOT IMPLEMENTED)
 *  u         set user ID bit   (NOT IMPLEMENTED)
 *  g         set group ID bit  (NOT IMPLEMENTED)
 *  k         sticky bit        (NOT IMPLEMENTED)
 *  s         size nonzero      (NOT IMPLEMENTED)
 *  @end example
 */
#ifndef HAVE_PATHFIND
extern char* pathfind(char const*, char const*, char const*);
#endif /* HAVE_PATHFIND */


/* From: streqvcmp.c line 209
 *
 * strequate - map a list of characters to the same value
 *
 * Arguments:
 *   ch_list      characters to equivalence
 *
 *  Each character in the input string get mapped to the first character
 *  in the string.
 *  This function name is mapped to option_strequate so as to not conflict
 *  with the POSIX name space.
 */
extern void strequate(char const*);


/* From: streqvcmp.c line 119
 *
 * streqvcmp - compare two strings with an equivalence mapping
 *
 * Arguments:
 *   str1         first string
 *   str2         second string
 *
 * Returns: int - the difference between two differing characters
 *
 *  Using a character mapping, two strings are compared for "equivalence".
 *  Each input character is mapped to a comparison character and the
 *  mapped-to characters are compared for the two NUL terminated input strings.
 *  This function name is mapped to option_streqvcmp so as to not conflict
 *  with the POSIX name space.
 */
extern int streqvcmp(char const*, char const*);


/* From: streqvcmp.c line 156
 *
 * streqvmap - Set the character mappings for the streqv functions
 *
 * Arguments:
 *   From         Input character
 *   To           Mapped-to character
 *   ct           compare length
 *
 *  Set the character mapping.  If the count (@code{ct}) is set to zero, then
 *  the map is cleared by setting all entries in the map to their index
 *  value.  Otherwise, the "@code{From}" character is mapped to the "@code{To}"
 *  character.  If @code{ct} is greater than 1, then @code{From} and @code{To}
 *  are incremented and the process repeated until @code{ct} entries have been
 *  set. For example,
 *  @example
 *  streqvmap('a', 'A', 26);
 *  @end example
 *  @noindent
 *  will alter the mapping so that all English lower case letters
 *  will map to upper case.
 *  
 *  This function name is mapped to option_streqvmap so as to not conflict
 *  with the POSIX name space.
 */
extern void streqvmap(char, char, int);


/* From: streqvcmp.c line 78
 *
 * strneqvcmp - compare two strings with an equivalence mapping
 *
 * Arguments:
 *   str1         first string
 *   str2         second string
 *   ct           compare length
 *
 * Returns: int - the difference between two differing characters
 *
 *  Using a character mapping, two strings are compared for "equivalence".
 *  Each input character is mapped to a comparison character and the
 *  mapped-to characters are compared for the two NUL terminated input strings.
 *  The comparison is limited to @code{ct} bytes.
 *  This function name is mapped to option_strneqvcmp so as to not conflict
 *  with the POSIX name space.
 */
extern int strneqvcmp(char const*, char const*, int);


/* From: streqvcmp.c line 235
 *
 * strtransform - convert a string into its mapped-to value
 *
 * Arguments:
 *   dest         output string
 *   src          input string
 *
 *  Each character in the input string is mapped and the mapped-to
 *  character is put into the output.
 *  This function name is mapped to option_strtransform so as to not conflict
 *  with the POSIX name space.
 *  
 *  The source and destination may be the same.
 */
extern void strtransform(char*, char const*);

/*  AutoOpts PRIVATE FUNCTIONS:  */
tOptProc optionStackArg, optionUnstackArg, optionBooleanVal, optionNumericVal;

extern char* ao_string_cook(char*, int*);

extern unsigned int ao_string_cook_escape_char(char const*, char*, unsigned int);

extern void genshelloptUsage(tOptions*, int);

extern int optionAlias(tOptions*, tOptDesc*, unsigned int);

extern void optionBooleanVal(tOptions*, tOptDesc*);

extern uintptr_t optionEnumerationVal(tOptions*, tOptDesc*, char const * const *, unsigned int);

extern void optionFileCheck(tOptions*, tOptDesc*, teOptFileType, tuFileMode);

extern char const * optionKeywordName(tOptDesc*, unsigned int);

extern void optionLoadOpt(tOptions*, tOptDesc*);

extern ag_bool optionMakePath(char*, int, char const*, char const*);

extern void optionNestedVal(tOptions*, tOptDesc*);

extern void optionNumericVal(tOptions*, tOptDesc*);

extern void optionPagedUsage(tOptions*, tOptDesc*);

extern void optionParseShell(tOptions*);

extern void optionPrintVersion(tOptions*, tOptDesc*);

extern void optionPutShell(tOptions*);

extern void optionResetOpt(tOptions*, tOptDesc*);

extern void optionSetMembers(tOptions*, tOptDesc*, char const * const *, unsigned int);

extern void optionShowRange(tOptions*, tOptDesc*, void *, int);

extern void optionStackArg(tOptions*, tOptDesc*);

extern void optionTimeDate(tOptions*, tOptDesc*);

extern void optionTimeVal(tOptions*, tOptDesc*);

extern void optionUnstackArg(tOptions*, tOptDesc*);

extern void optionUsage(tOptions*, int);

extern void optionVendorOption(tOptions *, tOptDesc *);

extern void optionVersionStderr(tOptions*, tOptDesc*);

extern void* text_mmap(char const*, int, int, tmap_info_t*);

extern int text_munmap(tmap_info_t*);

CPLUSPLUS_CLOSER
#endif /* AUTOOPTS_OPTIONS_H_GUARD */
/*
 * Local Variables:
 * c-file-style: "stroustrup"
 * indent-tabs-mode: nil
 * End:
 * options.h ends here */
