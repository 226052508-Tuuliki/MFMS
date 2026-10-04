/*
 * common.h
 * Shared constants for the Municipal Financial Management System (MFMS).
 * Each module keeps its own array sizes in its own header; this file only
 * holds what validation.c and main.c share.
 *
 * Responsibility: Student 6 (Functions, integration and validation)
 */
#ifndef COMMON_H
#define COMMON_H

/* ---- Money limits (N$) used by readMoney() / readPositiveMoney() ---- */
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
