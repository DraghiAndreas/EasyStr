#include <EasyStr.h>
#include <stdio.h>
#include <stdlib.h>
#define sep() printf("-------------------------------\n")

void character_validation(void);
void string_validation(void);
void string_comparison_inspection(void);
void string_counting(void);
void string_searching(void);
void memory_copying_concatenation(void);
void string_manipulation_nm(void);
void string_manupulation_ip(void);

int main(void) {
    character_validation();
    string_validation();
    string_comparison_inspection();
    string_counting();
    string_searching();
    memory_copying_concatenation();
    string_manipulation_nm();
    string_manupulation_ip();
}

void character_validation(void) {
    printf("1. Character Validation\n");
    sep();
    char test_chars[] = {'A','1',' ','b','$'};
    for (int i = 0; i < sizeof(test_chars)/sizeof(test_chars[0]); i++) {
        printf("Character : '%c' | IsAlpha : %d | IsDigit : %d | IsAlnum : %d | IsUpper : %d | IsLower : %d | IsSpace : %d \n",test_chars[i],
            EasyIsAlphaChr(test_chars[i]),
            EasyIsDigitChr(test_chars[i]),
            EasyIsAlnumChr(test_chars[i]),
            EasyIsUpperChr(test_chars[i]),
            EasyIsLowerChr(test_chars[i]),
            EasyIsSpaceChr(test_chars[i]));
    }
    printf("\n");
}

void string_validation(void) {
    printf("2. String Validation\n");
    sep();
    char *test_chars[] = {"abcdef","123456","abc456","ABCDEF","      "};
    for (int i = 0; i < sizeof(test_chars)/sizeof(test_chars[0]); i++) {
        printf("Character : '%s' | IsAlpha : %d | IsDigit : %d | IsAlnum : %d | IsUpper : %d | IsLower : %d | IsSpace : %d \n",test_chars[i],
            EasyIsAlphaStr(test_chars[i]),
            EasyIsDigitStr(test_chars[i]),
            EasyIsAlnumStr(test_chars[i]),
            EasyIsUpperStr(test_chars[i]),
            EasyIsLowerStr(test_chars[i]),
            EasyIsSpaceStr(test_chars[i]));
    }
    printf("\n");
}

void string_comparison_inspection(void) {
    printf("3. String Comparison/Inspection\n");
    sep();

    const char * string1 = "This is a test";
    printf("EasyLen:\n");
    printf("String : '%s' | Length : %zu \n\n",string1,EasyLen(string1));

    const char * string2 = "Testing";
    const char * string3 = "Testing";
    const char * string4 = "Test";
    printf("EasyCmp:\n");
    printf("String1 : '%s' | String2 : '%s' | Cmp : %d \n",string2,string3,EasyCmp(string2,string3));
    printf("String1 : '%s' | String2 : '%s' | Cmp : %d \n\n",string3,string4,EasyCmp(string3,string4));

    const char * string5 = "Testing";
    const char * string6 = "Test";
    const char * string7 = "ing";
    int n = 4;
    printf("EasyNCmp:\n");
    printf("String1 : '%s' | String2 : '%s' | N : %d | Cmp : %d \n",string5,string6,n,EasyNCmp(string5,string6,n));
    n = 5;
    printf("String1 : '%s' | String2 : '%s' | N : %d | Cmp : %d \n\n",string5,string6,n,EasyNCmp(string5,string6,n));

    printf("EasyStartsWith: :\n");
    printf("String1 : '%s' | Prefix : '%s' | StartsWith : %d \n",string5,string6,EasyStartsWith(string5,string6));
    printf("String1 : '%s' | Prefix : '%s' | StartsWith : %d \n\n",string5,string7,EasyStartsWith(string5,string7));

    printf("EasyEndsWith: :\n");
    printf("String1 : '%s' | Suffix : '%s' | StartsWith : %d \n",string5,string6,EasyEndsWith(string5,string6));
    printf("String1 : '%s' | Suffix : '%s' | StartsWith : %d \n",string5,string7,EasyEndsWith(string5,string7));
    printf("\n");
}

