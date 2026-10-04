#include <stdio.h>
#include "reports.h"

void supplierReport(int ids[], char names[][100], char emails[][50],
                    char phones[][10], char towns[][50], int count)
{
    int i;

    printf("\n SUPPLIER REPORT \n");

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

    printf("Total assets registered: %d\n", count);
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

    printf("\n EMPLOYEE REPORT n");

    if (count == 0)
    {
        printf("No employees registered.\n");
        return;
    }
