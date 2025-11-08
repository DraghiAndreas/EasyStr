#include "../include/EasyStr.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {UPPER,LOWER,CAP,SWAP} STRING_MODE;
typedef enum {AL,DG,AN,UP,LOW,SPACE} CHR_MODE;
typedef enum {RIGHT, LEFT, BOTH} TRIM_MODE;

static void efSwap(char* v1, char* v2) {
    if (v1==v2)return;
    *v1 = *v1 ^ *v2;
    *v2 = *v1 ^ *v2;
    *v1 = *v1 ^ *v2;
}


static int IsGeneralCaseChr(const unsigned char chr, CHR_MODE mode) {
    switch (mode) {
        case AL:
            return ((chr | 0x20) >= 'a' && (chr | 0x20) <= 'z');
        case DG:
            return (chr >= '0' && chr <= '9');
        case AN:
            return (IsGeneralCaseChr(chr,AL) || IsGeneralCaseChr(chr,DG));
        case UP:
            return (chr >= 'A' && chr <= 'Z');
        case LOW:
            return (chr >= 'a' && chr <= 'z');
        case SPACE:
            return  chr == ' ';
        default:
            return  0;
    }
}

static int IsGeneralCaseStr(const char * str, CHR_MODE mode) {
    if (!str || !*str) return 0;
    while (*str) {
       if (!IsGeneralCaseChr((unsigned char)*str, mode)) return 0;
        str++;
    }
    return 1;
}

int EasyIsAlphaChr(const unsigned char chr) {return  IsGeneralCaseChr(chr,AL);}
int EasyIsDigitChr(const unsigned char chr) {return  IsGeneralCaseChr(chr,DG);}
int EasyIsAlnumChr(const unsigned char chr) {return  IsGeneralCaseChr(chr,AN);}
int EasyIsUpperChr(const unsigned char chr) {return  IsGeneralCaseChr(chr,UP);}
int EasyIsLowerChr(const unsigned char chr) {return  IsGeneralCaseChr(chr,LOW);}
int EasyIsSpaceChr(const unsigned char chr) {return  IsGeneralCaseChr(chr,SPACE);}

int EasyIsAlphaStr(const char * string) {return  IsGeneralCaseStr(string,AL);}
int EasyIsDigitStr(const char * string) {return  IsGeneralCaseStr(string,DG);}
int EasyIsAlnumStr(const char * string) {return  IsGeneralCaseStr(string,AN);}
int EasyIsUpperStr(const char * string) {return  IsGeneralCaseStr(string,UP);}
int EasyIsLowerStr(const char * string) {return  IsGeneralCaseStr(string,LOW);}
int EasyIsSpaceStr(const char * string) {return  IsGeneralCaseStr(string,SPACE);}

int EasyStartsWith(const char * string, const char * prefix) {
    if (!string || !prefix) return 0;
    while (*prefix) {
        if (*string != *prefix) return 0;
        string++;
        prefix++;
    }
    return 1;
}

size_t EasyLen(const char* string) {
    if (!string || !*string) return 0;

    const char* p = string;

    while (*string) {
        string++;
    }
    return string - p;
}

int EasyCmp(const char* string1, const char* string2) {
    if (!string1 || !string2) return 0;
    while ((*string1 == *string2) && *string1) {
        string1++;
        string2++;
    }
    return ((*string1) == '\0' && (*string2) == '\0');
}

int EasyNCmp(const char* string1, const char* string2, int n) {
    if (!string1 || !string2 || n <= 0) return 0;
    while ((*string1 == *string2) && *string1 && n) {
        string1++;
        string2++;
        n--;
    }
    return(n==0 || *string1 == *string2);
}

int EasyEndsWith(const char * string, const char * suffix) {
    if (!string || !suffix || !*string ) return 0;
    if (!*suffix) return 1;

    const size_t string_len = EasyLen(string);
    const size_t suffix_len = EasyLen(suffix);

    if (suffix_len > string_len) return 0;

    return (EasyCmp(string+(string_len-suffix_len),suffix));
}


size_t EasyCount(const char* string, const char chr) {
    if (!string || !chr) return 0;
    size_t count = 0;
    while (*string) {
        if (*string == chr) {
            count++;
        }
        string++;
    }
    return count;
}

size_t EasyStrCount(const char* string1, const char* string2) {
    if (!string1 || !string2 || !*string2) return 0;
    size_t count = 0;
    while (*string1) {
        const char* s = string1;
        const char* sub = string2;

        while (*s && *sub && *s == *sub) {
            s++;
            sub++;
        }

        if (!*sub) {
            count++;
            string1 += sub-string2;
        }
        else {
            string1++;
        }
    }
    return count;
}

//----


