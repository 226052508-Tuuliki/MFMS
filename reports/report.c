
#include <stdio.h>
#include "reports.h"
#include "validation.h"


extern char employeeIDs[][20];
extern char employeeNames[][50];
extern char employeeDepartments[][50];
extern double employeeBasicSalaries[];
extern double employeeHousingAllowances[];
extern double employeeTransportAllowances[];
int getEmployeeCount(void);               

extern struct Budget budgets[];
extern int budgetCount;

extern int supplierID[];
extern char supplierName[][100];
extern char email[][50];
extern char telephoneNumber[][20];        
extern char Town[][50];
extern int supplierCount;                

extern int assetID[];
extern char assetName[][50];
extern char typeOfAsset[][50];
extern float valueOfPurchase[];
extern char department[][50];
extern char conditionOfAsset[][50];
extern int assetCount;


void employeeReport(char ids[][20], char names[][50], char departments[][50],
                    double basic[], double housing[], double transport[],
                    int count)
{
    int i;
    int highestIndex = 0;
    int lowestIndex = 0;
    double totalSalary = 0.0;
    double averageSalary;
    double highestSalary;
    double lowestSalary;
    double gross;

    printf("\n");
    printDivider('=', 50);
    printf("              EMPLOYEE REPORT\n");
    printDivider('=', 50);

    if (count == 0) {
        printf("No employees registered.\n");
        return;
    }

  
    gross = basic[0] + housing[0] + transport[0];
    highestSalary = gross;
    lowestSalary  = gross;

    for (i = 0; i < count; i++) {
        gross = basic[i] + housing[i] + transport[i];
        totalSalary += gross;

        if (gross > highestSalary) {
            highestSalary = gross;
            highestIndex = i;
        }
        if (gross < lowestSalary) {
            lowestSalary = gross;
            lowestIndex = i;
        }
    }

    averageSalary = totalSalary / count;

    printf("Total Employees      : %d\n", count);
    printf("Total Salary Bill    : N$ %.2f\n", totalSalary);
    printf("Average Salary       : N$ %.2f\n", averageSalary);
    printf("Highest Salary       : N$ %.2f\n", highestSalary);
    printf("  Employee           : %s (ID: %s, %s)\n",
           names[highestIndex], ids[highestIndex], departments[highestIndex]);
    printf("Lowest Salary        : N$ %.2f\n", lowestSalary);
    printf("  Employee           : %s (ID: %s, %s)\n",
           names[lowestIndex], ids[lowestIndex], departments[lowestIndex]);
    printDivider('-', 50);
}

void budgetReport(struct Budget list[], int count)
{
    int i;
    int exceeded = 0;
    double totalAllocated = 0.0;
    double totalSpent = 0.0;

    printf("\n");
    printDivider('=', 50);
    printf("               BUDGET REPORT\n");
    printDivider('=', 50);

    if (count == 0) {
        printf("No budgets entered.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        totalAllocated += list[i].allocatedBudget;
        totalSpent     += list[i].expenditure;
    }

    printf("Total allocated budget : N$ %.2f\n", totalAllocated);
    printf("Total expenditure      : N$ %.2f\n", totalSpent);
    printf("Remaining budget       : N$ %.2f\n", totalAllocated - totalSpent);

    printf("\nDepartments exceeding budget:\n");
    for (i = 0; i < count; i++) {
        if (list[i].expenditure > list[i].allocatedBudget) {
            printf("  %-25s over by N$ %.2f\n",
                   list[i].departmentName,
                   list[i].expenditure - list[i].allocatedBudget);
            exceeded++;
        }
    }

    if (exceeded == 0) {
        printf("  None – all departments are within budget.\n");
    }
    printDivider('-', 50);
}

void supplierReport(int ids[], char names[][100], char emails[][50],
                    char phones[][20], char towns[][50], int count)
{
    int i;

    printf("\n");
    printDivider('=', 50);
    printf("              SUPPLIER REPORT\n");
    printDivider('=', 50);

    if (count == 0) {
        printf("No suppliers registered.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nSupplier %d\n", i + 1);
        printf("  ID        : %d\n", ids[i]);
        printf("  Name      : %s\n", names[i]);
        printf("  Email     : %s\n", emails[i]);
        printf("  Telephone : %s\n", phones[i]);
        printf("  Town      : %s\n", towns[i]);
    }

    printf("\nTotal suppliers: %d\n", count);
    printDivider('-', 50);
}

void assetReport(int ids[], char names[][50], char types[][50],
                 float values[], char departments[][50],
                 char conditions[][50], int count)
{
    int i;
    double totalValue = 0.0;

    printf("\n");
    printDivider('=', 50);
    printf("               ASSET REPORT\n");
    printDivider('=', 50);

    if (count == 0) {
        printf("No assets registered.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nAsset %d\n", i + 1);
        printf("  Asset ID       : %d\n", ids[i]);
        printf("  Asset Name     : %s\n", names[i]);
        printf("  Type           : %s\n", types[i]);
        printf("  Purchase Value : N$ %.2f\n", values[i]);
        printf("  Department     : %s\n", departments[i]);
        printf("  Condition      : %s\n", conditions[i]);

        totalValue += values[i];
    }

    printf("\nTotal assets registered : %d\n", count);
    printf("Total value of assets   : N$ %.2f\n", totalValue);
    printDivider('-', 50);
}

void displayReports(void)
{
    int choice;

    do {
        printf("\n");
        printDivider('=', 40);
        printf("              REPORTS\n");
        printDivider('=', 40);
        printf("  1. Employee Report\n");
        printf("  2. Budget Report\n");
        printf("  3. Supplier Report\n");
        printf("  4. Asset Report\n");
        printf("  5. Return to Main Menu\n");
        printDivider('=', 40);

        choice = readMenuChoice("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1:
                employeeReport(employeeIDs, employeeNames, employeeDepartments,
                               employeeBasicSalaries, employeeHousingAllowances,
                               employeeTransportAllowances, getEmployeeCount());
                break;

            case 2:
                budgetReport(budgets, budgetCount);
                break;

            case 3:
                supplierReport(supplierID, supplierName, email,
                               telephoneNumber, Town, supplierCount);
                break;

            case 4:
                assetReport(assetID, assetName, typeOfAsset, valueOfPurchase,
                            department, conditionOfAsset, assetCount);
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;
        }
    } while (choice != 5);
}
