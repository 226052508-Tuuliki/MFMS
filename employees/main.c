#include <stdio.h>
#include "employees.h"

void displaySystemHeader(void);
void displayMainMenu(void);
int readMenuChoice(void);
void handleEmployeeManagement(void);
void displayPlaceholder(const char *moduleName);

int main(void)
{
    int choice;
    int running = 1;

    displaySystemHeader();

    while (running)
    {
        displayMainMenu();
        choice = readMenuChoice();

        switch (choice)
        {
            case 1:
                handleEmployeeManagement();
                break;

            case 2:
                displayPlaceholder("BUDGET MANAGEMENT");
                break;

            case 3:
                displayPlaceholder("SUPPLIER MANAGEMENT");
                break;

            case 4:
                displayPlaceholder("ASSET MANAGEMENT");
                break;

            case 5:
                displayPlaceholder("REPORTS");
                break;

            case 6:
                printf("\n");
                printf("================================================\n");
                printf("  Thank you for using the MFMS.                 \n");
                printf("  Windhoek Municipality - Goodbye!              \n");
                printf("================================================\n");
                running = 0;
                break;

            default:
                printf("\n");
                printf("  *** ERROR: Invalid choice '%d' ***\n", choice);
                printf("  Please enter a number between 1 and 6.\n");
                break;
        }
    }

    return 0;
}

void displaySystemHeader(void)
{
    printf("\n");
    printf("################################################\n");
    printf("#                                              #\n");
    printf("#   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM      #\n");
    printf("#              (MFMS) v1.0                     #\n");
    printf("#                                              #\n");
    printf("#   Windhoek Municipality                      #\n");
    printf("#   Republic of Namibia                        #\n");
    printf("#                                              #\n");
    printf("################################################\n");
    printf("\n");
    printf("  PAP521S - Programming in Practice\n");
    printf("  Project A: Foundation System\n");
}

void displayMainMenu(void)
{
    printf("\n");
    printf("================================================\n");
    printf("                  MAIN MENU                     \n");
    printf("================================================\n");
    printf("                                                \n");
    printf("   1.  Employee Management                      \n");
    printf("   2.  Budget Management                        \n");
    printf("   3.  Supplier Management                      \n");
    printf("   4.  Asset Management                         \n");
    printf("   5.  Reports                                  \n");
    printf("   6.  Exit                                     \n");
    printf("                                                \n");
    printf("================================================\n");
    printf("   Enter your choice (1-6): ");
}

int readMenuChoice(void)
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

void handleEmployeeManagement(void)
{
    int empChoice;
    int inEmployeeMenu = 1;

    while (inEmployeeMenu)
    {
        displayEmployeeMenu();
        scanf("%d", &empChoice);

        switch (empChoice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                calculateEmployeeSalary();
                break;
            case 5:
                displaySalarySummary();
                break;
            case 6:
                inEmployeeMenu = 0;
                printf("\n  Returning to main menu...\n");
                break;
            default:
                printf("\n  *** Invalid choice. Please enter 1-6. ***\n");
                break;
        }
    }
}

void displayPlaceholder(const char *moduleName)
{
    printf("\n");
    printf("================================================\n");
    printf("  %s\n", moduleName);
    printf("================================================\n");
    printf("                                                \n");
    printf("  This module is being developed by another     \n");
    printf("  team member and will be integrated soon.      \n");
    printf("                                                \n");
    printf("================================================\n");
}
