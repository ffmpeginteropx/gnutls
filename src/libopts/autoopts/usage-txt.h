/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (usage-txt.h)
 *  
 *  It has been AutoGen-ed  February 25, 2012 at 01:14:43 PM by AutoGen 5.15pre14
 *  From the definitions    usage-txt.def
 *  and the template file   usage-txt.tpl
 *
 *  This file handles all the bookkeeping required for tracking all the little
 *  tiny strings used by the AutoOpts library.  There are 144
 *  of them.  This is not versioned because it is entirely internal to the
 *  library and accessed by client code only in a very well-controlled way:
 *  they may substitute translated strings using a procedure that steps through
 *  all the string pointers.
 *
 *  Copyright (C) 1992-2012 Bruce Korb, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the
 *  GNU Lesser General Public License, version 3 or later
 *     <http://gnu.org/licenses/lgpl.html>
 *
 *  AutoOpts is free software: you can redistribute it and/or modify it
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
#ifndef AUTOOPTS_USAGE_TXT_H_GUARD
#define AUTOOPTS_USAGE_TXT_H_GUARD 1

#undef  cch_t
#define cch_t char const

/*
 *  One structure to hold all the pointers to all the stringlets.
 */
typedef struct {
  int       field_ct;
  char*     utpz_GnuBoolArg;
  char*     utpz_GnuKeyArg;
  char*     utpz_GnuFileArg;
  char*     utpz_GnuKeyLArg;
  char*     utpz_GnuTimeArg;
  char*     utpz_GnuNumArg;
  char*     utpz_GnuStrArg;
  cch_t*    apz_str[ 137 ];
} usage_text_t;

/*
 *  Declare the global structure with all the pointers to translated
 *  strings.  This is then used by the usage generation procedure.
 */
extern usage_text_t option_usage_text;

#if defined(AUTOOPTS_INTERNAL) /* DEFINE ALL THE STRINGS = = = = = */
/*
 *  Provide a mapping from a short name to fields in this structure.
 */
