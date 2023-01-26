#include<stdio.h>
#include<string.h>
#include "structs.h"


void RegisteringTheEntryOfGoods()
{
    struct ImportAndExportProductFromWarehouse product;
    FILE *EntryAndExityProductsFile;
    int choice , n = 0;
    EntryAndExityProductsFile = fopen("EntryAndExityProducts.txt" , "a+");
    if (EntryAndExityProductsFile == NULL)
    {
        printf("ERROR , File could not be opened");
    }
    else
    {
        fflush(stdin);
        printf("====>Welcome to the Registering The Entry Of Products page<====\n\n");
        printf("Product ID : ");
        scanf("%d" , &product.ProductID);
        do
        {
        printf("Transaction Type :\n\t1.Enter products.\n\t2.Exit products.\n====>please enter the number of your choice : ");
        scanf("%d" , &choice);
        switch (choice)
        {
        case 1:
            product.TransactionType == "Enter";
            n = 0;
            break;
        case 2:
            product.TransactionType == "Exit";
            n = 0;
            break;
        default:
            printf("wrong choice!!!!!!!!");
            n = 1;
            break;
        }
        }while (n != 0);
        printf("Number Of Products In This Transaction : ");
        scanf("%d" , &product.NumberOfProductsInThisTransaction);
        printf("Transaction Date : ");
        scanf("%s" , product.TransactionDate);
        printf("Registrant User ID : ");
        scanf("%d" , &product.RegistrantUserID);
        fwrite(&product , sizeof(struct ImportAndExportProductFromWarehouse ) , 1 , EntryAndExityProductsFile);
        fclose(EntryAndExityProductsFile);
    }
}
