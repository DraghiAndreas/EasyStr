#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//EXTRA
void efSwap(char* v1, char* v2);

// INTS
//--------// EasyLen, EasyCmp, EasyNCmp, EasyCount, EasyStrCount | TODO : EasyIsLet


int EasyLen(const char* string) {
    char* p = string;
    while(*string) {
        string++;
    }
    return string-p;
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

int EasyCount(const char* string,const char c) {
    int count = 0;
    while (*string++) {
        if (*string == c) {
            count++;
        }
    }
    return count;
}

int EasyStrCount(const char* string, const char *c) {
    int count = 0, len = EasyLen(c) ;

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
    return ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'));
}

// CHAR* 
//--------// EasyCpy, EasyNCpy, EasyCat, EasyUpper, EasyLower, EasyRev | TODO : EasyNCat, EasyInsert, EasySplit
// EasySwapcase, EasyCapitalize , EasySearchChr, EasyRSearchChr, EasySearchStr, EasyRSearchStr

char * EasyCpy(char* destination,const char* source) {
    char* orig = destination;
    while (*source) {
        *destination++= *source++;
    }
    *destination = '\0';
    return orig;
}

char * EasyNCpy(char* destination, const char* source,int n) {
    if (n <= 0) return destination;
    char* orig = destination;
    while (*source && n > 0) {
        *destination++ = *source++;
        n--;
    }
    memset(destination, '\0', n);
    return orig;
}

char * EasyCat(char* destination, char* source) {
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

char* EasyUpper(char* destination) {
    char* orig = destination;
    while (*destination) {
        if (*destination >= 'a' && *destination <= 'z') {
            *destination -= 32;
        }
        destination++;
    }
    return orig;
}

char* EasyLower(char* destination) {
    char* orig = destination;
    while (*destination) {
        if (*destination >= 'A' && *destination <= 'Z') {
            *destination += 32;
        }
        destination++;
    }
    return orig;
}

char* EasySwapcase(char* string) {
    char* orig = string;
    while (*string) {
        if (*string >= 'a' && *string <= 'z') *string -= 32;
        else if (*string >= 'A' && *string <= 'Z') *string += 32;
        string++;
    }
}

char* EasyCapitalize(char* string) {
    char* orig = string;
    _Bool first = 0;
    while (*string) {
        if (!first && EasyIsLet(string)){
            *string -= 32;
            first = 1;
            string++;
            continue;
        }
        if (*string >= 'A' && *string <= 'Z') *string += 32;
        string++;
    }
    return orig;
}

char* EasyRev(char* string) {
    int len = EasyLen(string);
    char* orig = string;
    for (int i = 0; i < len / 2; i++) {
        efSwap(string + i, string + len - i - 1);
    }
    return  orig;
}



char* EasyInsert(char* destination, char* source, const int location) {
    return;
}

char ** EasySplit(char** newArr,const char* source,const char* sep , int* wordCounter)
{
    const char* origSource = source;
    const char* origSep = sep;
    const char* origWord = source;
    const int len = EasyLen(sep);
    *wordCounter = 0;

    while(*source)
    {
        while (*source == *sep && *sep)
        {
            source++;
            sep++;
        }

        if ((source - origSource == len))
        {
            while (source > origSource)
            {
                origSource++;
            }
            (*wordCounter)++;
            if (newArr == NULL) {
                newArr = (char**)malloc(sizeof(char*));
                newArr[0] = (char*)malloc(sizeof(char) * (source - origWord - len));
                memcpy(newArr[0], origWord, sizeof(char) * (source - origWord - len));
                newArr[0][source - origWord - len] = '\0';
            }
            else {
                newArr = (char**)realloc(newArr, sizeof(char*) * (*wordCounter));
                newArr[(*wordCounter) -1] = (char*)malloc(sizeof(char) * (source - origWord - len));
                memcpy(newArr[(*wordCounter) - 1], origWord, sizeof(char) * (source - origWord - len));
                newArr[(*wordCounter) - 1][source - origWord - len] = '\0';
            }
            origWord = origSource;
        }
        else
        {
            origSource++;
        }
        if (!*origSource) {
            (*wordCounter)++;
            if (newArr == NULL) {
                newArr = (char**)malloc(sizeof(char*));
                newArr[0] = (char*)malloc(sizeof(char) * (origSource - origWord));
                memcpy(newArr[0], origWord, sizeof(char) * (origSource - origWord));
                newArr[0][origSource - origWord] = '\0';
            }
            else {
                newArr = (char**)realloc(newArr, sizeof(char*) * (*wordCounter));
                newArr[(*wordCounter) - 1] = (char*)malloc(sizeof(char) * (origSource - origWord));
                memcpy(newArr[(*wordCounter) - 1], origWord, sizeof(char) * (origSource - origWord));
                newArr[(*wordCounter) - 1][origSource - origWord] = '\0';
            }
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
    char text3[20]= "ThIs is ";







    char** newArr = NULL;
    int counter;

    newArr = EasySplit(newArr,"ana are multe, multe mere si pere"," ",&counter);


    //Afisare cuvinte
    for (int i = 0; i < counter; i++) {
        printf("%s\n", newArr[i]);
    }
}









//Extra
void efSwap(char* v1, char* v2) {
    *v1 = *v1 ^ *v2;
    *v2 = *v1 ^ *v2;
    *v1 = *v1 ^ *v2;
}