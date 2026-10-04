#include <stdio.h>
#include <string.h>
#include "suppliers.h"

int supplierID[5];
char supplierName[5][100];
char email[5][50];
char telephoneNumber[5][10];
char Town[5][50];

int Count = 0;


void addSupplier()
{
    if (Count < 5)
    {
        printf("\n add supplier \n");

        printf("Enter The suppliers ID: ");
        scanf("%d", &supplierID[Count]);

        printf("Enter the supplier Name: ");
        scanf("%s", supplierName[Count]);

        printf("Enter the Email: ");
        scanf("%s", email[Count]);

        printf("Enter the Telephone Number: ");
        scanf("%s", telephoneNumber[Count]);

        printf("Enter the Town/Location: ");
        scanf("%s", Town[Count]);

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
    scanf("%s", searchName);

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
    scanf("%d", &compareID);

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