#define zAO_Alloc             (option_usage_text.apz_str[  0])
#define zAO_Bad               (option_usage_text.apz_str[  1])
#define zAO_Big               (option_usage_text.apz_str[  2])
#define zAO_Err               (option_usage_text.apz_str[  3])
#define zAO_Realloc           (option_usage_text.apz_str[  4])
#define zAO_Sml               (option_usage_text.apz_str[  5])
#define zAO_Strdup            (option_usage_text.apz_str[  6])
#define zAO_Ver               (option_usage_text.apz_str[  7])
#define zAO_Woops             (option_usage_text.apz_str[  8])
#define zAliasRange           (option_usage_text.apz_str[  9])
#define zAll                  (option_usage_text.apz_str[ 10])
#define zAlt                  (option_usage_text.apz_str[ 11])
#define zAmbigKey             (option_usage_text.apz_str[ 12])
#define zAmbigList            (option_usage_text.apz_str[ 13])
#define zAmbigOptStr          (option_usage_text.apz_str[ 14])
#define zAmbiguous            (option_usage_text.apz_str[ 15])
#define zArgsMust             (option_usage_text.apz_str[ 16])
#define zAtMost               (option_usage_text.apz_str[ 17])
#define zAuto                 (option_usage_text.apz_str[ 18])
#define zBadPipe              (option_usage_text.apz_str[ 19])
#define zBadVerArg            (option_usage_text.apz_str[ 20])
#define zCantFmt              (option_usage_text.apz_str[ 21])
#define zCantSave             (option_usage_text.apz_str[ 22])
#define zCfgAO_Flags          (option_usage_text.apz_str[ 23])
#define zCfgProg              (option_usage_text.apz_str[ 24])
#define zDefaultOpt           (option_usage_text.apz_str[ 25])
#define zDis                  (option_usage_text.apz_str[ 26])
#define zDisabledErr          (option_usage_text.apz_str[ 27])
#define zDisabledOpt          (option_usage_text.apz_str[ 28])
#define zDisabledWhy          (option_usage_text.apz_str[ 29])
#define zEnab                 (option_usage_text.apz_str[ 30])
#define zEquiv                (option_usage_text.apz_str[ 31])
#define zErrOnly              (option_usage_text.apz_str[ 32])
#define zExamineFmt           (option_usage_text.apz_str[ 33])
#define zFiveSpaces           (option_usage_text.apz_str[ 34])
#define zFlagOkay             (option_usage_text.apz_str[ 35])
#define zFmtFmt               (option_usage_text.apz_str[ 36])
#define zForkFail             (option_usage_text.apz_str[ 37])
#define zFreopenFail          (option_usage_text.apz_str[ 38])
#define zFSErrOptLoad         (option_usage_text.apz_str[ 39])
#define zFSErrReadFile        (option_usage_text.apz_str[ 40])
#define zFSOptError           (option_usage_text.apz_str[ 41])
#define zFSOptErrMayExist     (option_usage_text.apz_str[ 42])
#define zFSOptErrMustExist    (option_usage_text.apz_str[ 43])
#define zFSOptErrNoExist      (option_usage_text.apz_str[ 44])
#define zFSOptErrOpen         (option_usage_text.apz_str[ 45])
#define zFSOptErrFopen        (option_usage_text.apz_str[ 46])
#define zFileCannotExist      (option_usage_text.apz_str[ 47])
#define zFileMustExist        (option_usage_text.apz_str[ 48])
#define zGenshell             (option_usage_text.apz_str[ 49])
#define zGnuBoolArg           (option_usage_text.utpz_GnuBoolArg)
#define zGnuBreak             (option_usage_text.apz_str[ 50])
#define zGnuKeyArg            (option_usage_text.utpz_GnuKeyArg)
#define zGnuFileArg           (option_usage_text.utpz_GnuFileArg)
#define zGnuKeyLArg           (option_usage_text.utpz_GnuKeyLArg)
#define zGnuTimeArg           (option_usage_text.utpz_GnuTimeArg)
#define zGnuNestArg           (option_usage_text.apz_str[ 51])
#define zGnuNumArg            (option_usage_text.utpz_GnuNumArg)
#define zGnuOptArg            (option_usage_text.apz_str[ 52])
#define zGnuOptFmt            (option_usage_text.apz_str[ 53])
#define zGnuStrArg            (option_usage_text.utpz_GnuStrArg)
#define zIllOptChr            (option_usage_text.apz_str[ 54])
#define zIllOptStr            (option_usage_text.apz_str[ 55])
#define zIllVendOptStr        (option_usage_text.apz_str[ 56])
#define zIntRange             (option_usage_text.apz_str[ 57])
#define zInvalOptDesc         (option_usage_text.apz_str[ 58])
#define zLowerBits            (option_usage_text.apz_str[ 59])
#define zMembers              (option_usage_text.apz_str[ 60])
#define zMisArg               (option_usage_text.apz_str[ 61])
#define zMultiEquiv           (option_usage_text.apz_str[ 62])
#define zMust                 (option_usage_text.apz_str[ 63])
#define zNeedOne              (option_usage_text.apz_str[ 64])
#define zNoArg                (option_usage_text.apz_str[ 65])
#define zNoArgs               (option_usage_text.apz_str[ 66])
#define zNoCreat              (option_usage_text.apz_str[ 67])
#define zNoFlags              (option_usage_text.apz_str[ 68])
#define zNoKey                (option_usage_text.apz_str[ 69])
#define zNoLim                (option_usage_text.apz_str[ 70])
#define zNoPreset             (option_usage_text.apz_str[ 71])
#define zNoResetArg           (option_usage_text.apz_str[ 72])
#define zNoRq_NoShrtTtl       (option_usage_text.apz_str[ 73])
#define zNoRq_ShrtTtl         (option_usage_text.apz_str[ 74])
#define zNoStat               (option_usage_text.apz_str[ 75])
#define zNoState              (option_usage_text.apz_str[ 76])
#define zNone                 (option_usage_text.apz_str[ 77])
#define zNotDef               (option_usage_text.apz_str[ 78])
#define zNotCmdOpt            (option_usage_text.apz_str[ 79])
#define zNotEnough            (option_usage_text.apz_str[ 80])
#define zNotFile              (option_usage_text.apz_str[ 81])
#define zNotNumber            (option_usage_text.apz_str[ 82])
#define zNotDate              (option_usage_text.apz_str[ 83])
#define zNotDuration          (option_usage_text.apz_str[ 84])
#define zNrmOptFmt            (option_usage_text.apz_str[ 85])
#define zNumberOpt            (option_usage_text.apz_str[ 86])
#define zOnlyOne              (option_usage_text.apz_str[ 87])
#define zOptsOnly             (option_usage_text.apz_str[ 88])
#define zOutputFail           (option_usage_text.apz_str[ 89])
#define zPathFmt              (option_usage_text.apz_str[ 90])
#define zPlsSendBugs          (option_usage_text.apz_str[ 91])
#define zPreset               (option_usage_text.apz_str[ 92])
#define zPresetFile           (option_usage_text.apz_str[ 93])
#define zPresetIntro          (option_usage_text.apz_str[ 94])
#define zProhib               (option_usage_text.apz_str[ 95])
#define zReorder              (option_usage_text.apz_str[ 96])
#define zRange                (option_usage_text.apz_str[ 97])
#define zRangeAbove           (option_usage_text.apz_str[ 98])
#define zRangeLie             (option_usage_text.apz_str[ 99])
#define zRangeOnly            (option_usage_text.apz_str[100])
#define zRangeOr              (option_usage_text.apz_str[101])
#define zRangeErr             (option_usage_text.apz_str[102])
#define zRangeExact           (option_usage_text.apz_str[103])
#define zRangeScaled          (option_usage_text.apz_str[104])
#define zRangeUpto            (option_usage_text.apz_str[105])
#define zResetNotConfig       (option_usage_text.apz_str[106])
#define zReqFmt               (option_usage_text.apz_str[107])
#define zReqOptFmt            (option_usage_text.apz_str[108])
#define zReqThese             (option_usage_text.apz_str[109])
#define zReq_NoShrtTtl        (option_usage_text.apz_str[110])
#define zReq_ShrtTtl          (option_usage_text.apz_str[111])
#define zSepChars             (option_usage_text.apz_str[112])
#define zSetMemberSettings    (option_usage_text.apz_str[113])
#define zShrtGnuOptFmt        (option_usage_text.apz_str[114])
#define zSixSpaces            (option_usage_text.apz_str[115])
#define zStdBoolArg           (option_usage_text.apz_str[116])
#define zStdBreak             (option_usage_text.apz_str[117])
#define zStdFileArg           (option_usage_text.apz_str[118])
#define zStdKeyArg            (option_usage_text.apz_str[119])
#define zStdKeyLArg           (option_usage_text.apz_str[120])
#define zStdTimeArg           (option_usage_text.apz_str[121])
#define zStdNestArg           (option_usage_text.apz_str[122])
#define zStdNoArg             (option_usage_text.apz_str[123])
#define zStdNumArg            (option_usage_text.apz_str[124])
#define zStdOptArg            (option_usage_text.apz_str[125])
#define zStdReqArg            (option_usage_text.apz_str[126])
#define zStdStrArg            (option_usage_text.apz_str[127])
#define zTabHyp               (option_usage_text.apz_str[128])
#define zTabHypAnd            (option_usage_text.apz_str[129])
#define zTabout               (option_usage_text.apz_str[130])
#define zThreeSpaces          (option_usage_text.apz_str[131])
#define zTwoSpaces            (option_usage_text.apz_str[132])
#define zUpTo                 (option_usage_text.apz_str[133])
#define zValidKeys            (option_usage_text.apz_str[134])
#define zVendOptsAre          (option_usage_text.apz_str[135])
#define zVendIntro            (option_usage_text.apz_str[136])

  /*
   *  First, set up the strings.  Some of these are writable.  These are all in
   *  English.  This gets compiled into libopts and is distributed here so that
   *  xgettext (or equivalents) can extract these strings for translation.
   */

  static char    eng_zGnuBoolArg[] = "=T/F";
  static char    eng_zGnuKeyArg[] = "=KWd";
  static char    eng_zGnuFileArg[] = "=file";
  static char    eng_zGnuKeyLArg[] = "=Mbr";
  static char    eng_zGnuTimeArg[] = "=Tim";
  static char    eng_zGnuNumArg[] = "=num";
  static char    eng_zGnuStrArg[] = "=str";
