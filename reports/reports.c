void supplierReport(int ids[], char names[][100], char emails[][50],
                    char phones[][10], char towns[][50], int count)
{
    printf("\n===== SUPPLIER REPORT =====\n");

    if (count == 0)
    {
        printf("No suppliers registered.\n");
        return;
    }

    for (int i = 0; i < count; i++)
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
    double totalValue = 0.0;

    printf("\n===== ASSET REPORT =====\n");

    if (count == 0)
    {
        printf("No assets registered.\n");
        return;
    }

    for (int i = 0; i < count; i++)
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

    printf("\n----------------------------------------\n");
    printf("Total assets registered: %d\n", count);
    printf("Total value of assets: N$%.2f\n", totalValue);
}
void employeeReport(char ids[][20], char names[][50], char departments[][50],
                    double basic[], double housing[], double transport[],
                    int count)
{
    double totalSalary = 0.0;
    double averageSalary;
    double highestSalary, lowestSalary;
    int highestIndex = 0, lowestIndex = 0;

    printf("\n===== EMPLOYEE REPORT =====\n");

    if (count == 0)
    {
        printf("No employees registered.\n");
        return;
    }

    /* First employee sets the initial high/low values */
    double gross = basic[0] + housing[0] + transport[0];
    highestSalary = lowestSalary = gross;

    for (int i = 0; i < count; i++)
    {
        gross = basic[i] + housing[i] + transport[i];
        totalSalary += gross;

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

    printf("\n========================================\n");
    printf("       EMPLOYEE SALARY REPORT           \n");
    printf("========================================\n");
    printf("Total Employees    : %d\n", count);
    printf("Total Salary Bill  : N$ %15.2f\n", totalSalary);
    printf("Average Salary     : N$ %15.2f\n", averageSalary);
    printf("Highest Salary     : N$ %15.2f\n", highestSalary);
    printf("  - Employee       : %s (ID: %s)\n",
           names[highestIndex], ids[highestIndex]);
    printf("Lowest Salary      : N$ %15.2f\n", lowestSalary);
    printf("  - Employee       : %s (ID: %s)\n",
           names[lowestIndex], ids[lowestIndex]);
    printf("========================================\n");
}

void budgetReport(int deptIDs[], char deptNames[][50],
                  double allocated[], double expenditure[],
                  int count)
{
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    double totalRemaining = 0.0;
    int overBudgetCount = 0;

    printf("\n===== BUDGET REPORT =====\n");

    if (count == 0)
    {
        printf("No budget information available.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        double remaining = allocated[i] - expenditure[i];

        totalAllocated   += allocated[i];
        totalExpenditure += expenditure[i];
        totalRemaining   += remaining;
    }

    printf("\n----------------------------------------\n");
    printf("Total Allocated Budget : N$%15.2f\n", totalAllocated);
    printf("Total Expenditure      : N$%15.2f\n", totalExpenditure);
    printf("Total Remaining Budget : N$%15.2f\n", totalRemaining);
    printf("----------------------------------------\n");

    printf("\nDepartments exceeding budget:\n");

    for (int i = 0; i < count; i++)
    {
        if (expenditure[i] > allocated[i])
        {
            double amountOver = expenditure[i] - allocated[i];

            printf("\n  Department : %s (ID %d)\n", deptNames[i], deptIDs[i]);
            printf("  Allocated  : N$%.2f\n", allocated[i]);
            printf("  Spent      : N$%.2f\n", expenditure[i]);
            printf("  Over by    : N$%.2f\n", amountOver);

            overBudgetCount++;
        }
    }

    if (overBudgetCount == 0)
        printf("  None – all departments are within budget.\n");
    else
        printf("\nTotal departments over budget: %d\n", overBudgetCount);
}