char * EasyStrDup(const char * string) {
    if (!string) return NULL;
    size_t len = EasyLen(string);
    char * newString = (char*)malloc(len + 1);
    if (!newString) return NULL;
    memcpy(newString, string, len+1);
    return newString;
}

static char *  GeneralTrim(const char * string, TRIM_MODE MODE) {

    if (!string) return NULL;

    if (!*string || EasyIsSpaceStr(string)) {
        char *newString = (char*)malloc(1);
        if (!newString) return NULL;
        newString[0] = '\0';
        return newString;
    }

    size_t first = 0;
    if (MODE == LEFT || MODE == BOTH) {
        while (*(string+first) && EasyIsSpaceChr(*(string+first))) {
            first++;
        }
    }

    size_t last = EasyLen(string) - 1;
    if (MODE == RIGHT || MODE == BOTH) {
        while (*(string+last) && EasyIsSpaceChr(*(string+last))) {
            last--;
        }
    }

    size_t len = last - first + 1;
    char * newString = (char*)malloc(len + 1);
    if (!newString) return NULL;
    memmove(newString, string + first, len);
    newString[len] = '\0';

    return newString;
}

char * EasyRTrim(const char * string) {return GeneralTrim(string,RIGHT);}
char * EasyLTrim(const char * string) {return GeneralTrim(string,LEFT);}
char * EasyTrim(const char * string) {return GeneralTrim(string,BOTH);}


char * EasyRSearchStr(const char* string1, const char* string2) {
    if (!string1 || !string2 || !*string2) return NULL;

    const char * pointer = string1;
    const char * oc = string2;
    const char * la = NULL;

    while (*string1) {
        while (*string1 == *string2 && *string2) {
            string1++;
            string2++;
        }
        if (!*string2) {
            la = string1 - (string2 - oc);
        }
        pointer++;
        string1 = pointer;
        string2 = oc;
    }
    return (char*)la;
}

char * EasySearchStr(const char* string1, const char* string2) {

    if (!string1 || !string2 || !*string2) return NULL;

    const char * pointer = string1;
    const char * oc = string2;

    while (*string1) {
        while (*string1 == *string2 && *string2) {
            string1++;
            string2++;
        }
        if (!*string2) {
            return (char*)(string1 - (string2 - oc));
        } else {
            pointer++;
            string1 = pointer;
            string2 = oc;
        }
    }
    return  NULL;
}


char *EasyRSearchChr(const char *string, const char chr) {
    if (!string || !chr) return NULL;
    char *lastPos = NULL;
    while (*string) {
        if (*string == chr)
            lastPos = (char*)string;
        string++;
    }
    return lastPos;
}

char *EasySearchChr(const char *string, const char chr) {
    if (!string || !chr) return NULL;
    while (*string) {
        if (*string == chr)
            return (char*)string;
        string++;
    }
    return NULL;
}

char* EasyCpy(char* destination, const char* source) {
    if (!destination || !source) return NULL;
    char* orig = destination;
    while (*source) {
        *destination++ = *source++;
    }
    *destination = '\0';
    return orig;
}

char* EasyNCpy(char* destination, const char* source, size_t n) {
    if (!destination || !source || !n) return NULL;

    char* orig = destination;

    while (*source && n > 0) {
        *destination++ = *source++;
        n--;
    }
    if (n>0) {
        memset(destination, '\0', n);
    }

    return orig;
}

char* EasyCat(char* destination,const char* source) {
    if (!destination || !source) return NULL;
    char* orig = destination;
    while (*destination) {
        destination++;
    }
    while (*source) {
        *destination++ = *source++;
    }
    *destination = '\0';
    return orig;
}

char* EasyNCat(char* destination,const char* source, size_t n) {
    if (!destination || !source) return NULL;
    if (n == 0) return destination;

    char* orig = destination;
    while (*destination) {
        destination++;
    }
    while (*source && n) {
        *destination++ = *source++;
        n--;
    }
    *destination = '\0';
    return orig;
}

char* GeneralCase(char* string, STRING_MODE MODE) {
    if (!string) return NULL;

    char* orig = string;
    _Bool flag = 0;
    while (*string) {
        switch (MODE)
        {
        case UPPER:
            if (*string >= 'a' && *string <= 'z') {
                *string -= 32;
            }
            break;
        case LOWER:
            if (*string >= 'A' && *string <= 'Z') {
                *string += 32;
            }
            break;
        case SWAP:
            if (EasyIsAlphaChr(*string)){
                *string ^= 0x20;
            }
            break;
        case CAP:
            if (EasyIsAlphaChr(*string)) {
                if (!flag) {
                    *string &= ~(0x20);
                    flag = 1;
                }
                else {
                    *string |= 0x20;
                }
            }
            break;
        default:
            break;
        }
        string++;
    }
    return orig;
}