void string_counting(void) {
    printf("4. String Counting\n");
    sep();
    const char * string1 = "This test is a simple test";
    const char chr = 't';
    const char chr2 = 'a';
    const char * string2 = "test";
    const char * string3 = "easy";

    printf("EasyCount: \n");
    printf("String1 : '%s' | Chr : '%c' | Count : %d \n",string1,chr,EasyCount(string1,chr));
    printf("String1 : '%s' | Chr : '%c' | Count : %d \n\n",string1,chr2,EasyCount(string1,chr2));

    printf("EasyStrCount: \n");
    printf("String1 : '%s' | Chr : '%s' | Count : %d \n",string1,string2,EasyStrCount(string1,string2));
    printf("String1 : '%s' | Chr : '%s' | Count : %d \n",string1,string3,EasyCount(string1,string3));
    printf("\n");
}

void string_searching(void) {
    printf("5. String Searching\n");
    sep();
    const char * string1 = "This test is a simple test used for testing puropses\n";
    printf("Original String : %s\n", string1);

    const char chr = 't';
    const char * string2 = "test";

    printf("EasySearchChr: \n");
    printf("Character : '%c'\n",chr);
    char * result = EasySearchChr(string1,chr);
    printf("%s\n",result);

    printf("EasyRSearchChr: \n");
    printf("Character : '%c'\n",chr);
    char * result2 = EasyRSearchChr(string1,chr);
    printf("%s\n",result2);

    printf("EasySearchStr: \n");
    printf("String : '%s'\n",string2);
    char * result3 = EasySearchStr(string1,string2);
    printf("%s\n",result3);

    printf("EasyRSearchStr: \n");
    printf("String : '%s'\n",string2);
    char * result4 = EasyRSearchStr(string1,string2);
    printf("%s\n",result4);
}

void memory_copying_concatenation(void) {
    printf("6. Memory, Copy, & Concatenation\n");
    sep();

    char * string = "Original String";
    char * copy = NULL;

    printf("EasyStrDup: \n");
    printf("Original String : '%s' | Address : %p\n",string, string);
    copy = EasyStrDup(string);
    printf("Duplicated String : '%s' | Address : %p\n\n",copy, copy);

    char source1[] = "This";
    char destination[20] = "";

    printf("EasyCpy: \n");
    printf("Original String : '%s' | Address : %p \n",destination,destination);
    printf("Source String : '%s' | Address : %p \n",source1,source1);
    EasyCpy(destination,source1);
    printf("Original String (post-copy) : '%s' | Address : %p \n\n",destination,destination);

    char source2[] = " is a test";
    size_t n = 3;
    printf("EasyNCpy: \n");
    printf("Original String : '%s' | Address : %p \n",destination,destination);
    printf("Source String : '%s' | Address : %p \n",source2,source2);
    EasyNCpy(destination+4,source2,n);
    printf("Original String (post-copy) : '%s' | N : %lld | Address : %p \n\n",destination,n,destination);

    char source3[] = " a simple";
    printf("EasyCat: \n");
    printf("Original String : '%s' | Address : %p \n",destination,destination);
    printf("Source String : '%s' | Address : %p \n",source3,source3);
    EasyCat(destination,source3);
    printf("Original String (post-concat) : '%s' | Address : %p \n\n",destination,destination);

    char source4[] = " testing";
    n = 5;
    printf("EasyNCat: \n");
    printf("Original String : '%s' | Address : %p \n",destination,destination);
    printf("Source String : '%s' | Address : %p \n",source3,source3);
    EasyNCat(destination,source4,n);
    printf("Original String (post-concat) : '%s' | N : %lld | Address : %p \n\n",destination,n,destination);

    free(copy);
}

