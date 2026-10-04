#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 5

void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void compareSuppliers(void);
void supplierMenu(void);

/* Supplier data is shared with the Reports module (reports.c) */
extern int supplierID[MAX_SUPPLIERS];
extern char supplierName[MAX_SUPPLIERS][100];
extern char email[MAX_SUPPLIERS][50];
extern char telephoneNumber[MAX_SUPPLIERS][20];
extern char Town[MAX_SUPPLIERS][50];
extern int supplierCount;

#endif
