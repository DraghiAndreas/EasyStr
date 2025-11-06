# EasyStr Library Documentation

This document provides API documentation for the `EasyStr` C library, a utility library for common string manipulation tasks.

---

## 1. Character Validation

These functions check a single character against a specific condition.

### `EasyIsAlphaChr(const unsigned char c)`
Checks if a character is an alphabetic letter (a-z or A-Z).
* **Parameters:**
    * `c`: The character to check.
* **Returns:** `1` (true) if the character is alphabetic, `0` (false) otherwise.

### `EasyIsDigitChr(const unsigned char c)`
Checks if a character is a numeric digit (0-9).
* **Parameters:**
    * `c`: The character to check.
* **Returns:** `1` (true) if the character is a digit, `0` (false) otherwise.

### `EasyIsAlnumChr(const unsigned char c)`
Checks if a character is alphanumeric (a-z, A-Z, or 0-9).
* **Parameters:**
    * `c`: The character to check.
* **Returns:** `1` (true) if the character is alphanumeric, `0` (false) otherwise.

### `EasyIsUpperChr(const unsigned char c)`
Checks if a character is an uppercase letter (A-Z).
* **Parameters:**
    * `c`: The character to check.
* **Returns:** `1` (true) if the character is uppercase, `0` (false) otherwise.

### `EasyIsLowerChr(const unsigned char c)`
Checks if a character is a lowercase letter (a-z).
* **Parameters:**
    * `c`: The character to check.
* **Returns:** `1` (true) if the character is lowercase, `0` (false) otherwise.

### `EasyIsSpaceChr(const unsigned char c)`
Checks if a character is a space (`' '`).
* **Parameters:**
    * `c`: The character to check.
* **Returns:** `1` (true) if the character is a space, `0` (false) otherwise.

---

## 2. String Validation

These functions check if **all** characters in a string match a specific condition.

### `EasyIsAlphaStr(const char * c)`
Checks if a string contains only alphabetic letters.
* **Parameters:**
    * `c`: The null-terminated string to check.
* **Returns:** `1` (true) if the entire string is alphabetic, `0` (false) otherwise.

### `EasyIsDigitStr(const char * c)`
Checks if a string contains only numeric digits.
* **Parameters:**
    * `c`: The null-terminated string to check.
* **Returns:** `1` (true) if the entire string is numeric, `0` (false) otherwise.

### `EasyIsAlnumStr(const char * c)`
Checks if a string contains only alphanumeric characters.
* **Parameters:**
    * `c`: The null-terminated string to check.
* **Returns:** `1` (true) if the entire string is alphanumeric, `0` (false) otherwise.

### `EasyIsUpperStr(const char * c)`
Checks if a string contains only uppercase letters.
* **Parameters:**
    * `c`: The null-terminated string to check.
* **Returns:** `1` (true) if the entire string is uppercase, `0` (false) otherwise.

### `EasyIsLowerStr(const char * c)`
Checks if a string contains only lowercase letters.
* **Parameters:**
    * `c`: The null-terminated string to check.
* **Returns:** `1` (true) if the entire string is lowercase, `0` (false) otherwise.

### `EasyIsSpaceStr(const char * c)`
Checks if a string contains only space characters.
* **Parameters:**
    * `c`: The null-terminated string to check.
* **Returns:** `1` (true) if the entire string is spaces, `0` (false) otherwise.

---

## 3. String Comparison & Inspection

Functions for comparing strings and getting their properties.

### `EasyLen(const char* string)`
Calculates the length of a string (excluding the null terminator).
* **Parameters:**
    * `string`: The null-terminated string.
* **Returns:** The length (`size_t`) of the string. Returns `0` if the string is `NULL` or empty.

### `EasyCmp(const char* string1, const char* string2)`
Compares two strings for exact equality.
* **Parameters:**
    * `string1`: The first null-terminated string.
    * `string2`: The second null-terminated string.
* **Returns:** `1` (true) if the strings are identical, `0` (false) otherwise. Returns `0` if either string is `NULL`.

### `EasyNCmp(const char* string1, const char* string2, int n)`
Compares the first `n` characters of two strings for equality.
* **Parameters:**
    * `string1`: The first null-terminated string.
    * `string2`: The second null-terminated string.
    * `n`: The number of characters to compare.
