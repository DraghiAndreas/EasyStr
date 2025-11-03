#include "EasyStr.h"
#include <stdio.h>
#include <stdlib.h>

#define SEPARATOR() printf("\n%s\n\n", "========================================")

void demo_character_checks(void);
void demo_string_checks(void);
void demo_comparison_searching(void);
void demo_string_manipulation_new(void);
void demo_string_manipulation_inplace(void);

int main(void) {
    printf("╔════════════════════════════════════════╗\n");
    printf("║   EasyStr Library Function Demo       ║\n");
    printf("║   String Manipulation Made Easy       ║\n");
    printf("╚════════════════════════════════════════╝\n\n");

    demo_character_checks();
    demo_string_checks();
    demo_comparison_searching();
    demo_string_manipulation_new();
    demo_string_manipulation_inplace();

    printf("\n✓ Demo completed successfully!\n");
    return 0;
}

void demo_character_checks(void) {
    printf("1. CHARACTER TYPE CHECKS\n");
    SEPARATOR();

    char test_chars[] = {'A', 'z', '5', ' ', '@'};
    const char* descriptions[] = {"'A'", "'z'", "'5'", "' '", "'@'"};

    printf("Testing characters:\n");
    for (int i = 0; i < 5; i++) {
        printf("  %s -> Alpha: %d, Digit: %d, Alnum: %d, Upper: %d, Lower: %d, Space: %d\n",
               descriptions[i],
               EasyIsAlphaChr(test_chars[i]),
               EasyIsDigitChr(test_chars[i]),
               EasyIsAlnumChr(test_chars[i]),
               EasyIsUpperChr(test_chars[i]),
               EasyIsLowerChr(test_chars[i]),
               EasyIsSpaceChr(test_chars[i]));
    }
}

void demo_string_checks(void) {
    printf("\n2. STRING TYPE CHECKS\n");
    SEPARATOR();

    const char* test_strings[] = {
        "HelloWorld",
        "12345",
        "Hello123",
        "UPPERCASE",
        "lowercase",
        "   "
    };

    printf("Testing strings:\n");
    for (int i = 0; i < 6; i++) {
        printf("  \"%s\":\n", test_strings[i]);
        printf("    IsAlpha: %d | IsDigit: %d | IsAlnum: %d\n",
               EasyIsAlphaStr(test_strings[i]),
               EasyIsDigitStr(test_strings[i]),
               EasyIsAlnumStr(test_strings[i]));
        printf("    IsUpper: %d | IsLower: %d | IsSpace: %d\n",
               EasyIsUpperStr(test_strings[i]),
               EasyIsLowerStr(test_strings[i]),
               EasyIsSpaceStr(test_strings[i]));
    }
}

void demo_comparison_searching(void) {
    printf("\n3. COMPARISON & SEARCHING\n");
    SEPARATOR();

    // Length and counting
    const char* text = "Hello World! Welcome to EasyStr!";
    printf("String: \"%s\"\n", text);
    printf("  Length: %zu\n", EasyLen(text));
    printf("  Count 'o': %zu\n", EasyCount(text, 'o'));
    printf("  Count \"World\": %zu\n\n", EasyStrCount(text, "World"));

    // String comparison
    const char* str1 = "Hello";
    const char* str2 = "Hello";
    const char* str3 = "World";
    printf("Comparison:\n");
    printf("  EasyCmp(\"%s\", \"%s\"): %d\n", str1, str2, EasyCmp(str1, str2));
    printf("  EasyCmp(\"%s\", \"%s\"): %d\n", str1, str3, EasyCmp(str1, str3));
    printf("  EasyNCmp(\"%s\", \"%s\", 3): %d\n\n", str1, str3, EasyNCmp(str1, str3, 3));

    // Prefix/Suffix checking
    const char* filename = "document.txt";
    printf("Filename: \"%s\"\n", filename);
    printf("  StartsWith \"doc\": %d\n", EasyStartsWith(filename, "doc"));
    printf("  EndsWith \".txt\": %d\n", EasyEndsWith(filename, ".txt"));
    printf("  EndsWith \".pdf\": %d\n\n", EasyEndsWith(filename, ".pdf"));

    // Searching
    const char* haystack = "The quick brown fox jumps";
    printf("Haystack: \"%s\"\n", haystack);

    char* found = EasySearchStr(haystack, "brown");
    if (found) {
        printf("  SearchStr \"brown\": Found at position %ld\n", found - haystack);
    }

    found = EasySearchChr((char*)haystack, 'q');
    if (found) {
        printf("  SearchChr 'q': Found at position %ld\n", found - haystack);
    }

    found = EasyRSearchChr((char*)haystack, 'o');
    if (found) {
        printf("  RSearchChr 'o': Last occurrence at position %ld\n", found - haystack);
    }
}