char* EasyLower(char* string) { return GeneralCase(string, LOWER); }
char* EasyUpper(char* string) { return GeneralCase(string, UPPER); }
char* EasySwapcase(char* string) { return GeneralCase(string, SWAP); }
char* EasyCapitalize(char* string) { return GeneralCase(string, CAP); }

char* EasyRev(char* string) {
    if (!string) return NULL;
    size_t len = EasyLen(string);
    char* orig = string;
    for (size_t i = 0; i < len / 2; i++) {
        efSwap(string + i, string + len - i - 1);
    }
    return  orig;
}

char* EasyInsert(const char* destination, const char* source, size_t location) {
    if (!destination || !source) return NULL;

    size_t origLen = EasyLen(destination);
    size_t len = EasyLen(source);

    char* newString = malloc(sizeof(char)*(origLen+len+1));

    EasyNCpy(newString, destination, location);
    newString[location] = '\0';

    EasyCat(newString, source);
    EasyCat(newString, destination + location);

    return newString;
}

static char** memAlloc(char** newArr,const char* origWord, const size_t len, const size_t wordCounter) {

    char** temp = (char**)realloc(newArr, sizeof(char*) * wordCounter);
    if (temp == NULL) return NULL;
    newArr = temp;

    newArr[wordCounter - 1] = (char*)malloc(sizeof(char) * (len+1));
    if (newArr[wordCounter - 1] == NULL) return NULL;

    memcpy(newArr[wordCounter - 1], origWord, sizeof(char) * (len));
    newArr[wordCounter - 1][len] = '\0';
    return newArr;
}

char ** EasySplit(char ** newArr, const char * source, const char* sep, size_t* wordCounter)
{
    if (source == NULL || sep == NULL || wordCounter == NULL) return NULL;

    const char* origWord = source;
    const char* origSource = source;
    const char* origSep = sep;

    *wordCounter = 0;

    while (*source)
    {
        while (*source == *sep && *sep)
        {
            source++;
            sep++;
        }

        if (!*sep)
        {
            while (source > origSource)
            {
                origSource++;
            }
            (*wordCounter)++;
            newArr = memAlloc(newArr, origWord, source - origWord - (sep - origSep), (*wordCounter));
            origWord = origSource;
        }
        else
        {
            origSource++;
        }
        if (!*origSource) {
            (*wordCounter)++;
            newArr = memAlloc(newArr, origWord, origSource - origWord, (*wordCounter));
        }
        source = origSource;
        sep = origSep;
    }
    return newArr;
}

char * EasyReplace(const char * string, const char * old, const char * new) {
    if (!string || !old || !new) return NULL;
    if (!*old) return EasyStrDup(string);

    const size_t count = EasyStrCount(string, old);
    if (count == 0) return EasyStrDup(string);

    size_t lenOld = EasyLen(old);
    size_t lenNew = EasyLen(new);

    size_t oldSize = EasyLen(string);
    size_t newSize = oldSize - (lenOld * count) + (lenNew * count);

    char * newString = (char*)malloc(newSize + 1);
    if (!newString) return NULL;

    char * dest = newString;
    const char * src = string;
    const char * pos;

    while ((pos = EasySearchStr(src,old))) {
        size_t len = pos - src;
        memcpy(dest,src,len);
        dest += len;

        memcpy(dest,new,lenNew);
        dest += lenNew;

        src = pos + lenOld;
    }

    EasyCpy(dest, src);
    return newString;
}

char * EasyJoin(char ** strings, size_t count, char * sep) {
    //Edge handling
    if (!strings || !sep) return NULL;
    if (!count) {
        char * newString = malloc(1);
        if (!newString) return NULL;
        newString[0] = '\0';
        return newString;
    }

    size_t null_terms = 0;
    size_t length = 0;
    size_t sepLength = EasyLen(sep);
    for (size_t i = 0; i < count; i++) {
        if (strings[i]) {
            length += EasyLen(strings[i]);
        } else {
            null_terms++;
        }
    }
    length += sepLength * (count-null_terms-1);
    char * newString = (char*)malloc(length+1);
    if (!newString) return NULL;

    char *dest = newString;

    _Bool first = true;

    for (size_t i = 0; i < count; i++) {

        if (!strings[i]) {
            continue;
        }

        if (!first) {
            memcpy(dest,sep,sepLength);
            dest += sepLength;
        }

        size_t wordLen = EasyLen(strings[i]);
        memcpy(dest,strings[i],wordLen);
        dest += wordLen;
        first = false;
    }
    newString[length] = '\0';

    return newString;
}

