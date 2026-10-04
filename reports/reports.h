#ifndef REPORTS_H
#define REPORTS_H

#include "../budget/budget.h"

void displayReports(void);

void employeeReport(char ids[][20], char names[][50], char departments[][50],
                    double basic[], double housing[], double transport[],
                    int count);
void budgetReport(struct Budget list[], int count);
void supplierReport(int ids[], char names[][100], char emails[][50],
                    char phones[][20], char towns[][50], int count);
void assetReport(int ids[], char names[][50], char types[][50],
                 float values[], char departments[][50],
                 char conditions[][50], int count);

#endif
