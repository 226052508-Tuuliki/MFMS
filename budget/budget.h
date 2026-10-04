#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 50
information
struct Budget {
    int departmentID;
    char departmentName[50];
    double allocatedBudget;
    double expenditure;
    double remainingBudget;
};


void addBudget(struct Budget budgets[], int *count);
void displayBudgets(struct Budget budgets[], int count);
void calculateBudget(struct Budget budgets[], int count);
void showExceededBudgets(struct Budget budgets[], int count);
void budgetMenu(struct Budget budgets[], int *count);

#endif