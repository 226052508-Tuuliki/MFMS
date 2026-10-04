#ifndef SUPPLIERS_H
#define SUPPLIERS_H

void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void compareSuppliers(void);
void supplierMenu(void);

/* Supplier data is shared with the Reports module (reports.c) */
extern int supplierID[5];
extern char supplierName[5][100];
extern char email[5][50];
extern char telephoneNumber[5][20];
extern char Town[5][50];
extern int Count;

#endif 