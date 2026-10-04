/*
 * common.h
 * Shared constants for the Municipal Financial Management System (MFMS).
 * Every module (.c file) should include this header and use these
 * constants for array sizes, so the whole team uses the same limits.
 *
 * Responsibility: Student 6 (Functions, integration and validation)
 */
#ifndef COMMON_H
#define COMMON_H

/* ---- Maximum number of records per module ---- */
#define MAX_EMPLOYEES    100
#define MAX_DEPARTMENTS   20
#define MAX_SUPPLIERS    100
#define MAX_ASSETS       200

/* ---- Maximum string sizes (INCLUDING the '\0' terminator) ---- */
#define MAX_ID_LEN        15
#define MAX_NAME_LEN      50
#define MAX_DEPT_LEN      40
#define MAX_EMAIL_LEN     60
#define MAX_PHONE_LEN     20
#define MAX_TOWN_LEN      40
#define MAX_TYPE_LEN      30
#define MAX_CONDITION_LEN 20

/* ---- Money limits (N$) ---- */
#define MAX_MONEY 1000000000.0   /* N$1 billion upper limit */
#define MIN_MONEY 0.0

/* ---- Main menu option numbers ---- */
#define MENU_EMPLOYEES 1
#define MENU_BUDGET    2
#define MENU_SUPPLIERS 3
#define MENU_ASSETS    4
#define MENU_REPORTS   5
#define MENU_EXIT      6

#endif /* COMMON_H */