static char const usage_txt[4575] =
/*     0 */ "malloc of %d bytes failed\n\0"
/*    27 */ "AutoOpts function called without option descriptor\n\0"
/*    79 */ "\tThis exceeds the compiled library version:  \0"
/*   125 */ "Automated Options Processing Error!\n"
            "\t%s called AutoOpts function with structure version %d:%d:%d.\n\0"
/*   224 */ "realloc of %d bytes at 0x%p failed\n\0"
/*   260 */ "\tThis is less than the minimum library version:  \0"
/*   310 */ "strdup of %d byte string failed\n\0"
/*   343 */ "Automated Options version %s\n"
            "\tcopyright (c) 1999-2012 by Bruce Korb - all rights reserved\n\0"
/*   434 */ "AutoOpts lib error: defaulted to option with optional arg\n\0"
/*   493 */ "(AutoOpts bug):  Aliasing option is out of range.\0"
/*   543 */ "all\0"
/*   547 */ "\t\t\t\t- an alternate for %s\n\0"
/*   574 */ "%s error:  the keyword `%s' is ambiguous for %s\n\0"
/*   623 */ "  The following options match:\n\0"
/*   655 */ "%s: ambiguous option name: %s (matches %d options)\n\0"
/*   707 */ "  %s%s\n\0"
/*   715 */ "%s: Command line arguments required\n\0"
/*   752 */ "%d %s%s options allowed\n\0"
/*   777 */ "version and help options:\0"
/*   803 */ "Error %d (%s) from the pipe(2) syscall\n\0"
/*   843 */ "ERROR: version option argument '%c' invalid.  Use:\n"
            "\t'v' - version only\n"
            "\t'c' - version and copyright\n"
            "\t'n' - version and copyright notice\n\0"