* **Returns:** `1` (true) if the first `n` characters are identical, `0` (false) otherwise. Returns `0` if either string is `NULL` or `n <= 0`.

### `EasyStartsWith(const char * string, const char * prefix)`
Checks if a string begins with a specified prefix.
* **Parameters:**
    * `string`: The string to check.
    * `prefix`: The prefix to look for.
* **Returns:** `1` (true) if `string` starts with `prefix`, `0` (false) otherwise.

### `EasyEndsWith(const char * string, const char * suffix)`
Checks if a string ends with a specified suffix.
* **Parameters:**
    * `string`: The string to check.
    * `suffix`: The suffix to look for.
* **Returns:** `1` (true) if `string` ends with `suffix`, `0` (false) otherwise. Returns `1` if `suffix` is empty.

---

## 4. String Counting

Functions for counting occurrences within a string.

### `EasyCount(const char* string, const char c)`
Counts the number of occurrences of a specific character in a string.
* **Parameters:**
    * `string`: The string to search in.
    * `c`: The character to count.
* **Returns:** The total number (`size_t`) of times `c` appears in `string`.

### `EasyStrCount(const char* string, const char* c)`
Counts the number of non-overlapping occurrences of a substring in a string.
* **Parameters:**
    * `string`: The string to search in.
    * `c`: The null-terminated substring to count.
* **Returns:** The total number (`size_t`) of times `c` appears in `string`.

---

## 5. String Searching

Functions for finding characters or substrings.

### `EasySearchChr(char *string, const char c)`
Finds the **first** occurrence of a character in a string.
* **Parameters:**
    * `string`: The string to search in.
    * `c`: The character to find.
* **Returns:** A pointer to the first occurrence of `c` in `string`, or `NULL` if not found.

### `EasyRSearchChr(char *string, const char c)`
Finds the **last** occurrence of a character in a string.
* **Parameters:**
    * `string`: The string to search in.
    * `c`: The character to find.
* **Returns:** A pointer to the last occurrence of `c` in `string`, or `NULL` if not found.

### `EasySearchStr(const char* string, const char* c)`
Finds the **first** occurrence of a substring in a string.
* **Parameters:**
    * `string`: The string to search in.
    * `c`: The null-terminated substring to find.
* **Returns:** A pointer to the beginning of the first occurrence of `c` in `string`, or `NULL` if not found.

### `EasyRSearchStr(const char* string, const char* c)`
Finds the **last** occurrence of a substring in a string.
* **Parameters:**
    * `string`: The string to search in.
    * `c`: The null-terminated substring to find.
* **Returns:** A pointer to the beginning of the last occurrence of `c` in `string`, or `NULL` if not found.

---

## 6. Memory, Copying, & Concatenation

Functions for allocating, copying, and joining strings.

### `EasyStrDup(const char * string)`
Duplicates a string by allocating new memory.
* **Parameters:**
    * `string`: The null-terminated string to duplicate.
* **Returns:** A pointer to a new, heap-allocated string identical to `string`. Returns `NULL` on allocation failure or if `string` is `NULL`. **The caller is responsible for `free()`ing this memory.**

### `EasyCpy(char* destination, const char* source)`
Copies a source string into a destination buffer (like `strcpy`).
* **Parameters:**
    * `destination`: Pointer to the destination buffer.
    * `source`: Pointer to the source string.
* **Returns:** A pointer to `destination`.

### `EasyNCpy(char* destination, const char* source, size_t n)`
Copies at most `n` characters from a source string into a destination buffer (like `strncpy`). If `source` is shorter than `n`, the remainder of `destination` up to `n` bytes is padded with `\0`.
* **Parameters:**
    * `destination`: Pointer to the destination buffer.
    * `source`: Pointer to the source string.
    * `n`: The maximum number of characters to copy.
* **Returns:** A pointer to `destination`.

### `EasyCat(char* destination, const char* source)`
Appends a source string to the end of a destination string (like `strcat`).
* **Parameters:**
    * `destination`: The destination string, which must have enough space.
    * `source`: The source string to append.
* **Returns:** A pointer to `destination`.