void string_manipulation_nm(void) {
    printf("7. String Manipulation (New Memory)\n");
    sep();

    char * string = "     TEST";
    printf("EasyLTrim: \n");
    printf("Original String : '%s' | Address : %p\n" ,string,string);
    char * str = EasyLTrim(string);
    printf("Trimmed String : '%s' | Address : %p\n\n",str,str);

    char * string2 = "TEST     ";
    printf("EasyLTrim: \n");
    printf("Original String : '%s' | Address : %p\n" ,string2,string2);
    char * str2 = EasyRTrim(string2);
    printf("Trimmed String : '%s' | Address : %p\n\n",str2,str2);

    char * string3 = "     TEST     ";
    printf("EasyTrim: \n");
    printf("Original String : '%s' | Address : %p\n" ,string3,string3);
    char * str3 = EasyTrim(string3);
    printf("Trimmed String : '%s' | Address : %p\n\n",str3,str3);

    char * string4 = "This is a test";
    char * source = "simple ";
    size_t location = 10;
    printf("EasyInsert: \n");
    printf("Original String : '%s' | Address : %p\n" ,string4,string4);
    printf("Word-to-insert : '%s' | Location : %lld\n" ,source,location);
    char * str4 = EasyInsert(string4,source,location);
    printf("Inserted String : '%s' | Address : %p\n\n",str4,str4);

    char * source2 = "demo";
    char * replace = "test";
    printf("EasyReplace: \n");
    printf("Original String : '%s' | Address : %p\n" ,string4,string4);
    printf("Replacing '%s' -> '%s'\n",replace,source2);
    char * str5 = EasyReplace(string4,replace,source2);
    printf("Replaced String : '%s' | Address : %p\n\n",str5,str5);

    char ** newArr = NULL;
    int wordCount;
    printf("EasySplit: \n");
    printf("Original String : '%s' | Address : %p\n" ,string4,string4);
    newArr = EasySplit(newArr,string4," ",&wordCount);
    printf("Number of words : %d\n", wordCount);
    printf("Words : \n");
    for (int i = 0 ; i < wordCount ; i++) {
        printf("newArr[%d] : %s\n",i,newArr[i]);
    }
    printf("\n");

    printf("EasyJoin: \n");
    char* sep1 = " ";
    printf("Number of words : %d\n", wordCount);
    printf("Words : \n");
    for (int i = 0 ; i < wordCount ; i++) {
        printf("newArr[%d] : %s\n",i,newArr[i]);
    }
    char * newStr = EasyJoin(newArr,wordCount,sep1);
    printf("Joined string : %s | Separator : '%s'\n",newStr,sep1);

    free(str);
    free(str2);
    free(str3);
    free(str4);
    free(str5);
    for (int i = 0 ; i < wordCount ; i++) {
        free(newArr[i]);
    }
    free(newArr);
    free(newStr);
}

void string_manupulation_ip(void) {
    printf("8. String Manipulation (In-Place)\n");
    sep();

    char test[] = "tEsTiNg";
    printf("EasyLower:\n");
    printf("Original String : '%s' | Address : %p\n" ,test,test);
    EasyLower(test);
    printf("Original String (after) : '%s' | Address : %p\n\n" ,test,test);

    EasyCpy(test,"tEsTiNg");
    printf("EasyUpper:\n");
    printf("Original String : '%s' | Address : %p\n" ,test,test);
    EasyUpper(test);
    printf("Original String (after) : '%s' | Address : %p\n\n" ,test,test);

    EasyCpy(test,"tEsTiNg");
    printf("EasySwapcase:\n");
    printf("Original String : '%s' | Address : %p\n" ,test,test);
    EasySwapcase(test);
    printf("Original String (after) : '%s' | Address : %p\n\n" ,test,test);

    EasyCpy(test,"tEsTiNg");
    printf("EasyCapitalize:\n");
    printf("Original String : '%s' | Address : %p\n" ,test,test);
    EasyCapitalize(test);
    printf("Original String (after) : '%s' | Address : %p\n\n" ,test,test);

    EasyCpy(test,"tEsTiNg");
    printf("EasyRev:\n");
    printf("Original String : '%s' | Address : %p\n" ,test,test);
    EasyRev(test);
    printf("Original String (after) : '%s' | Address : %p\n\n" ,test,test);
}