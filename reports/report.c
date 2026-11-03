#include <stdio.h>
#include "report.h"
#include "../validation.h"

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"



void employeeReport()
{
    printf("\n");
    printf("-------------------------");
    printf("EMPLOYEE REPORT\n");
    printf("-------------------------");

    displaySalarySummary();
}



void budgetReport()
{
    int i;
    int exceeded = 0;
    double totalAllocated = 0.0;
    double totalSpent = 0.0;

    printf("\n");
    printf("-------------");
    printf("BUDGET REPORT\n");
    printf("-----------------");

    if (budgetCount == 0)
    {
        printf("No budget was entered.\n");
        return;
    }

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalSpent += budgets[i].expenditure;
    }

    printf("Total allocated budget : N$ %.2f\n", totalAllocated);
    printf("Total expenditure      : N$ %.2f\n", totalSpent);
    printf("Remaining budget       : N$ %.2f\n",
           totalAllocated - totalSpent);

    printf("\nDepartments exceeding budget:\n");

    for (i = 0; i < budgetCount; i++)
    {
        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            printf("  %-25s over by N$ %.2f\n",
                   budgets[i].departmentName,
                   budgets[i].expenditure - budgets[i].allocatedBudget);

            exceeded++;
        }
    }

    if (exceeded == 0)
    {
        printf("  None all departments are within budget.\n");
    }

    printf("-------------------------\n");
}



void supplierReport()
{
    printf("\n");
    printf("-------------------------");
    printf("SUPPLIER REPORT\n");
    printf("-------------------------");

    printf("Total suppliers: %d\n", getSupplierCount());

    displaySuppliers();

    printf("-------------------------\n");
}



void assetReport()
{
    printf("\n");
    printf("-------------------------");
    printf("ASSET REPORT\n");
    printf("-------------------------");

    printf("Total assets registered: %d\n", assetCount);

    displayAssets();

    printf("-------------------------\n");
}



void displayReports()
{
    int choice;

    do
    {
        printf("\n");
        printf("------------------------");
        printf("REPORTS\n");
        printf("------------------------");

        printf("  1. Employee Report\n");
        printf("  2. Budget Report\n");
        printf("  3. Supplier Report\n");
        printf("  4. Asset Report\n");
        printf("  5. Return to Main Menu\n");

        printf("------------------------");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        while (choice < 1 || choice > 5)
        {
            printf("Invalid choice. Please enter a number between 1 and 5: ");
            scanf("%d", &choice);
        }

        switch (choice)
        {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                assetReport();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;
        }

    } while (choice != 5);
}
