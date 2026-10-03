#include <stdio.h>
#include <string.h>


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
    scanf("%d", &assetID[assetCount]);

    printf("Enter asset name :");
    scanf(" %[^\n]" , assetName[assetCount]);

    printf("Enter type of asset :");
    scanf(" %[^\n]",typeOfAsset[assetCount]);

    printf("Enter value of purchase :");
    scanf(" %f", &valueOfPurchase[assetCount]);

    printf("Enter department : ");
    scanf(" %[^\n]", department[assetCount]);

    printf("Enter condition of asset : ");
    scanf(" %[^\n]" , conditionOfAsset[assetCount]);

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
    scanf("%d",&searchID);

    for(i=0; i<assetCount; i++){
        if(assetID[i]== searchID){
            printf("\n Asset found \n");
            printf("Asset ID : %d\n ", assetID[i]);
            printf("Asset Name : %s\n", assetName[i]);
            printf("Type Of Asset : %s\n", typeOfAsset[i]);
            printf("Value of Purchase : N$.2f\n", valueOfPurchase[i]);
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
        scanf("%d", &choice);

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
int main(){
    assetmanagement();
    return 0;
}