void demo_string_manipulation_new(void) {
    printf("\n4. STRING MANIPULATION (New Allocation)\n");
    SEPARATOR();

    // String duplication
    const char* original = "EasyStr Library";
    char* duplicate = EasyStrDup(original);
    printf("StrDup: \"%s\" -> \"%s\"\n\n", original, duplicate);
    free(duplicate);

    // Trimming
    const char* padded = "   Hello World   ";
    char* ltrimmed = EasyLTrim(padded);
    char* rtrimmed = EasyRTrim(padded);
    char* trimmed = EasyTrim(padded);
    printf("Trimming: \"%s\"\n", padded);
    printf("  LTrim: \"%s\"\n", ltrimmed);
    printf("  RTrim: \"%s\"\n", rtrimmed);
    printf("  Trim:  \"%s\"\n\n", trimmed);
    free(ltrimmed);
    free(rtrimmed);
    free(trimmed);

    // Replace
    const char* sentence = "I love cats and cats are great!";
    char* replaced = EasyReplace(sentence, "cats", "dogs");
    printf("Replace:\n");
    printf("  Original: \"%s\"\n", sentence);
    printf("  Replaced: \"%s\"\n\n", replaced);
    free(replaced);

    // Insert
    const char* base = "Hello!";
    char* inserted = EasyInsert(base, " World", 5);
    printf("Insert:\n");
    printf("  Base: \"%s\"\n", base);
    printf("  Insert \" World\" at position 5: \"%s\"\n\n", inserted);
    free(inserted);

    // Split
    const char* csv = "apple,banana,cherry,date";
    size_t count = 0;
    char** parts = EasySplit(NULL, csv, ",", &count);
    printf("Split: \"%s\" by \",\"\n", csv);
    printf("  Parts (%zu): ", count);
    for (size_t i = 0; i < count; i++) {
        printf("\"%s\"%s", parts[i], (i < count - 1) ? ", " : "\n");
        free(parts[i]);
    }
    free(parts);
    printf("\n");

    // Join
    char* words[] = {"Easy", "Str", "Library"};
    char* joined = EasyJoin(words, 3, "-");
    printf("Join: [\"Easy\", \"Str\", \"Library\"] with \"-\"\n");
    printf("  Result: \"%s\"\n", joined);
    free(joined);
}

void demo_string_manipulation_inplace(void) {
    printf("\n5. STRING MANIPULATION (In-Place)\n");
    SEPARATOR();

    // Copy operations
    char dest[50];
    EasyCpy(dest, "Hello");
    printf("Cpy: \"%s\"\n", dest);

    EasyNCpy(dest, "Welcome to EasyStr", 7);
    dest[7] = '\0';
    printf("NCpy (7 chars): \"%s\"\n\n", dest);

    // Concatenation
    char buffer[100] = "Hello";
    EasyCat(buffer, " World");
    printf("Cat: \"%s\"\n", buffer);

    EasyNCat(buffer, "!!!!!", 2);
    printf("NCat (2 chars): \"%s\"\n\n", buffer);

    // Case transformations
    char text1[50] = "Hello World";
    char text2[50] = "Hello World";
    char text3[50] = "Hello World";
    char text4[50] = "hello world";

    printf("Case transformations on \"Hello World\":\n");
    printf("  Upper: \"%s\"\n", EasyUpper(text1));
    printf("  Lower: \"%s\"\n", EasyLower(text2));
    printf("  Swapcase: \"%s\"\n", EasySwapcase(text3));
    printf("  Capitalize: \"%s\"\n\n", EasyCapitalize(text4));

    // Reverse
    char reversible[50] = "EasyStr";
    printf("Reverse: \"%s\" -> ", reversible);
    EasyRev(reversible);
    printf("\"%s\"\n", reversible);
}