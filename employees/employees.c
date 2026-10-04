#include <stdio.h>
#include <string.h>
#include "employee.h"


    static char employeeIDs[MAX_EMPLOYEES][MAX_ID_LENGTH];
    static char employeeNames[MAX_EMPLOYEES][MAX_NAME_LENGTH];
    static char employeeDepartments[MAX_EMPLOYEES][MAX_DEPT_LENGTH];
    static double employeeBasicSalaries[MAX_EMPLOYEES];
    static double employeeHousingAllowances[MAX_EMPLOYEES];
    static double employeeTransportAllowances[MAX_EMPLOYEES];
    static int employeeCount = 0;
    
    int validatePositiveSalary(double salary)
    {
        if (salary > 0) return 1;
        return 0;
    }
    
    int validateNonEmptyString(const char *str)
    {
        if (strlen(str) > 0) return 1;
        return 0;
    }
    
    void displayEmployeeMenu(void)
    {
        printf("\n");
        printf("========================================\n");
        printf("       EMPLOYEE MANAGEMENT              \n");
        printf("========================================\n");
        printf("  1. Add Employee                       \n");
        printf("  2. Display All Employees              \n");
        printf("  3. Search Employee by ID              \n");
        printf("  4. Calculate Employee Salary          \n");
        printf("  5. Display Salary Summary             \n");
        printf("  6. Return to Main Menu                \n");
        printf("========================================\n");
        printf("  Enter your choice: ");
    }
    
    void addEmployee(void)
    {
        char tempID[MAX_ID_LENGTH];
        char tempName[MAX_NAME_LENGTH];
        char tempDept[MAX_DEPT_LENGTH];
        double tempBasic, tempHousing, tempTransport;
        int validInput;
        int i;
        int duplicateFound;
        
        printf("\n--- ADD NEW EMPLOYEE ---\n");
        
        if (employeeCount >= MAX_EMPLOYEES)
        {
            printf("Error: Maximum employee limit (%d) reached.\n", MAX_EMPLOYEES);
            return;
        }
        
        do
        {
            validInput = 1;
            printf("Enter Employee ID: ");
            scanf("%19s", tempID);
            
            if (!validateNonEmptyString(tempID))
            {
                printf("Error: Employee ID cannot be empty.\n");
                validInput = 0;
            }
            
            if (validInput)
            {
                duplicateFound = 0;
                for (i = 0; i < employeeCount; i++)
                {
                    if (strcmp(employeeIDs[i], tempID) == 0)
                    {
                        duplicateFound = 1;
                        break;
                    }
                }
                if (duplicateFound)
                {
                    printf("Error: Employee ID already exists.\n");
                    validInput = 0;
                }
            }
        } while (!validInput);
        
        do
        
        {
            printf("Enter Employee Name: ");
            scanf("%49s", tempName);
            
            if (!validateNonEmptyString(tempName))
            {
                printf("Error: Employee name cannot be empty.\n");
            }
        } while (!validateNonEmptyString(tempName));
        do
        {
            printf("Enter Department: ");
            scanf("%49s", tempDept);
            
            if (!validateNonEmptyString(tempDept))
            {
                printf("Error: Department cannot be empty.\n");
            }
        } while (!validateNonEmptyString(tempDept));
        
        do
        {
            printf("Enter Basic Salary (N$): ");
            scanf("%lf", &tempBasic);
            
            if (!validatePositiveSalary(tempBasic))
            {
                printf("Error: Salary must be positive.\n");
            }
        } while (!validatePositiveSalary(tempBasic));
        
        do
        {
            printf("Enter Housing Allowance (N$): ");
            scanf("%lf", &tempHousing);
            
            if (tempHousing < 0)
            {
                printf("Error: Housing allowance cannot be negative.\n");
            }
        } while (tempHousing < 0);
        
        do
        {
            printf("Enter Transport Allowance (N$): ");
            scanf("%lf", &tempTransport);
            
            if (tempTransport < 0)
            {
                printf("Error: Transport allowance cannot be negative.\n");
            }
        } while (tempTransport < 0);
        
        strcpy(employeeIDs[employeeCount], tempID);
        strcpy(employeeNames[employeeCount], tempName);
        strcpy(employeeDepartments[employeeCount], tempDept);
        employeeBasicSalaries[employeeCount] = tempBasic;
        employeeHousingAllowances[employeeCount] = tempHousing;
        employeeTransportAllowances[employeeCount] = tempTransport;
        
        employeeCount++;
        
        printf("\nSuccess: Employee added successfully!\n");
        printf("Total employees in system: %d\n", employeeCount);
    }
    
    void displayEmployees(void)
    {
        int i;
        double grossSalary;
        
        printf("\n--- ALL EMPLOYEES ---\n");
        
        if (employeeCount == 0)
        {
            printf("No employees have been added yet.\n");
            return;
        }
        
        printf("\n");
        
        printf("================================================================================\n");
        printf("%-10s %-20s %-15s %12s %12s %12s %12s\n",
           "ID", "Name", "Department", "Basic", "Housing", "Transport", "Gross");
        printf("================================================================================\n");
        
        for (i = 0; i < employeeCount; i++)
        {
            grossSalary = employeeBasicSalaries[i] +
                employeeHousingAllowances[i] +
                employeeTransportAllowances[i];
            
            printf("%-10s %-20s %-15s %12.2f %12.2f %12.2f %12.2f\n",
                   employeeIDs[i],
                   employeeNames[i],
                   employeeDepartments[i],
                   employeeBasicSalaries[i],
                   employeeHousingAllowances[i],
                   employeeTransportAllowances[i],
                   grossSalary);
        }
        
        printf("================================================================================\n");
        printf("Total Employees: %d\n", employeeCount);
    }
    
    void searchEmployee(void)
    {
        char searchID[MAX_ID_LENGTH];
        int found = 0;
        int i;
        double grossSalary;
        
        printf("\n--- SEARCH EMPLOYEE ---\n");
        
        if (employeeCount == 0)
        {
            printf("No employees in the system to search.\n");
            return;
        }
        
        printf("Enter Employee ID to search: ");
        scanf("%19s", searchID);
        
        for (i = 0; i < employeeCount; i++)
        {
            if (strcmp(employeeIDs[i], searchID) == 0)
            {
                found = 1;
                grossSalary = employeeBasicSalaries[i] +
                    employeeHousingAllowances[i] +
                    employeeTransportAllowances[i];
                
                printf("\n--- EMPLOYEE FOUND ---\n");
                printf("Employee ID       : %s\n", employeeIDs[i]);
                printf("Name              : %s\n", employeeNames[i]);
                printf("Department        : %s\n", employeeDepartments[i]);
                printf("Basic Salary      : N$ %.2f\n", employeeBasicSalaries[i]);
                printf("Housing Allowance : N$ %.2f\n", employeeHousingAllowances[i]);
                printf("Transport Allow.  : N$ %.2f\n", employeeTransportAllowances[i]);
                printf("Gross Salary      : N$ %.2f\n", grossSalary);
                printf("Position in array : %d\n", i);
                break; 
            }
        }
        
        if (!found)
        {
            printf("\nEmployee with ID '%s' not found.\n", searchID);
        }
    }
    
    void calculateEmployeeSalary(void)
    {
        char searchID[MAX_ID_LENGTH];
        int found = 0;
        int i;
        double grossSalary;
        double tax;
        double netSalary;
        
        printf("\n--- CALCULATE EMPLOYEE SALARY ---\n");
        
        if (employeeCount == 0)
        {
            printf("No employees in the system.\n");
            return;
        }
        
        printf("Enter Employee ID: ");
        scanf("%19s", searchID);
        
        for (i = 0; i < employeeCount; i++)
        {
            if (strcmp(employeeIDs[i], searchID) == 0)
            {
                found = 1;
                
                grossSalary = employeeBasicSalaries[i] +
                    employeeHousingAllowances[i] +
                    employeeTransportAllowances[i];
                
                printf("\n--- SALARY CALCULATION FOR %s ---\n", employeeNames[i]);
                printf("Basic Salary      : N$ %12.2f\n", employeeBasicSalaries[i]);
                printf("Housing Allowance : N$ %12.2f\n", employeeHousingAllowances[i]);
                printf("Transport Allow.  : N$ %12.2f\n", employeeTransportAllowances[i]);
                printf("----------------------------------------\n");
                printf("Gross Salary      : N$ %12.2f\n", grossSalary);
                
                printf("\nEnter Tax Amount (N$): ");
                scanf("%lf", &tax);
                
                if (tax < 0)
                {
                    printf("Error: Tax cannot be negative. Setting tax to 0.\n");
                    tax = 0;
                }
                
                netSalary = grossSalary - tax;
                
                printf("Tax Deduction     : N$ %12.2f\n", tax);
                printf("----------------------------------------\n");
                printf("Net Salary        : N$ %12.2f\n", netSalary);
                
                if (netSalary >= 20000)
                {
                    printf("Income Category   : HIGH INCOME\n");
                }
                else if (netSalary >= 10000)
                {
                    printf("Income Category   : STANDARD INCOME\n");
                }
                else
                {
                    printf("Income Category   : BASIC INCOME\n");
                }
                
                break;
            }
        }
        
        if (!found)
        {
            printf("\nEmployee with ID '%s' not found.\n", searchID);
        }
    }
    
    void displaySalarySummary(void)
    {
        int i;
        double grossSalary;
        double totalSalary = 0.0;
        double averageSalary;
        double highestSalary;
        double lowestSalary;
        int highestIndex = 0;
        int lowestIndex = 0;
        
        printf("\n--- SALARY SUMMARY REPORT ---\n");
        
        if (employeeCount == 0)
        {
            printf("No employees in the system.\n");
            return;
        }
        
        grossSalary = employeeBasicSalaries[0] +
            employeeHousingAllowances[0] +
            employeeTransportAllowances[0];
        highestSalary = grossSalary;
        lowestSalary = grossSalary;
        
        for (i = 0; i < employeeCount; i++)
        {
            grossSalary = employeeBasicSalaries[i] +
                employeeHousingAllowances[i] +
                employeeTransportAllowances[i];
            
            totalSalary = totalSalary + grossSalary;
            
            if (grossSalary > highestSalary)
            {
                highestSalary = grossSalary;
                highestIndex = i;
            }
            
            if (grossSalary < lowestSalary)
            {
                lowestSalary = grossSalary;
                lowestIndex = i;
            }
        }
        
        averageSalary = totalSalary / employeeCount;
        
        printf("\n");
        printf("========================================\n");
        printf("       EMPLOYEE SALARY REPORT           \n");
        printf("========================================\n");
        printf("Total Employees    : %d\n", employeeCount);
        printf("Total Salary Bill  : N$ %15.2f\n", totalSalary);
        printf("Average Salary     : N$ %15.2f\n", averageSalary);
        printf("Highest Salary     : N$ %15.2f\n", highestSalary);
        printf("  - Employee       : %s (ID: %s)\n",
               employeeNames[highestIndex], employeeIDs[highestIndex]);
        printf("Lowest Salary      : N$ %15.2f\n", lowestSalary);
        printf("  - Employee       : %s (ID: %s)\n",
               employeeNames[lowestIndex], employeeIDs[lowestIndex]);
        printf("========================================\n");
    }
    
    int getEmployeeCount(void)
    {
        return employeeCount;
    }
