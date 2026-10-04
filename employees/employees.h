/* Employee Management Header - Originally developed by Muingona T Mbaha 223059242
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
int validateNonEmptyString(const char *str);
void employeeMenu(void);

/* Employee data is shared with the Reports module (reports.c) */
extern char employeeIDs[MAX_EMPLOYEES][MAX_ID_LENGTH];
extern char employeeNames[MAX_EMPLOYEES][MAX_NAME_LENGTH];
extern char employeeDepartments[MAX_EMPLOYEES][MAX_DEPT_LENGTH];
extern double employeeBasicSalaries[MAX_EMPLOYEES];
extern double employeeHousingAllowances[MAX_EMPLOYEES];
extern double employeeTransportAllowances[MAX_EMPLOYEES];

#endif
