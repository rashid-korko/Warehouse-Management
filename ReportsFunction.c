#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structs.h"


extern struct AccountData user;
extern account_list *head_account;

extern struct ImportAndExportProductFromWarehouse transaction;
extern ImportAndExportProductList *head_transaction_product;

extern struct ProductData product;
extern ProductList *head_product;


void QuantityOfEachProductInTheWarehouse()
{
    ProductList *current = head_product;
    int count = 0;
    while (current != NULL)
    {
        count++;
        printf("\n%d." , count);
        printf("\n\tProduct ID : %d" , current->product.ID);
        printf("\n\tName of the product : %s" , current->product.NameOfTheProduct);
        printf("\n\tcount : %d" , current->product.count);
        printf("\n\tBrand of the product : %s" , current->product.BrandOfTheProduct);
        printf("\n\tModel of the product : %s" , current->product.ModelOfTheProduct);
        printf("\n\tProduct price : %s" , current->product.ProductPrice);
        printf("\n\tExplanations : %s" , current->product.Explanations);
        current = current->next;
    }
    sleep(5);
}


void TheListOfProductsOfWhichWeHaveMoreThanACertainAmount()
{
    ProductList *current = head_product;
    int num;
    int count = 0;
    printf("Please enter a number in order to print products whose quantity is more than this number : ");
    scanf("%d" , &num);
    while (current != NULL)
    {
        if (current->product.count >= num)
        {
            count++;
            printf("\n%d." , count);
            printf("\n\tProduct ID : %d" , current->product.ID);
            printf("\n\tName of the product : %s" , current->product.NameOfTheProduct);
            printf("\n\tcount : %d" , current->product.count);
            printf("\n\tBrand of the product : %s" , current->product.BrandOfTheProduct);
            printf("\n\tModel of the product : %s" , current->product.ModelOfTheProduct);
            printf("\n\tProduct price : %s" , current->product.ProductPrice);
            printf("\n\tExplanations : %s" , current->product.Explanations);
        }
        current = current->next;
    }
    sleep(5);
}


void TheListOfProductsOfWhichWeHaveLessThanACertainAmount()
{
    ProductList *current = head_product;
    int num;
    int count = 0;
    printf("Please enter a number in order to print products whose quantity is less than this number : ");
    scanf("%d" , &num);
    while (current != NULL)
    {
        if (current->product.count <= num)
        {
            count++;
            printf("\n%d." , count);
            printf("\n\tProduct ID : %d" , current->product.ID);
            printf("\n\tName of the product : %s" , current->product.NameOfTheProduct);
            printf("\n\tcount : %d" , current->product.count);
            printf("\n\tBrand of the product : %s" , current->product.BrandOfTheProduct);
            printf("\n\tModel of the product : %s" , current->product.ModelOfTheProduct);
            printf("\n\tProduct price : %s" , current->product.ProductPrice);
            printf("\n\tExplanations : %s" , current->product.Explanations);
        }
        current = current->next;
    }
    sleep(5);
}


void RiyalValueOfAllWarehouseProducts()
{
    ProductList *current = head_product;
    int sum = 0 , price;
    while (current != NULL)
    {
        price = atoi(current->product.ProductPrice);
        sum = sum + (price * current->product.count);
        current = current->next;
    }
    printf("Riyal value of products = %d" , sum);
    sleep(5);
}


void RiyalValueOfAParticularProductInTheWarehouse()
{
    ProductList *current = head_product;
    int price;
    char ProductName[100];
    printf("Please enter a product name  : ");
    scanf("%s" , ProductName);
    while (current != NULL)
    {
        if (strcmp(current->product.NameOfTheProduct , ProductName) == 0)
        {
            price = atoi(current->product.ProductPrice);
            printf("Riyal value of ( %s ) = %d\n" , current->product.NameOfTheProduct , price);
            price = price * current->product.count;
            printf("Riyal value of all ( %s ) = %d\n" , current->product.NameOfTheProduct , price);
        }
        current = current->next;
    }
    sleep(5);
}


void TheNumberOfArrivalsOfASpecificProductInASpecificHistoricalPeriod()
{
    ProductList *current = head_product;
    char FirstDate[100] , LastDate[100] , ProductName[100];
    printf("Please enter a product name  : ");
    scanf("%s" , ProductName);
    printf("Please enter a First Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , FirstDate);
    printf("Please enter a Last Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , LastDate);
    while (current != NULL)
    {
        if (strcmp(current->product.NameOfTheProduct , ProductName) == 0)
        {
            ImportAndExportProductList *current_1 = head_transaction_product;
            while (current_1 != NULL)
            {
                if (strcmp(current_1->transaction.NumberOfProductsInThisTransaction , ProductName) == 0)
                {
                }
                current_1 = current_1->next;
            }
        }
        current = current->next;
    }
    sleep(5);
}