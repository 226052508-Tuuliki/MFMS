#include <stdio.h>
#include "reports.h"
#include "../validation.h"
#include "../employees/employees.h"
#include "../supplier/suppliers.h"
#include "../assets/assets.h"


void supplierReport(int ids[], char names[][100], char emails[][50],
                    char phones[][20], char towns[][50], int count)
{
    int i;

    printf("\n===== SUPPLIER REPORT =====\n");

    if (count == 0)
    {
        printf("No suppliers registered.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("ID: %d\n", ids[i]);
        printf("Name: %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Telephone: %s\n", phones[i]);
        printf("Town: %s\n", towns[i]);
    }

    printf("\nTotal suppliers: %d\n", count);
}


void assetReport(int ids[], char names[][50], char types[][50],
                 float values[], char departments[][50],
                 char conditions[][50], int count)
{
    int i;
    double totalValue = 0.0;

    printf("\n===== ASSET REPORT =====\n");

    if (count == 0)
    {
        printf("No assets registered.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("Asset ID: %d\n", ids[i]);
        printf("Asset Name: %s\n", names[i]);
        printf("Type of Asset: %s\n", types[i]);
        printf("Value of Purchase: N$%.2f\n", values[i]);
        printf("Department: %s\n", departments[i]);
        printf("Condition: %s\n", conditions[i]);

        totalValue += values[i];
    }

    printf("\nTotal assets registered: %d\n", count);
    printf("Total value of assets: N$%.2f\n", totalValue);
}


void employeeReport(char ids[][20], char names[][50], char departments[][50],
                    double basic[], double housing[], double transport[],
                    int count)
{
    int i;
    double totalSalary = 0.0;
    double averageSalary;
    double highestSalary, lowestSalary;
    double gross;
    int highestIndex = 0;
    int lowestIndex = 0;

    printf("\n===== EMPLOYEE REPORT =====\n");

    if (count == 0)
    {
        printf("No employees registered.\n");
        return;
    }

    gross = basic[0] + housing[0] + transport[0];
    highestSalary = gross;
    lowestSalary = gross;

    for (i = 0; i < count; i++)
    {
        gross = basic[i] + housing[i] + transport[i];
        totalSalary = totalSalary + gross;

        if (gross > highestSalary)
        {
            highestSalary = gross;
            highestIndex = i;
        }
        if (gross < lowestSalary)
        {
            lowestSalary = gross;
            lowestIndex = i;
        }
    }

    averageSalary = totalSalary / count;

    printf("Total Employees: %d\n", count);
    printf("Total Salary Bill: N$%.2f\n", totalSalary);
    printf("Average Salary: N$%.2f\n", averageSalary);
    printf("Highest Salary: N$%.2f (%s, ID %s, %s)\n", highestSalary,
           names[highestIndex], ids[highestIndex], departments[highestIndex]);
    printf("Lowest Salary: N$%.2f (%s, ID %s, %s)\n", lowestSalary,
           names[lowestIndex], ids[lowestIndex], departments[lowestIndex]);
}


void budgetReport(struct Budget list[], int count)
{
    int i;
    int exceeded = 0;
    double totalAllocated = 0.0;
    double totalSpent = 0.0;

    printf("\n===== BUDGET REPORT =====\n");

    if (count == 0)
    {
        printf("No budgets entered.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        totalAllocated = totalAllocated + list[i].allocatedBudget;
        totalSpent = totalSpent + list[i].expenditure;
    }

    printf("Total allocated budget: N$%.2f\n", totalAllocated);
    printf("Total expenditure: N$%.2f\n", totalSpent);
    printf("Remaining budget: N$%.2f\n", totalAllocated - totalSpent);

    printf("\nDepartments exceeding budget:\n");
    for (i = 0; i < count; i++)
    {
        if (list[i].expenditure > list[i].allocatedBudget)
        {
            printf("  %s - over by N$%.2f\n", list[i].departmentName,
                   list[i].expenditure - list[i].allocatedBudget);
            exceeded++;
        }
    }

    if (exceeded == 0)
    {
        printf("  None - all departments are within budget.\n");
    }
}


/* Reports sub-menu: runs until the user chooses "Return to Main Menu".
 * Added during integration so the root main.c can call it. */
void displayReports(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("                REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        choice = readMenuChoice("", 1, 5);

        switch (choice)
        {
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
