#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//EXTRA
typedef enum {UPPER,LOWER,CAP,SWAP}STRING_MODE;

void efSwap(char* v1, char* v2);

// INTS
//--------// EasyLen, EasyCmp, EasyNCmp, EasyCount, EasyStrCount,EasyIsLet | TODO : 


int EasyLen(const char* string) {
    char* p = string;
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

int EasyIsLet(const char* c) {
    return ((*c | 0x20) >= 'a' && (*c | 0x20) <= 'z');
}


// CHAR* 
//--------// EasyCpy, EasyNCpy, EasyCat, EasyUpper, EasyLower, EasyRev, EasySplit, EasySwapcase, EasyCapitalize, EasyInsert  | TODO : EasyNCat,
//EasySearchChr, EasyRSearchChr, EasySearchStr, EasyRSearchStr


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
            if (EasyIsLet(destination)){
                *destination ^= 0x20;
            }
            break;
        case CAP:
            if (EasyIsLet(destination)) {
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

    EasyRev(text5);
    printf("%s", text5);
}









//Extra
void efSwap(char* v1, char* v2) {
    *v1 = *v1 ^ *v2;
    *v2 = *v1 ^ *v2;
    *v1 = *v1 ^ *v2;
}
