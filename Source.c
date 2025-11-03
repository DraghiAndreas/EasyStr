#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//EXTRA
typedef enum {UPPER,LOWER,CAP,SWAP} STRING_MODE;
typedef enum {AL,DG,AN,UP,LOW,SPACE} CHR_MODE;
typedef enum {RIGHT, LEFT, BOTH} TRIM_MODE  ;
static void efSwap(char* v1, char* v2);
// INTS
//--------// EasyLen, EasyCmp, EasyNCmp, EasyCount, EasyStrCount ,IsAlpha, IsDigit, IsAlnum, IsUpper/Lower, isSpace, EasyStartsWith|

static int IsGeneralCaseChr(const unsigned char c, CHR_MODE mode) {
    switch (mode) {
        case AL:
            return ((c | 0x20) >= 'a' && (c | 0x20) <= 'z');
        case DG:
            return (c >= '0' && c <= '9');
        case AN:
            return (IsGeneralCaseChr(c,AL) || IsGeneralCaseChr(c,DG));
        case UP:
            return (c >= 'A' && c <= 'Z');
        case LOW:
            return (c >= 'a' && c <= 'z');
        case SPACE:
            return  c == ' ';
        default:
            return  0;
    }
}

static int IsGeneralCaseStr(const char * c, CHR_MODE mode) {
    if (!c || !*c) return 0;
    while (*c) {
       if (!IsGeneralCaseChr((unsigned char)*c, mode)) return 0;
        c++;
    }
    return 1;
}

int EasyIsAlphaChr(const unsigned char c) {return  IsGeneralCaseChr(c,AL);}
int EasyIsDigitChr(const unsigned char c) {return  IsGeneralCaseChr(c,DG);}
int EasyIsAlnumChr(const unsigned char c) {return  IsGeneralCaseChr(c,AN);}
int EasyIsUpperChr(const unsigned char c) {return  IsGeneralCaseChr(c,UP);}
int EasyIsLowerChr(const unsigned char c) {return  IsGeneralCaseChr(c,LOW);}
int EasyIsSpaceChr(const unsigned char c) {return  IsGeneralCaseChr(c,SPACE);}

int EasyIsAlphaStr(const char * c) {return  IsGeneralCaseStr(c,AL);}
int EasyIsDigitStr(const char * c) {return  IsGeneralCaseStr(c,DG);}
int EasyIsAlnumStr(const char * c) {return  IsGeneralCaseStr(c,AN);}
int EasyIsUpperStr(const char * c) {return  IsGeneralCaseStr(c,UP);}
int EasyIsLowerStr(const char * c) {return  IsGeneralCaseStr(c,LOW);}
int EasyIsSpaceStr(const char * c) {return  IsGeneralCaseStr(c,SPACE);}

//--------------------------------------------//

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

