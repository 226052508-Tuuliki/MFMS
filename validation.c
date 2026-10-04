/*
 * validation.c
 * Implementation of the shared input and validation functions.
 *
 * Only basic C from the course is used here: loops, arrays, strings,
 * if/switch, functions with parameters and return values, fgets and the
 * string.h functions strlen(), strcpy() and strcmp().
 *
 * Responsibility: Student 6 (Functions, integration and validation)
 */
#include <stdio.h>
#include <stdlib.h>     /* exit() */
#include <string.h>     /* strlen(), strcpy(), strcmp() */
#include "common.h"
#include "validation.h"

/* ------------------------------------------------------------------ */
/*  Function declarations for the private helper functions            */
/* ------------------------------------------------------------------ */
int    isDigitChar(char c);
int    isLetterChar(char c);
int    isSpaceChar(char c);
char   toLowerChar(char c);
void   endOfInput(void);
int    getCleanLine(char buffer[], int size);
int    hasNumberFormat(char str[], int allowDecimal);
double convertToNumber(char str[]);
void   readValidatedText(char prompt[], char dest[], int size, int kind);

/* ------------------------------------------------------------------ */
/*  Character helpers (use ASCII comparisons, no extra library)       */
/* ------------------------------------------------------------------ */

int isDigitChar(char c)
{
    return c >= '0' && c <= '9';
}

int isLetterChar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isSpaceChar(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

char toLowerChar(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

/* ------------------------------------------------------------------ */
/*  Private helpers                                                    */
/* ------------------------------------------------------------------ */

/* Called when the keyboard input ends (Ctrl+D / Ctrl+Z): end the program
 * cleanly instead of asking the same question forever. */
void endOfInput(void)
{
    printf("\n\nInput closed. Exiting the system.\n");
    exit(0);
}

/* Reads and trims one line. Returns 1 if the line is usable, or prints an
 * error and returns 0 if the line was too long. */
int getCleanLine(char buffer[], int size)
{
    int status = readLine(buffer, size);

    if (status == 0) {
        endOfInput();
    }
    if (status < 0) {
        printf("Error: input is too long. Please try again.\n");
        return 0;
    }
    trimString(buffer);
    return 1;
}

/* Checks the FORMAT of a number typed as text: an optional + or - sign,
 * digits, and (only if allowDecimal is 1) one decimal point, with at least
 * one digit. So "abc", "12abc", "1.2.3", "1e5" and "" are all rejected.
 * Returns 1 if the format is valid, otherwise 0. */
int hasNumberFormat(char str[], int allowDecimal)
{
    int i = 0;
    int digits = 0;
    int dots = 0;

    if (str[0] == '\0') {
        return 0;
    }
    if (str[0] == '+' || str[0] == '-') {
        i = 1;
    }
    for (; str[i] != '\0'; i++) {
        if (isDigitChar(str[i])) {
            digits++;
        } else if (str[i] == '.' && allowDecimal == 1 && dots == 0) {
            dots++;
        } else {
            return 0;
        }
    }
    return digits > 0;
}

/* Converts text that already passed hasNumberFormat() into a number.
 * Each digit is added with: value = value * 10 + digit.
 * Digits after the decimal point are counted, and the result is divided
 * by 10 once for each of them at the end. */
double convertToNumber(char str[])
{
    int i = 0;
    int negative = 0;
    int afterPoint = 0;
    int decimals = 0;
    double value = 0.0;

    if (str[0] == '-') {
        negative = 1;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            afterPoint = 1;
        } else {
            value = value * 10 + (str[i] - '0');
            if (afterPoint == 1) {
                decimals++;
            }
        }
    }
    for (i = 0; i < decimals; i++) {
        value = value / 10;
    }
    if (negative == 1) {
        value = -value;
    }
    return value;
}

/* Generic "keep asking until valid" loop for text fields.
 * kind: 0 = any text, 1 = name, 2 = id, 3 = email, 4 = phone */
void readValidatedText(char prompt[], char dest[], int size, int kind)
{
    char buffer[INPUT_BUFFER_SIZE];
    int valid;
    int length;

    while (1) {
        printf("%s", prompt);
        if (!getCleanLine(buffer, INPUT_BUFFER_SIZE)) {
            continue;
        }
        if (isBlank(buffer)) {
            printf("Error: this field cannot be empty.\n");
            continue;
        }
        length = strlen(buffer);
        if (length >= size) {
            printf("Error: too long (maximum %d characters).\n", size - 1);
            continue;
        }

        switch (kind) {
            case 1:
                valid = isValidName(buffer);
                if (!valid) {
                    printf("Error: use letters, spaces, hyphens, apostrophes and dots only.\n");
                }
                break;
            case 2:
                valid = isValidId(buffer);
                if (!valid) {
                    printf("Error: use letters, digits, '-' or '_' only (no spaces).\n");
                }
                break;
            case 3:
                valid = isValidEmail(buffer);
                if (!valid) {
                    printf("Error: invalid e-mail format (example: name@example.com).\n");
                }
                break;
            case 4:
                valid = isValidPhone(buffer);
                if (!valid) {
                    printf("Error: invalid telephone number (7-15 digits, e.g. +264 61 207 2052).\n");
                }
                break;
            default:
                valid = 1;
                break;
        }

        if (valid) {
            strcpy(dest, buffer);
            return;
        }
    }
}

/* ------------------------------------------------------------------ */
/*  Low-level helpers (public)                                         */
/* ------------------------------------------------------------------ */

int readLine(char buffer[], int size)
{
    int length;
    int ch;
    int extra = 0;

    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return 0;
    }

    /* fgets keeps the newline character, so remove it. */
    length = strlen(buffer);
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
        length--;
    } else {
        /* No newline: the line was longer than the buffer. Throw away the
         * rest of the line so it is not read by the next prompt. */
        while ((ch = getchar()) != '\n' && ch != EOF) {
            extra = 1;
        }
        if (extra == 1) {
            return -1;
        }
    }
    if (length > 0 && buffer[length - 1] == '\r') {   /* Windows line ending */
        buffer[length - 1] = '\0';
    }
    return 1;
}

