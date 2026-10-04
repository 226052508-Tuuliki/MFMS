#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50
#define MAX_DEPT_LENGTH 50
#define MAX_ID_LENGTH 20

void displayEmployeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateEmployeeSalary(void);
void displaySalarySummary(void);
int getEmployeeCount(void);
int validatePositiveSalary(double salary);
int validateNonEmptyString(const char *str)

#endif