/*   980 */ "ERROR:  %s option conflicts with the %s option\n\0"
/*  1028 */ "%s(optionSaveState): error: cannot allocate %d bytes\n\0"
/*  1082 */ "auto-options\0"
/*  1095 */ "program\0"
/*  1103 */ "\t\t\t\t- default option for unnamed options\n\0"
/*  1145 */ "\t\t\t\t- disabled as --%s\n\0"
/*  1169 */ "%s: The ``%s'' option has been disabled\0"
/*  1209 */ " --- %-14s %s\n\0"
/*  1224 */ "This option has been disabled\0"
/*  1254 */ "\t\t\t\t- enabled by default\n\0"
/*  1280 */ "-equivalence\0"
/*  1293 */ "ERROR:  only \0"
/*  1307 */ " - examining environment variables named %s_*\n\0"
/*  1354 */ "     \0"
/*  1360 */ "Options are specified by doubled hyphens and their name or by a single\n"
            "hyphen and the flag character.\n\0"
/*  1463 */ "%%-%ds %%s\n\0"
/*  1475 */ "fs error %d (%s) on fork - cannot obtain %s usage\n\0"
/*  1526 */ "fs error %d (%s) on freopen\n\0"
/*  1555 */ "File error %d (%s) opening %s for loading options\n\0"
/*  1606 */ "fs error %d (%s) reading file %s\n\0"
/*  1640 */ "fs error %d (%s) on %s %s for option %s\n\0"
/*  1681 */ "stat-ing for directory\0"
/*  1704 */ "stat-ing for regular file\0"
/*  1730 */ "stat-ing for non-existant file\0"
/*  1761 */ "open-ing file\0"
/*  1775 */ "fopen-ing file\0"
/*  1790 */ "\t\t\t\t- file must not pre-exist\n\0"
/*  1821 */ "\t\t\t\t- file must pre-exist\n\0"
/*  1848 */ "\n"
            "= = = = = = = =\n\n"
            "This incarnation of genshell will produce\n"
            "a shell script to parse the options for %s:\n\n\0"
/*  1954 */ "\n"
            "%s\n\n\0"
/*  1960 */ "=Cplx\0"
/*  1966 */ "[=arg]\0"
/*  1973 */ "--%2$s%1$s\0"
/*  1984 */ "%s: illegal option -- %c\n\0"
/*  2010 */ "%s: illegal option -- %s\n\0"
/*  2036 */ "%s: unknown vendor extension option -- %s\n\0"
/*  2079 */ "  or an integer from %d through %d\n\0"
/*  2115 */ "AutoOpts ERROR:  invalid option descriptor for %s\n\0"
/*  2166 */ "  or an integer mask with any of the lower %d bits set\n\0"
/*  2222 */ "\t\t\t\t- is a set membership option\n\0"
/*  2256 */ "%s: option `%s' requires an argument\n\0"
/*  2294 */ "Equivalenced option '%s' was equivalenced to both\n"
            "\t'%s' and '%s'\0"
