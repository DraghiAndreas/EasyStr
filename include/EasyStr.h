#ifndef EASY_STR_H
#define EASY_STR_H

#include <stddef.h>

typedef enum {UPPER,LOWER,CAP,SWAP} STRING_MODE;
typedef enum {AL,DG,AN,UP,LOW,SPACE} CHR_MODE;
typedef enum {RIGHT, LEFT, BOTH} TRIM_MODE  ;

// --Character Type Checks--
int EasyIsAlphaChr(const unsigned char c);
int EasyIsDigitChr(const unsigned char c);
int EasyIsAlnumChr(const unsigned char c);
int EasyIsUpperChr(const unsigned char c);
int EasyIsLowerChr(const unsigned char c);
int EasyIsSpaceChr(const unsigned char c);

// --String Type Checks--
int EasyIsAlphaStr(const char * c);
int EasyIsDigitStr(const char * c);
int EasyIsAlnumStr(const char * c);
int EasyIsUpperStr(const char * c);
int EasyIsLowerStr(const char * c);
int EasyIsSpaceStr(const char * c);

// ---- Comparison/Searching ----

// -size_t
size_t EasyLen(const char* string);
size_t EasyCount(const char* string, const char c);
size_t EasyStrCount(const char* string, const char* c);

//  -int
int EasyStartsWith(const char * string, const char * prefix);
int EasyCmp(const char* string1, const char* string2);
int EasyNCmp(const char* string1, const char* string2, int n);
int EasyEndsWith(const char * string, const char * suffix);

// -char*
char * EasyRSearchStr(const char* string, const char* c);
char * EasySearchStr(const char* string, const char* c);
char *EasyRSearchChr(char *string, const char c);
char *EasySearchChr(char *string, const char c);

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
char * EasyLower(char* dest);
char * EasyUpper(char* dest);
char * EasySwapcase(char* dest);
char * EasyCapitalize(char* dest);
char * EasyRev(char* string);

#endif