#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "../validation.h"

int supplierID[MAX_SUPPLIERS];
char supplierName[MAX_SUPPLIERS][100];
char email[MAX_SUPPLIERS][50];
char telephoneNumber[MAX_SUPPLIERS][20];
char Town[MAX_SUPPLIERS][50];

int supplierCount = 0;


void addSupplier(void)
{
    int newID;
    int i;
    int duplicate;

    if (supplierCount < MAX_SUPPLIERS)
    {
        printf("\n add supplier \n");

        do
        {
            duplicate = 0;
            printf("Enter The suppliers ID: ");
            newID = readInt("", 1, 999999);

            for (i = 0; i < supplierCount; i++)
            {
                if (supplierID[i] == newID)
                {
                    printf("Error: Supplier ID already exists.\n");
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate == 1);

        supplierID[supplierCount] = newID;

        printf("Enter the supplier Name: ");
        readText("", supplierName[supplierCount], 100);

        printf("Enter the Email: ");
        readEmail("", email[supplierCount], 50);

        printf("Enter the Telephone Number: ");
        readPhone("", telephoneNumber[supplierCount], 20);

        printf("Enter the Town/Location: ");
        readText("", Town[supplierCount], 50);

        printf("\nSupplier was successfully added.\n");

        supplierCount++;
    }
    else
    {
        printf("\n only %d suppliers can be added.\n", MAX_SUPPLIERS);
    }
}


void displaySuppliers(void)
{
    int i;

    printf("\n--- SUPPLIER DETAILS ---\n");

    if (supplierCount == 0)
    {
        printf("supplier does not exist \n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier ID: %d\n", supplierID[i]);
        printf("Supplier Name: %s\n", supplierName[i]);
        printf("Email: %s\n", email[i]);
        printf("Telephone Number: %s\n", telephoneNumber[i]);
        printf("Town/Location: %s\n", Town[i]);
    }
}


void searchSupplier(void)
{
    char searchName[100];
    int i;
    int found = 0;

    printf("\n search for the supplier \n");

    printf("Enter the suppliers Name: ");
    readText("", searchName, 100);

    for (i = 0; i < supplierCount; i++)
    {
        if (equalsIgnoreCase(searchName, supplierName[i]) == 1)
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


void compareSuppliers(void)
{
    int compareID;
    int i;
    int found = 0;

    printf("\n Compare Supplier Information \n");

    printf("Enter Supplier ID: ");
    compareID = readInt("", 1, 999999);

    for (i = 0; i < supplierCount; i++)
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


/* Supplier sub-menu: runs until the user chooses "Return to Main Menu".
 * Added during integration so the root main.c can call it. */
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
        printf("Enter your choice: ");

        choice = readMenuChoice("", 1, 5);

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