/*  2359 */ "\t\t\t\t- must appear between %d and %d times\n\0"
/*  2402 */ "ERROR:  The %s option is required\n\0"
/*  2437 */ "%s: option `%s' cannot have an argument\n\0"
/*  2478 */ "%s: Command line arguments not allowed\n\0"
/*  2518 */ "error %d (%s) creating %s\n\0"
/*  2545 */ "Options are specified by single or double hyphens and their name.\n\0"
/*  2612 */ "%s error:  `%s' does not match any %s keywords\n\0"
/*  2660 */ "\t\t\t\t- may appear multiple times\n\0"
/*  2693 */ "\t\t\t\t- may not be preset\n\0"
/*  2718 */ "The 'reset-option' option requires an argument\n\0"
/*  2766 */ "   Arg Option-Name    Description\n\0"
/*  2801 */ "  Flg Arg Option-Name    Description\n\0"
/*  2839 */ "error %d (%s) stat-ing %s\n\0"
/*  2866 */ "%s(optionRestore): error: no saved option state\n\0"
/*  2915 */ "none\0"
/*  2920 */ "'%s' not defined\n\0"
/*  2938 */ "'%s' is not a command line option\n\0"
/*  2973 */ "ERROR:  The %s option must appear %d times\n\0"
/*  3017 */ "error:  cannot load options from non-regular file %s\n\0"
/*  3071 */ "%s error:  `%s' is not a recognizable number\n\0"
/*  3117 */ "%s error:  `%s' is not a recognizable date/time\n\0"
/*  3166 */ "%s error:  `%s' is not a recognizable time duration\n\0"
/*  3219 */ " %3s %s\0"
/*  3227 */ "The '-#<number>' option may omit the hash char\n\0"
/*  3275 */ "one %s%s option allowed\n\0"
/*  3300 */ "All arguments are named options.\n\0"
/*  3334 */ "Write failure to output file\0"
/*  3363 */ " - reading file %s\0"
/*  3382 */ "\n"
            "please send bug reports to:  %s\n\0"
/*  3416 */ "\t\t\t\t- may NOT appear - preset only\n\0"
/*  3452 */ "#  preset/initialization file\n"
            "#  %s#\n\0"
/*  3490 */ "\n"
            "The following option preset mechanisms are supported:\n\0"
/*  3546 */ "prohibits these options:\n\0"
/*  3572 */ "Operands and options may be intermixed.  They will be reordered.\n\0"
/*  3638 */ "%s%ld to %ld\0"
/*  3651 */ "%sgreater than or equal to %ld\0"
/*  3682 */ "%sIt must lie in one of the ranges:\n\0"
/*  3719 */ "%sIt must be in the range:\n\0"
/*  3747 */ ", or\n\0"
/*  3753 */ "%s error:  %s option value %ld is out of range.\n\0"
/*  3802 */ "%s%ld exactly\0"
/*  3816 */ "%sis scalable with a suffix: k/K/m/M/g/G/t/T\n\0"
/*  3862 */ "%sless than or equal to %ld\0"
/*  3890 */ "The --reset-option has not been configured.\n\0"
/*  3935 */ "ERROR:  %s option requires the %s option\n\0"
/*  3977 */ " %3s %-14s %s\0"
/*  3991 */ "requires these options:\n\0"
/*  4016 */ "   Arg Option-Name   Req?  Description\n\0"
/*  4056 */ "  Flg Arg Option-Name   Req?  Description\n\0"
/*  4099 */ "-_^\0"
/*  4103 */ "or you may use a numeric representation.  Preceding these with a '!' will\n"
            "clear the bits, specifying 'none' will clear all bits, and 'all' will set them\n"
            "all.  Multiple entries may be passed as an option argument list.\n\0"
/*  4322 */ "%s\0"
/*  4325 */ "      \0"
/*  4332 */ "T/F\0"
/*  4336 */ "\n"
            "%s\n\n"
            "%s\0"
