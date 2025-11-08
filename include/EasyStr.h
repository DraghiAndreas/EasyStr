#ifndef EASY_STR_H
#define EASY_STR_H

#include <stddef.h>

// --Character Type Checks--
int EasyIsAlphaChr(const unsigned char chr);
int EasyIsDigitChr(const unsigned char chr);
int EasyIsAlnumChr(const unsigned char chr);
int EasyIsUpperChr(const unsigned char chr);
int EasyIsLowerChr(const unsigned char chr);
int EasyIsSpaceChr(const unsigned char chr);

// --String Type Checks--
int EasyIsAlphaStr(const char * string);
int EasyIsDigitStr(const char * string);
int EasyIsAlnumStr(const char * string);
int EasyIsUpperStr(const char * string);
int EasyIsLowerStr(const char * string);
int EasyIsSpaceStr(const char * string);

// ---- Comparison/Searching ----

// -size_t
size_t EasyLen(const char* string);
size_t EasyCount(const char* string, const char chr);
size_t EasyStrCount(const char* string1, const char* string2);

//  -int
int EasyStartsWith(const char * string, const char * prefix);
int EasyCmp(const char* string1, const char* string2);
int EasyNCmp(const char* string1, const char* string2, int n);
int EasyEndsWith(const char * string, const char * suffix);

// -char*
char * EasyRSearchStr(const char* string1, const char* string2);
char * EasySearchStr(const char* string1, const char* string2);
char *EasyRSearchChr(const char *string, const char chr);
char *EasySearchChr(const char *string, const char chr);

// ---- String Manipulation (New-Allocation) ----

// -char*
char * EasyStrDup(const char * string);
char * EasyRTrim(const char * string);
char * EasyLTrim(const char * string);
char * EasyTrim(const char * string);
char * EasyJoin(char ** strings, size_t count, char * sep);
char * EasyReplace(const char * string, const char * old, const char * new);
char * EasyInsert(const char* destination, const char* source, size_t location);

// -char**
char ** EasySplit(char** newArr, const char* source, const char* sep, size_t* wordCounter);

// ---- String Manipulation (In-Place) ----

// -char*
char * EasyCpy(char* destination, const char* source);
char * EasyNCpy(char* destination, const char* source, size_t n) ;
char * EasyCat(char* destination,const char* source);
char * EasyNCat(char* destination,const char* source, size_t n);
char * EasyLower(char* string);
char * EasyUpper(char* string);
char * EasySwapcase(char* string);
char * EasyCapitalize(char* string);
char * EasyRev(char* string);

#endif