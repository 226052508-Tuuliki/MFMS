#ifndef ASSETS_H
#define ASSETS_H

void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void assetmanagement(void);

/* Asset data is shared with the Reports module (reports.c) */
extern int assetID[100];
extern char assetName[100][50];
extern char typeOfAsset[100][50];
extern float valueOfPurchase[100];
extern char department[100][50];
extern char conditionOfAsset[100][50];
extern int assetCount;

#endif