void trimString(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;
    int i;

    while (str[start] != '\0' && isSpaceChar(str[start])) {
        start++;
    }
    while (end >= start && isSpaceChar(str[end])) {
        end--;
    }
    /* Move the remaining characters to the front of the array. */
    for (i = 0; i <= end - start; i++) {
        str[i] = str[start + i];
    }
    str[end - start + 1] = '\0';
}

int isBlank(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (!isSpaceChar(str[i])) {
            return 0;
        }
    }
    return 1;
}

/* ------------------------------------------------------------------ */
/*  Reading numbers                                                    */
/* ------------------------------------------------------------------ */

int readInt(char prompt[], int min, int max)
{
    char buffer[INPUT_BUFFER_SIZE];
    double value;
    int result;

    while (1) {
        printf("%s", prompt);
        if (!getCleanLine(buffer, INPUT_BUFFER_SIZE)) {
            continue;
        }
        if (isBlank(buffer)) {
            printf("Error: input cannot be empty.\n");
        } else if (!hasNumberFormat(buffer, 0)) {
            printf("Error: please enter a whole number (digits only).\n");
        } else {
            value = convertToNumber(buffer);
            if (value < min || value > max) {
                printf("Error: the value must be between %d and %d.\n", min, max);
            } else {
                result = value;
                return result;
            }
        }
    }
}

double readDouble(char prompt[], double min, double max)
{
    char buffer[INPUT_BUFFER_SIZE];
    double value;

    while (1) {
        printf("%s", prompt);
        if (!getCleanLine(buffer, INPUT_BUFFER_SIZE)) {
            continue;
        }
        if (isBlank(buffer)) {
            printf("Error: input cannot be empty.\n");
        } else if (!hasNumberFormat(buffer, 1)) {
            printf("Error: please enter a valid number (e.g. 1500.50).\n");
        } else {
            value = convertToNumber(buffer);
            if (value < min) {
                printf("Error: the value cannot be less than %.2f.\n", min);
            } else if (value > max) {
                printf("Error: the value cannot be more than %.2f.\n", max);
            } else {
                return value;
            }
        }
    }
}

double readMoney(char prompt[])
{
    return readDouble(prompt, MIN_MONEY, MAX_MONEY);
}

double readPositiveMoney(char prompt[])
{
    return readDouble(prompt, 0.01, MAX_MONEY);
}

int readMenuChoice(char prompt[], int min, int max)
{
    char buffer[INPUT_BUFFER_SIZE];
    double value;
    int result;

    while (1) {
        printf("%s", prompt);
        if (!getCleanLine(buffer, INPUT_BUFFER_SIZE)) {
            continue;
        }
        if (hasNumberFormat(buffer, 0)) {
            value = convertToNumber(buffer);
            if (value >= min && value <= max) {
                result = value;
                return result;
            }
        }
        printf("Invalid choice. Please enter a number from %d to %d.\n", min, max);
    }
}

int readYesNo(char prompt[])
{
    char buffer[INPUT_BUFFER_SIZE];

    while (1) {
        printf("%s", prompt);
        if (!getCleanLine(buffer, INPUT_BUFFER_SIZE)) {
            continue;
        }
        if (strlen(buffer) == 1) {
            if (buffer[0] == 'y' || buffer[0] == 'Y') {
                return 1;
            }
            if (buffer[0] == 'n' || buffer[0] == 'N') {
                return 0;
            }
        }
        printf("Error: please enter y (yes) or n (no).\n");
    }
}