### `EasyNCat(char* destination, const char* source, size_t n)`
Appends at most `n` characters from a source string to a destination string (like `strncat`). A null terminator is always appended.
* **Parameters:**
    * `destination`: The destination string, which must have enough space.
    * `source`: The source string to append.
    * `n`: The maximum number of characters to append from `source`.
* **Returns:** A pointer to `destination`.

---

## 7. String Manipulation (New Memory)

These functions return a **new** heap-allocated string. The caller is responsible for `free()`ing the returned pointer.

### `EasyLTrim(const char * string)`
Removes leading whitespace from a string.
* **Parameters:**
    * `string`: The string to trim.
* **Returns:** A new, heap-allocated string with leading spaces removed. **Caller must `free()` this memory.**

### `EasyRTrim(const char * string)`
Removes trailing whitespace from a string.
* **Parameters:**
    * `string`: The string to trim.
* **Returns:** A new, heap-allocated string with trailing spaces removed. **Caller must `free()` this memory.**

### `EasyTrim(const char * string)`
Removes both leading and trailing whitespace from a string.
* **Parameters:**
    * `string`: The string to trim.
* **Returns:** A new, heap-allocated string with leading and trailing spaces removed. **Caller must `free()` this memory.**

### `EasyInsert(const char* destination, const char* source, size_t location)`
Inserts a source string into a destination string at a specific location.
* **Parameters:**
    * `destination`: The original string.
    * `source`: The string to insert.
    * `location`: The byte offset (index) in `destination` where `source` will be inserted.
* **Returns:** A new, heap-allocated string containing the result. **Caller must `free()` this memory.**

### `EasyReplace(const char * string, const char * old, const char * new)`
Replaces all occurrences of a substring with a new substring.
* **Parameters:**
    * `string`: The original string.
    * `old`: The substring to be replaced.
    * `new`: The substring to replace with.
* **Returns:** A new, heap-allocated string with all replacements made. If `old` is not found, returns a duplicate of the original `string`. **Caller must `free()` this memory.**

### `EasySplit(char** newArr, const char* source, const char* sep, size_t* wordCounter)`
Splits a string into an array of strings based on a separator.
* **Note:** This function is complex. It re-allocates `newArr` as it finds new words.
* **Parameters:**
    * `newArr`: A pointer to a `char**` (string array). Can be `NULL` initially.
    * `source`: The string to split.
    * `sep`: The separator string.
    * `wordCounter`: A pointer to a `size_t` which will be updated with the number of words found.
* **Returns:** A `char**` (array of strings) containing the split parts. The array and all strings within it are heap-allocated. **The caller is responsible for `free()`ing each string in the array, and then `free()`ing the array itself.**

### `EasyJoin(char ** strings, size_t count, char * sep)`
Joins an array of strings into a single string, separated by a separator.
* **Parameters:**
    * `strings`: The array of null-terminated strings.
    * `count`: The number of strings in the `strings` array.
    * `sep`: The separator string to insert between each element.
* **Returns:** A new, heap-allocated string containing the joined result. `NULL` strings in the input array are skipped. **Caller must `free()` this memory.**

---

## 8. String Manipulation (In-Place)

These functions modify the string passed to them directly.

### `EasyLower(char* dest)`
Converts an entire string to lowercase, in-place.
* **Parameters:**
    * `dest`: The string to modify.
* **Returns:** A pointer to `dest`.

### `EasyUpper(char* dest)`
Converts an entire string to uppercase, in-place.
* **Parameters:**
    * `dest`: The string to modify.
* **Returns:** A pointer to `dest`.

### `EasySwapcase(char* dest)`
Swaps the case of all alphabetic characters in a string, in-place (e.g., 'a' becomes 'A', 'B' becomes 'b').
* **Parameters:**
    * `dest`: The string to modify.
* **Returns:** A pointer to `dest`.

### `EasyCapitalize(char* dest)`
Capitalizes the first letter of the string and converts the rest to lowercase, in-place.
* **Parameters:**
    * `dest`: The string to modify.
* **Returns:** A pointer to `dest`.

### `EasyRev(char* string)`
Reverses a string, in-place.
* **Parameters:**
    * `string`: The string to reverse.
* **Returns:** A pointer to `string`.