#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//EXTRA
typedef enum {UPPER,LOWER,CAP,SWAP} STRING_MODE;
typedef enum {AL,DG,AN,UP,LOW,SPACE} CHR_MODE;

void efSwap(char* v1, char* v2);

// INTS
//--------// EasyLen, EasyCmp, EasyNCmp, EasyCount, EasyStrCount ,IsAlpha, IsDigit, IsAlnum, IsUpper/Lower, isSpace, EasyStartsWith|

int IsGeneralCaseChr(const char c, CHR_MODE mode) {
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
    return 0;
}

int IsGeneralCaseStr(const char * c, CHR_MODE mode) {
    if (!*c || !c) return 0;
    while (*c) {
        switch (mode) {
            case AL:
                if ((*c | 0x20) >= 'a' && (*c | 0x20) <= 'z')c++;
                else return 0;
                break;
            case DG:
                if (*c >= '0' && *c <= '9')c++;
                else return 0;
                break;
            case AN:
                if (IsGeneralCaseChr(*c,AL) || IsGeneralCaseChr(*c,DG))c++;
                else return 0;
                break;
            case UP:
                if (*c >= 'A' && *c <= 'Z')c++;
                else return 0;
                break;
            case LOW:
                if (*c >= 'a' && *c <= 'z')c++;
                else return 0;
                break;
            case SPACE:
                if (*c == ' ')c++;
                else return 0;
                break;
            default:
                return 0;
        }
    }
    return 1;
}

int EasyIsAlphaChr(const char c) {return  IsGeneralCaseChr(c,AL);}
int EasyIsDigitChr(const char c) {return  IsGeneralCaseChr(c,DG);}
int EasyIsAlnumChr(const char c) {return  IsGeneralCaseChr(c,AN);}
int EasyIsUpperChr(const char c) {return  IsGeneralCaseChr(c,UP);}
int EasyIsLowerChr(const char c) {return  IsGeneralCaseChr(c,LOW);}
int EasyIsSpaceChr(const char c) {return  IsGeneralCaseChr(c,SPACE);}

int EasyIsAlphaStr(const char * c) {return  IsGeneralCaseStr(c,AL);}
int EasyIsDigitStr(const char * c) {return  IsGeneralCaseStr(c,DG);}
int EasyIsAlnumStr(const char * c) {return  IsGeneralCaseStr(c,AN);}
int EasyIsUpperStr(const char * c) {return  IsGeneralCaseStr(c,UP);}
int EasyIsLowerStr(const char * c) {return  IsGeneralCaseStr(c,LOW);}
int EasyIsSpaceStr(const char * c) {return  IsGeneralCaseStr(c,SPACE);}

//--------------------------------------------//

int EasyStartsWith(const char * string, const char * prefix) {
    while (*prefix) {
        if (*string != *prefix) return 0;
        string++;
        prefix++;
    }
    return 1;
}

int EasyLen(const char* string) {
    char* p = string;

    if (!*string) return 0;

    while (*string) {
        string++;
    }
    return string - p;
}

int EasyCmp(const char* string1, const char* string2) {
    while ((*string1 == *string2) && *string1) {
        string1++;
        string2++;
    }
    return ((*string1) == '\0' && (*string2) == '\0');
}

int EasyEndsWith(const char * string, const char * sufix) {
    const size_t string_len = EasyLen(string);
    const size_t sufix_len = EasyLen(sufix);

    if (!*string || !*sufix) return 0;
    if (sufix_len > string_len) return 0;

    return (EasyCmp(string+(string_len-sufix_len),sufix));
}

int EasyNCmp(const char* string1, const char* string2, int n) {
    while ((*string1 == *string2) && *string1 && n) {
        string1++;
        string2++;
        n--;
    }
    return(*string1 == *string2);
}

int EasyCount(const char* string, const char c) {
    int count = 0;
    while (*string++) {
        if (*string == c) {
            count++;
        }
    }
    return count;
}

int EasyStrCount(const char* string, const char* c) {
    int count = 0, len = EasyLen(c);

    while (*string) {
        const char* s = string;
        const char* sub = c;

        while (*s && *sub && *s == *sub) {
            s++;
            sub++;
        }

        if (*sub == '\0') {
            count++;
            string += len;
        }
        else {
            string++;
        }
    }
    return count;
}



// CHAR* 
//--------// EasyCpy, EasyNCpy, EasyCat, EasyUpper, EasyLower, EasyRev, EasySplit, EasySwapcase, EasyCapitalize,
//EasyInsert, EasyNCat , EasySearchChr, EasyRSearchChr, EasySearchStr, EasyRSearchStr| TODO : EasyTrim (L+R), EasyReplace, EasyJoin


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

int main() {
    char text[] = "test test test";
    char text2[] = "a test or something";
    char text4[] = "bACalAurEat";
    char text3[20] = "ThIs is ";
    char text5[30] = "iluminati";

    char** arr = NULL;
    int words;

    printf("%d", EasyEndsWith("this is a test","test"));


    int test;
}

//Extra
void efSwap(char* v1, char* v2) {
    *v1 = *v1 ^ *v2;
    *v2 = *v1 ^ *v2;
    *v1 = *v1 ^ *v2;
}
