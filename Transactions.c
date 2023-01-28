#include<stdio.h>
#include<string.h>
#include "structs.h"

extern ImportAndExportProductList *head_transaction_product;


void Transactions()
{
    struct ImportAndExportProductFromWarehouse transaction;
    int choice , n = 0;
        fflush(stdin);
        printf("====>Welcome to the Registering The Entry Of Products page<====\n\n");
        printf("Product ID : ");
        scanf("%d" , &transaction.ProductID);
        do
        {
        printf("Transaction Type :\n\t");
        printf("1.Enter products.\n\t");
        printf("2.Exit products.\n");
        printf("====>please enter the number of your choice : ");
        scanf("%d" , &choice);
        switch (choice)
        {
        case 1:
            transaction.TransactionType == "Enter";
            n = 0;
            break;
        case 2:
            transaction.TransactionType == "Exit";
            n = 0;
            break;
        default:
            printf("wrong choice!!!!!!!!");
            n = 1;
            break;
        }
        }while (n != 0);
        printf("Number Of Products In This Transaction : ");
        scanf("%d" , &transaction.ID);
        printf("Transaction Date : ");
        scanf("%s" , transaction.TransactionDate);
        printf("Registrant User ID : ");
        scanf("%s" , transaction.UserName);
        PushTransactionProductFromFile(head_transaction_product, transaction);
}