int EasyEndsWith(const char * string, const char * suffix) {
    if (!string || !suffix || !*string || !*string) return 0;

    const size_t string_len = EasyLen(string);
    const size_t suffix_len = EasyLen(suffix);

    if (suffix_len > string_len) return 0;

    return (EasyCmp(string+(string_len-suffix_len),suffix));
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

size_t EasyCount(const char* string, const char c) {
    if (!string || !c) return 0;
    size_t count = 0;
    while (*string) {
        if (*string == c) {
            count++;
        }
        string++;
    }
    return count;
}

size_t EasyStrCount(const char* string, const char* c) {
    if (!string || !c || !*c) return 0;
    size_t count = 0;
    while (*string) {
        const char* s = string;
        const char* sub = c;

        while (*s && *sub && *s == *sub) {
            s++;
            sub++;
        }

        if (!*sub) {
            count++;
            string += sub-c;
        }
        else {
            string++;
        }
    }
    return count;
}


//memmove(
// CHAR* 
//--------// EasyCpy, EasyNCpy, EasyCat, EasyUpper, EasyLower, EasyRev, EasySplit, EasySwapcase, EasyCapitalize,
//EasyInsert, EasyNCat , EasySearchChr, EasyRSearchChr, EasySearchStr, EasyRSearchStr, EasyTrim (L+R), EasyStrDupe| TODO : EasyReplace, EasyJoin

char * EasyStrDup(const char * string) {
    if (!string) return NULL;
    size_t len = EasyLen(string);
    char * newString = (char*)malloc(len + 1);
    if (!newString) return NULL;
    memcpy(newString, string, len+1);
    return newString;
}

static char *  GeneralTrim(const char * string, TRIM_MODE MODE) {

    if (!string || !*string) return NULL;

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


char * EasyRSearchStr(const char* string, const char* c) {
    const char * pointer = string;
    const char * oc = c;
    const char * la = NULL;

    if (!*c) return NULL;

    while (*string) {
        while (*string == *c && *c) {
            string++;
            c++;
        }
        if (!*c) {
            printf("UPDATE\n");
            la = string - (c - oc);
        }
        pointer++;
        string = pointer;
        c = oc;
    }
    return la;
}

char * EasySearchStr(const char* string, const char* c) {
    const char * pointer = string;
    const char * oc = c;

    if (!*c) return NULL;

    while (*string) {
        while (*string == *c && *c) {
            string++;
            c++;
        }
        if (!*c) {
            return string - (c - oc);
        } else {
            pointer++;
            string = pointer;
            c = oc;
        }
    }
    return  NULL;
}


char *EasyRSearchChr(char *string, const char c) {
    char *lastPos = NULL;
    while (*string) {
        if (*string == c)
            lastPos = string;
        string++;
    }
    return lastPos;
}

char *EasySearchChr(char *string, const char c) {
    while (*string) {
        if (*string == c)
            return string;
        string++;
    }
    return NULL;
}

char* EasyCpy(char* destination, const char* source) {
    char* orig = destination;
    while (*source) {
        *destination++ = *source++;
    }
    *destination = '\0';
    return orig;
}

char* EasyNCpy(char* destination, const char* source, int n) {
    if (n <= 0) return destination;
    char* orig = destination;
    while (*source && n > 0) {
        *destination++ = *source++;
        n--;
    }
    memset(destination, '\0', n);
    return orig;
}

char* EasyCat(char* destination, char* source) {
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

char* EasyNCat(char* destination, char* source, int n) {
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

char* GeneralCase(char* destination, STRING_MODE MODE) {
    char* orig = destination;
    _Bool flag = 0;
    while (*destination) {
        switch (MODE)
        {
        case UPPER:
            if (*destination >= 'a' && *destination <= 'z') {
                *destination -= 32;
            }
            break;
        case LOWER:
            if (*destination >= 'A' && *destination <= 'Z') {
                *destination += 32;
            }
            break;
        case SWAP:
            if (EasyIsAlphaChr(*destination)){
                *destination ^= 0x20;
            }
            break;
        case CAP:
            if (EasyIsAlphaChr(*destination)) {
                if (!flag) {
                    *destination &= ~(0x20);
                    flag = 1;
                }
                else {
                    *destination |= 0x20;
                }
            }
            break;
        default:
            break;
        }
        destination++;
    }
    return orig;
}

char* EasyLower(char* dest) { return GeneralCase(dest, LOWER); }
char* EasyUpper(char* dest) { return GeneralCase(dest, UPPER); }
char* EasySwapcase(char* dest) { return GeneralCase(dest, SWAP); }
char* EasyCapitalize(char* dest) { return GeneralCase(dest, CAP); }

char* EasyRev(char* string) {
    int len = EasyLen(string);
    char* orig = string;
    for (int i = 0; i < len / 2; i++) {
        efSwap(string + i, string + len - i - 1);
    }
    return  orig;
}

char* EasyInsert(char* destination, char* source, int location) {
    char* temp = malloc(sizeof(char)*(EasyLen(destination)+EasyLen(source)+1));
    EasyNCpy(temp, destination, location);
    temp[location] = '\0';
    EasyCat(temp, source);
    EasyCat(temp, destination + location);
    EasyCpy(destination, temp);
    free(temp);
    return destination;
}

char** memAlloc(char** newArr, char* origWord, const int len, const int wordCounter) {
    if (newArr == NULL) {
        newArr = (char**)malloc(sizeof(char*));
        newArr[0] = (char*)malloc(sizeof(char) * (len));
        memcpy(newArr[0], origWord, sizeof(char) * (len));
        newArr[0][len] = '\0';
    }
    else {
        newArr = (char**)realloc(newArr, sizeof(char*) * wordCounter);
        newArr[wordCounter - 1] = (char*)malloc(sizeof(char) * (len));
        memcpy(newArr[wordCounter - 1], origWord, sizeof(char) * (len));
        newArr[wordCounter - 1][len] = '\0';
    }
    return newArr;
}

char** EasySplit(char** newArr, const char* source, const char* sep, int* wordCounter)
{
    
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

    const unsigned int count = EasyStrCount(string, old);
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

    while (pos = EasySearchStr(src,old)) {
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
        newString[0] = '\0';
        return newString;
    }

    unsigned int null_terms = 0;
    size_t length = 0;
    size_t sepLength = EasyLen(sep);
    for (int i = 0; i < count; i++) {
        if (strings[i]) {
            length += EasyLen(strings[i]);
        } else {
            null_terms++;
        }
    }
    length += sepLength * (count-null_terms-1);
    printf("Calculated length: %zu\n", length);
    char * newString = (char*)malloc(length+1);
    if (!newString) return NULL;

    char *dest = newString;

    _Bool first = true;

    for (int i = 0; i < count; i++) {

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

//This is a test
int main() {
    char text[] = "This test is a test.";
    printf("%d",EasyStrCount(text,"test"));
}

//Extra
static void efSwap(char* v1, char* v2) {
    *v1 = *v1 ^ *v2;
    *v2 = *v1 ^ *v2;
    *v1 = *v1 ^ *v2;
}
