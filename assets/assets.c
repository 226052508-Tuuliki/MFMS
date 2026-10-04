#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "../validation.h"


    int assetID[100];
    char assetName[100][50];
    char typeOfAsset[100][50];
    float valueOfPurchase[100];
    char department[100][50];
    char conditionOfAsset[100][50];

    int assetCount= 0;

void addAsset() {
    if(assetCount >= 100){
        printf("\n Asset storage is full !!\n");
        return;
    }
    
     printf("\n-------------ADD ASSET -------------\n");
    printf("Enter asset ID : ");
    assetID[assetCount] = readInt("", 1, 999999);

    printf("Enter asset name :");
    readText("", assetName[assetCount], 50);

    printf("Enter type of asset :");
    readText("", typeOfAsset[assetCount], 50);

    printf("Enter value of purchase :");
    valueOfPurchase[assetCount] = readMoney("");

    printf("Enter department : ");
    readText("", department[assetCount], 50);

    printf("Enter condition of asset : ");
    readText("", conditionOfAsset[assetCount], 50);

    assetCount++;

    printf("\nAsset was successfully added !\n");
}
void displayAssets (){
    int i;
    

    printf("\n-----------------List of assets-------------\n");

    if(assetCount==0){
        printf("No assets found\n");
        return;
    }

    for(i=0;i<assetCount;i++){
        printf("\n Asset : %d\n", i+1);
        printf("Asset ID : %d\n", assetID[i]);
        printf("Asset Name : %s\n", assetName[i]);
        printf("Type Of Asset : %s\n", typeOfAsset[i]);
        printf("Value of Purchase : N$%.2f\n", valueOfPurchase[i]);
        printf("Department : %s\n", department[i]);
        printf("Condition of asset : %s\n",conditionOfAsset[i]);
        
    }
}    
void searchAsset(){
    int searchID;
    int i;
    int found =0;

    printf("\n------------Search Asset----------\n");
    printf("Enter ID of asset to search for : ");
    searchID = readInt("", 1, 999999);

    for(i=0; i<assetCount; i++){
        if(assetID[i]== searchID){
            printf("\n Asset found \n");
            printf("Asset ID : %d\n ", assetID[i]);
            printf("Asset Name : %s\n", assetName[i]);
            printf("Type Of Asset : %s\n", typeOfAsset[i]);
            printf("Value of Purchase : N$%.2f\n", valueOfPurchase[i]);
            printf("Department : %s\n", department[i]);
            printf("Condition of asset : %s\n",conditionOfAsset[i]);

            found = 1;
            break;
            
        }
    } if(found ==0){
        printf("\n Asset not found\n");
        
    }
} 
void assetmanagement(){
    int choice ;
    do {
        printf("\n---------------------------------------\n");
        printf("             Asset Management \n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Assets\n");
        printf("4. Return to main menu\n");

        printf("Enter your choice :");
        choice = readMenuChoice("", 1, 4);

        switch (choice){
            case 1 :
            addAsset();
            break;

            case 2 :
            displayAssets();
            break;

            case 3:
            searchAsset();
            break;

            case 4:
            printf("Returning to main menu \n");
            break;

            default:
            printf("Invalid choice \n");
            
        }
    } while (choice !=4);
}
