#include <stdio.h>
#include <string.h>
#include "budget.h"



void addBudget(struct Budget budgets[], int *count);
void displayBudgets(struct Budget budgets[], int count);
void calculateBudget(struct Budget budgets[], int count);
void showExceededBudgets(struct Budget budgets[], int count);
void budgetMenu(struct Budget budgets[], int *count);

int main() {
    struct Budget budgets[MAX_DEPARTMENTS];
    int budgetCount = 0;

    budgetMenu(budgets, &budgetCount);

    return 0;
}


void budgetMenu(struct Budget budgets[], int *count) {
    int choice;

    do {
        printf("\n========================================\n");
        printf("          BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Enter Departmental Budget\n");
        printf("2. Display Budget Information\n");
        printf("3. Calculate Remaining Budgets\n");
        printf("4. Show Departments Over Budget\n");
        printf("5. Return to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBudget(budgets, count);
                break;

            case 2:
                displayBudgets(budgets, *count);
                break;

            case 3:
                calculateBudget(budgets, *count);
                break;

            case 4:
                showExceededBudgets(budgets, *count);
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please enter 1-5.\n");
        }

    } while (choice != 5);
}


void addBudget(struct Budget budgets[], int *count) {

    if (*count >= MAX_DEPARTMENTS) {
        printf("\nMaximum number of departments reached.\n");
        return;
    }

    printf("\n========== ADD DEPARTMENTAL BUDGET ==========\n");

    printf("Enter Department ID: ");
    scanf("%d", &budgets[*count].departmentID);

    getchar();

    printf("Enter Department Name: ");
    fgets(budgets[*count].departmentName, 50, stdin);

   
    budgets[*count].departmentName[
        strcspn(budgets[*count].departmentName, "\n")
    ] = '\0';

    do {
        printf("Enter Allocated Budget (N$): ");
        scanf("%lf", &budgets[*count].allocatedBudget);

        if (budgets[*count].allocatedBudget < 0) {
            printf("Budget cannot be negative.\n");
        }

    } while (budgets[*count].allocatedBudget < 0);

    do {
        printf("Enter Expenditure (N$): ");
        scanf("%lf", &budgets[*count].expenditure);

        if (budgets[*count].expenditure < 0) {
            printf("Expenditure cannot be negative.\n");
        }

    } while (budgets[*count].expenditure < 0);

    
    budgets[*count].remainingBudget =
        budgets[*count].allocatedBudget -
        budgets[*count].expenditure;

    (*count)++;

    printf("\nBudget successfully added!\n");
}

void displayBudgets(struct Budget budgets[], int count) {

    if (count == 0) {
        printf("\nNo budget information available.\n");
        return;
    }

    printf("\n================ BUDGET INFORMATION ================\n");

    for (int i = 0; i < count; i++) {

        printf("\nDepartment ID: %d\n",
               budgets[i].departmentID);

        printf("Department: %s\n",
               budgets[i].departmentName);

        printf("Allocated Budget: N$%.2f\n",
               budgets[i].allocatedBudget);

        printf("Expenditure: N$%.2f\n",
               budgets[i].expenditure);

        printf("Remaining Budget: N$%.2f\n",
               budgets[i].remainingBudget);

        if (budgets[i].expenditure <= budgets[i].allocatedBudget) {
            printf("Status: WITHIN BUDGET\n");
        } else {
            printf("Status: OVER BUDGET\n");
        }

        printf("----------------------------------------------\n");
    }
}

void calculateBudget(struct Budget budgets[], int count) {

    if (count == 0) {
        printf("\nNo budget information available.\n");
        return;
    }

    printf("\n========== BUDGET CALCULATIONS ==========\n");

    for (int i = 0; i < count; i++) {

        budgets[i].remainingBudget =
            budgets[i].allocatedBudget -
            budgets[i].expenditure;

        printf("\nDepartment: %s\n",
               budgets[i].departmentName);

        printf("Remaining Budget: N$%.2f\n",
               budgets[i].remainingBudget);

        if (budgets[i].expenditure <= budgets[i].allocatedBudget) {
            printf("Status: WITHIN BUDGET\n");
        } else {
            printf("Status: OVER BUDGET\n");
        }
    }
}

void showExceededBudgets(struct Budget budgets[], int count) {

    int found = 0;

    if (count == 0) {
        printf("\nNo budget information available.\n");
        return;
    }

    printf("\n========== DEPARTMENTS OVER BUDGET ==========\n");

    for (int i = 0; i < count; i++) {

        if (budgets[i].expenditure > budgets[i].allocatedBudget) {

            double amountOver =
                budgets[i].expenditure -
                budgets[i].allocatedBudget;

            printf("\nDepartment: %s\n",
                   budgets[i].departmentName);

            printf("Allocated Budget: N$%.2f\n",
                   budgets[i].allocatedBudget);

            printf("Expenditure: N$%.2f\n",
                   budgets[i].expenditure);

            printf("Amount Over Budget: N$%.2f\n",
                   amountOver);

            found = 1;
        }
    }

    if (found == 0) {
        printf("\nNo departments have exceeded their budget.\n");
    }
}