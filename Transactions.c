#include<stdio.h>
#include<string.h>
#include "structs.h"

extern ImportAndExportProductList *head_transaction_product;
extern char auth_user[100];
extern struct ImportAndExportProductFromWarehouse transaction;
extern ProductList *head_product;
extern struct ProductData product;


void ProductCount(int number , int choice , int ID)
{
    ProductList *current = head_product;
    while (current != NULL)
    {
        if (current->product.ID == ID )
        {
            break;
        }
        current = current->next;
    }
    if (choice == 1)
    {
        current->product.count = current->product.count + number;
    }
    else
    {
        current->product.count = current->product.count - number;
    }
}



void Transactions()
{
    int choice , n = 0;
    fflush(stdin);
    printf("====>Welcome to the Registering The Entry Of Products page<====\n\n");
    ProductList *current = head_product;
    int count = 0;
    char NameOfTheProduct[100];
    printf("enter Name Of The Product to search it : ");
    gets(NameOfTheProduct);
    while (current != NULL)
    {
        if (strstr(current->product.NameOfTheProduct , NameOfTheProduct))
        {
            count++;
            printf("\n%d." , count);
            printf("\n\tProduct ID : %d" , current->product.ID);
            printf("\n\tName of the product : %s" , current->product.NameOfTheProduct);
            printf("\n\tBrand of the product : %s" , current->product.BrandOfTheProduct);
            printf("\n\tModel of the product : %s" , current->product.ModelOfTheProduct);
            printf("\n\tProduct price : %s" , current->product.ProductPrice);
            printf("\n\tExplanations : %s\n" , current->product.Explanations);
        }
        current = current->next;
    }
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
        strcpy(transaction.TransactionType , "Enter");
        n = 0;
        break;
    case 2:
        strcpy(transaction.TransactionType , "Exit");
        n = 0;
        break;
    default:
        printf("wrong choice!!!!!!!!");
        n = 1;
        break;
    }
    }while (n != 0);
    printf("Number Of Products In This Transaction : ");
    scanf("%d" , &transaction.NumberOfProductsInThisTransaction);
    ProductCount(transaction.NumberOfProductsInThisTransaction , choice , transaction.ProductID);
    printf("Transaction Date : ");
    scanf("%s" , transaction.TransactionDate);
    strcpy(transaction.UserName , auth_user);
    PushTransactionProductFromFile(head_transaction_product, transaction);
}
