/*
 * main.c
 * Entry point and integration of the Municipal Financial Management
 * System (MFMS). main() only shows the menu and passes control to the
 * module that the user selects - all real work happens in the modules.
 *
 * Responsibility: Student 6 (Functions, integration and validation)
 */
#include <stdio.h>
#include "common.h"
#include "validation.h"
#include "employees/employees.h"
#include "budget/budget.h"
#include "supplier/suppliers.h"
#include "assets/assets.h"
#include "reports/reports.h"

void displayMenu(void);
void runMenuOption(int choice);

int main(void)
{
    int choice;

    do {
        displayMenu();
        choice = readMenuChoice("Enter your choice: ", MENU_EMPLOYEES, MENU_EXIT);
        runMenuOption(choice);
    } while (choice != MENU_EXIT);

    return 0;
}

/* Prints the main menu. */
void displayMenu(void)
{
    printf("\n");
    printDivider('=', 40);
    printf("Welcome to Windhoek Municipality\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printDivider('=', 40);
    printf("%d. Employee Management\n", MENU_EMPLOYEES);
    printf("%d. Budget Management\n",   MENU_BUDGET);
    printf("%d. Supplier Management\n", MENU_SUPPLIERS);
    printf("%d. Asset Management\n",    MENU_ASSETS);
    printf("%d. Reports\n",             MENU_REPORTS);
    printf("%d. Exit\n",                MENU_EXIT);
    printDivider('-', 40);
}

/* Sends the user to the module that matches the menu choice. */
void runMenuOption(int choice)
{
    switch (choice) {
        case MENU_EMPLOYEES:
            employeeMenu();
            break;
        case MENU_BUDGET:
            budgetMenu(budgets, &budgetCount);
            break;
        case MENU_SUPPLIERS:
            supplierMenu();
            break;
        case MENU_ASSETS:
            assetmanagement();
            break;
        case MENU_REPORTS:
            displayReports();
            break;
        case MENU_EXIT:
            printf("\nThank you for using the MFMS. Goodbye!\n");
            break;
        default:
            /* Cannot happen because readMenuChoice() validates the range,
             * but kept as a safety net. */
            printf("Invalid choice.\n");
            break;
    }
}
