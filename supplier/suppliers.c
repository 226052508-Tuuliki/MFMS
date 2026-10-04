#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "../validation.h"

int supplierID[5];
char supplierName[5][100];
char email[5][50];
char telephoneNumber[5][20];
char Town[5][50];

int Count = 0;


void addSupplier()
{
    if (Count < 5)
    {
        printf("\n add supplier \n");

        printf("Enter The suppliers ID: ");
        supplierID[Count] = readInt("", 1, 999999);

        printf("Enter the supplier Name: ");
        readText("", supplierName[Count], 100);

        printf("Enter the Email: ");
        readEmail("", email[Count], 50);

        printf("Enter the Telephone Number: ");
        readPhone("", telephoneNumber[Count], 20);

        printf("Enter the Town/Location: ");
        readText("", Town[Count], 50);

        printf("\nSupplier was successfully added.\n");

        Count++;
    }
    else
    {
        printf("\n only 5 suppliers can be added.\n");
    }
}


void displaySuppliers()
{
    int i;

    printf("\n--- SUPPLIER DETAILS ---\n");

    if (Count == 0)
    {
        printf("supplier does not exist \n");
        return;
    }

    for (i = 0; i < Count; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %d\n", supplierID[i]);
        printf("Supplier Name: %s\n", supplierName[i]);
        printf("Email: %s\n", email[i]);
        printf("Telephone Number: %s\n", telephoneNumber[i]);
        printf("Town/Location: %s\n", Town[i]);
    }
}


void searchSupplier()
{
    char searchName[50];
    int i;
    int found = 0;

    printf("\n search for the supplier \n");

    printf("Enter the suppliers Name: ");
    readText("", searchName, 50);

    for (i = 0; i < Count; i++)
    {
        if (strcmp(searchName, supplierName[i]) == 0)
        {
            printf("\nSupplier found!\n");

            printf("Supplier ID: %d\n", supplierID[i]);
            printf("Supplier Name: %s\n", supplierName[i]);
            printf("Email: %s\n", email[i]);
            printf("Telephone Number: %s\n", telephoneNumber[i]);
            printf("Town/Location: %s\n", Town[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nSupplier information does not exist.\n");
    }
}


void compareSuppliers()
{
    int compareID;
    int i;
    int found = 0;

    printf("\n Compare Supplier Information \n");

    printf("Enter Supplier ID: ");
    compareID = readInt("", 1, 999999);

    for (i = 0; i < Count; i++)
    {
        if (compareID == supplierID[i])
        {
            printf("\nSupplier ID entered matches an existing supplier.\n");

            printf("Supplier ID: %d\n", supplierID[i]);
            printf("Supplier Name: %s\n", supplierName[i]);
            printf("Email: %s\n", email[i]);
            printf("Telephone Number: %s\n", telephoneNumber[i]);
            printf("Town/Location: %s\n", Town[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Supplier ID entered does not exist.\n");
    }
}

void supplierMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("          SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier by Name\n");
        printf("4. Compare/Search Supplier by ID\n");
        printf("5. Return to Main Menu\n");
        printf("========================================\n");

        choice = readMenuChoice("Enter your choice: ", 1, 5);

        switch (choice)
        {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                compareSuppliers();
                break;
            case 5:
                printf("\nReturning to Main Menu...\n");
                break;
        }
    } while (choice != 5);
}