/*  4344 */ "Fil\0"
/*  4348 */ "KWd\0"
/*  4352 */ "Mbr\0"
/*  4356 */ "Tim\0"
/*  4360 */ "Cpx\0"
/*  4364 */ "no \0"
/*  4368 */ "Num\0"
/*  4372 */ "opt\0"
/*  4376 */ "YES\0"
/*  4380 */ "Str\0"
/*  4384 */ "\t\t\t\t- \0"
/*  4391 */ "\t\t\t\t-- and \0"
/*  4403 */ "\t\t\t\t%s\n\0"
/*  4411 */ "   \0"
/*  4415 */ "  \0"
/*  4418 */ "\t\t\t\t- may appear up to %d times\n\0"
/*  4451 */ "The valid \"%s\" option keywords are:\n\0"
/*  4488 */ "These additional options are:\0"
/*  4518 */ "The next option supports vendor supported extra options:";


  /*
   *  Now, define (and initialize) the structure that contains
   *  the pointers to all these strings.
   *  Aren't you glad you don't maintain this by hand?
   */
  usage_text_t option_usage_text = {
    144,
    eng_zGnuBoolArg, eng_zGnuKeyArg,  eng_zGnuFileArg, eng_zGnuKeyLArg,
    eng_zGnuTimeArg, eng_zGnuNumArg,  eng_zGnuStrArg,
    {
      usage_txt +   0, usage_txt +  27, usage_txt +  79, usage_txt + 125,
      usage_txt + 224, usage_txt + 260, usage_txt + 310, usage_txt + 343,
      usage_txt + 434, usage_txt + 493, usage_txt + 543, usage_txt + 547,
      usage_txt + 574, usage_txt + 623, usage_txt + 655, usage_txt + 707,
      usage_txt + 715, usage_txt + 752, usage_txt + 777, usage_txt + 803,
      usage_txt + 843, usage_txt + 980, usage_txt +1028, usage_txt +1082,
      usage_txt +1095, usage_txt +1103, usage_txt +1145, usage_txt +1169,
      usage_txt +1209, usage_txt +1224, usage_txt +1254, usage_txt +1280,
      usage_txt +1293, usage_txt +1307, usage_txt +1354, usage_txt +1360,
      usage_txt +1463, usage_txt +1475, usage_txt +1526, usage_txt +1555,
      usage_txt +1606, usage_txt +1640, usage_txt +1681, usage_txt +1704,
      usage_txt +1730, usage_txt +1761, usage_txt +1775, usage_txt +1790,
      usage_txt +1821, usage_txt +1848, usage_txt +1954, usage_txt +1960,
      usage_txt +1966, usage_txt +1973, usage_txt +1984, usage_txt +2010,
      usage_txt +2036, usage_txt +2079, usage_txt +2115, usage_txt +2166,
      usage_txt +2222, usage_txt +2256, usage_txt +2294, usage_txt +2359,
      usage_txt +2402, usage_txt +2437, usage_txt +2478, usage_txt +2518,
      usage_txt +2545, usage_txt +2612, usage_txt +2660, usage_txt +2693,
      usage_txt +2718, usage_txt +2766, usage_txt +2801, usage_txt +2839,
      usage_txt +2866, usage_txt +2915, usage_txt +2920, usage_txt +2938,
      usage_txt +2973, usage_txt +3017, usage_txt +3071, usage_txt +3117,
      usage_txt +3166, usage_txt +3219, usage_txt +3227, usage_txt +3275,
      usage_txt +3300, usage_txt +3334, usage_txt +3363, usage_txt +3382,
      usage_txt +3416, usage_txt +3452, usage_txt +3490, usage_txt +3546,
      usage_txt +3572, usage_txt +3638, usage_txt +3651, usage_txt +3682,
      usage_txt +3719, usage_txt +3747, usage_txt +3753, usage_txt +3802,
      usage_txt +3816, usage_txt +3862, usage_txt +3890, usage_txt +3935,
      usage_txt +3977, usage_txt +3991, usage_txt +4016, usage_txt +4056,
      usage_txt +4099, usage_txt +4103, usage_txt +4322, usage_txt +4325,
      usage_txt +4332, usage_txt +4336, usage_txt +4344, usage_txt +4348,
      usage_txt +4352, usage_txt +4356, usage_txt +4360, usage_txt +4364,
      usage_txt +4368, usage_txt +4372, usage_txt +4376, usage_txt +4380,
      usage_txt +4384, usage_txt +4391, usage_txt +4403, usage_txt +4411,
      usage_txt +4415, usage_txt +4418, usage_txt +4451, usage_txt +4488,
      usage_txt +4518
    }
  };

#endif /* DO_TRANSLATIONS */
#endif /* AUTOOPTS_USAGE_TXT_H_GUARD */