/* ------------------------------------------------------------------ */
/*  Reading text                                                       */
/* ------------------------------------------------------------------ */

void readText(char prompt[], char dest[], int size)
{
    readValidatedText(prompt, dest, size, 0);
}

void readName(char prompt[], char dest[], int size)
{
    readValidatedText(prompt, dest, size, 1);
}

void readId(char prompt[], char dest[], int size)
{
    readValidatedText(prompt, dest, size, 2);
}

void readEmail(char prompt[], char dest[], int size)
{
    readValidatedText(prompt, dest, size, 3);
}

void readPhone(char prompt[], char dest[], int size)
{
    readValidatedText(prompt, dest, size, 4);
}

/* ------------------------------------------------------------------ */
/*  Checking existing strings                                          */
/* ------------------------------------------------------------------ */

int isValidName(char str[])
{
    int i;
    int letters = 0;

    if (isBlank(str)) {
        return 0;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (isLetterChar(str[i])) {
            letters++;
        } else if (str[i] != ' ' && str[i] != '-' &&
                   str[i] != '\'' && str[i] != '.') {
            return 0;
        }
    }
    return letters > 0;
}

int isValidId(char str[])
{
    int i;

    if (str[0] == '\0') {
        return 0;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (!isLetterChar(str[i]) && !isDigitChar(str[i]) &&
            str[i] != '-' && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}

/* A valid e-mail has: exactly one '@', something before the '@', a '.'
 * after the '@' that is not right next to it and not the last character,
 * no spaces and no two dots in a row. */
int isValidEmail(char str[])
{
    int i;
    int length = strlen(str);
    int atCount = 0;
    int atPosition = -1;
    int lastDot = -1;

    if (length < 5) {                      /* shortest valid: a@b.c */
        return 0;
    }
    for (i = 0; i < length; i++) {
        if (isSpaceChar(str[i])) {
            return 0;
        }
        if (str[i] == '@') {
            atCount++;
            atPosition = i;
        }
        if (str[i] == '.') {
            if (i > 0 && str[i - 1] == '.') {
                return 0;
            }
            lastDot = i;
        }
    }
    if (atCount != 1 || atPosition == 0) {
        return 0;
    }
    if (lastDot < atPosition + 2) {        /* no dot, or dot too close to '@' */
        return 0;
    }
    if (lastDot == length - 1) {           /* nothing after the last dot */
        return 0;
    }
    return 1;
}

int isValidPhone(char str[])
{
    int i;
    int digits = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (isDigitChar(str[i])) {
            digits++;
        } else if (str[i] == '+' && i == 0) {
            /* '+' is only allowed as the first character */
        } else if (str[i] != ' ' && str[i] != '-' &&
                   str[i] != '(' && str[i] != ')') {
            return 0;
        }
    }
    return digits >= 7 && digits <= 15;
}

/* ------------------------------------------------------------------ */
/*  String helpers for searching                                       */
/* ------------------------------------------------------------------ */

void toLowerCase(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toLowerChar(str[i]);
    }
}

/* Copies both strings (strcpy), converts the copies to lower case and
 * compares them with strcmp(). The originals are not changed. */
int equalsIgnoreCase(char a[], char b[])
{
    char first[INPUT_BUFFER_SIZE];
    char second[INPUT_BUFFER_SIZE];

    if (strlen(a) >= INPUT_BUFFER_SIZE || strlen(b) >= INPUT_BUFFER_SIZE) {
        return 0;
    }
    strcpy(first, a);
    strcpy(second, b);
    toLowerCase(first);
    toLowerCase(second);

    return strcmp(first, second) == 0;
}

/* Checks every possible starting position of "search" inside "text". */
int containsIgnoreCase(char text[], char search[])
{
    int textLength = strlen(text);
    int searchLength = strlen(search);
    int i;
    int j;

    if (searchLength == 0) {
        return 0;               /* an empty search matches nothing */
    }
    for (i = 0; i + searchLength <= textLength; i++) {
        for (j = 0; j < searchLength; j++) {
            if (toLowerChar(text[i + j]) != toLowerChar(search[j])) {
                break;
            }
        }
        if (j == searchLength) {
            return 1;
        }
    }
    return 0;
}

/* ------------------------------------------------------------------ */
/*  Screen helpers                                                     */
/* ------------------------------------------------------------------ */

void printDivider(char ch, int length)
{
    int i;

    for (i = 0; i < length; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

void printHeader(char title[])
{
    printf("\n");
    printDivider('=', 40);
    printf("%s\n", title);
    printDivider('=', 40);
}

void pauseScreen(void)
{
    char buffer[INPUT_BUFFER_SIZE];

    printf("\nPress Enter to continue...");
    if (readLine(buffer, INPUT_BUFFER_SIZE) == 0) {
        endOfInput();
    }
}
