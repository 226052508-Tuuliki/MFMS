/*
 * validation.h
 * Input reading and validation functions shared by ALL modules.
 *
 * RULE FOR THE TEAM: do not use scanf() for user input in the project.
 * Use the functions below instead. They keep asking until the user enters
 * valid data, they never leave stray characters in the input buffer and
 * they never crash when letters are typed where a number is expected.
 *
 * Responsibility: Student 6 (Functions, integration and validation)
 */
#ifndef VALIDATION_H
#define VALIDATION_H

#define INPUT_BUFFER_SIZE 256

/* ---------- Low-level helpers ---------- */

/* Reads one line from the keyboard into buffer using fgets (newline removed).
 * Returns  1 = OK, 0 = end of input (Ctrl+D / Ctrl+Z), -1 = line too long. */
int  readLine(char buffer[], int size);

/* Removes leading and trailing spaces/tabs from str (in place). */
void trimString(char str[]);

/* Returns 1 if str is empty or contains only spaces/tabs, otherwise 0. */
int  isBlank(char str[]);

/* ---------- Reading numbers (re-prompts until valid) ---------- */

/* Whole number between min and max (inclusive). Returns the number. */
int    readInt(char prompt[], int min, int max);

/* Decimal number between min and max (inclusive). Returns the number. */
double readDouble(char prompt[], double min, double max);

/* Amount of money in N$: 0 up to MAX_MONEY (negative values rejected). */
double readMoney(char prompt[]);

/* Amount of money in N$: greater than 0 up to MAX_MONEY (use for salaries). */
double readPositiveMoney(char prompt[]);

/* Menu choice between min and max, with a menu-specific error message. */
int    readMenuChoice(char prompt[], int min, int max);

/* Asks a yes/no question. Returns 1 for yes (y/Y), 0 for no (n/N). */
int    readYesNo(char prompt[]);

/* ---------- Reading text (re-prompts until valid) ---------- */
/* "size" is the size of the destination array: pass sizeof name or MAX_NAME_LEN.
 * The validated text is copied into dest with strcpy(). */

/* Any non-empty text (department names, asset names, towns, etc.). */
void readText(char prompt[], char dest[], int size);

/* Person name: letters, spaces, hyphens, apostrophes and dots only. */
void readName(char prompt[], char dest[], int size);

/* ID code: letters, digits, '-' and '_' only, no spaces (e.g. EMP001). */
void readId(char prompt[], char dest[], int size);

/* E-mail address in a valid format (e.g. name@example.com). */
void readEmail(char prompt[], char dest[], int size);

/* Telephone number: digits, spaces, '-', '(', ')' and a leading '+'; 7-15 digits. */
void readPhone(char prompt[], char dest[], int size);

/* ---------- Checking existing strings (return 1 = valid, 0 = invalid) ---------- */
int isValidName(char str[]);
int isValidId(char str[]);
int isValidEmail(char str[]);
int isValidPhone(char str[]);

/* ---------- String helpers for searching ---------- */

/* Converts str to lower case (in place). */
void toLowerCase(char str[]);

/* Returns 1 if a and b are equal ignoring upper/lower case, otherwise 0. */
int  equalsIgnoreCase(char a[], char b[]);

/* Returns 1 if text contains search (ignoring case), otherwise 0.
 * Use for "search by part of a name". */
int  containsIgnoreCase(char text[], char search[]);

/* ---------- Screen helpers (consistent look across modules) ---------- */

/* Prints a title between two lines of '=' characters. */
void printHeader(char title[]);

/* Prints a line of 'ch' repeated 'length' times followed by a newline. */
void printDivider(char ch, int length);

/* Waits for the user to press Enter. */
void pauseScreen(void);

#endif /* VALIDATION_H */
