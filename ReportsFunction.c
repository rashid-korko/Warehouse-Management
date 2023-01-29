#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


extern struct AccountData user;
extern account_list *head_account;

extern struct ImportAndExportProductFromWarehouse tarnsaction_product;
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
    int num;
    int count = 0;
    printf("Please enter a number in order to print products whose quantity is more than this number : ");
    scanf("%d" , num);
    fflush(stdin);
    ProductList *current = head_product;
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
    int num;
    int count = 0;
    printf("Please enter a number in order to print products whose quantity is less than this number : ");
    scanf("%d" , num);
    fflush(stdin);
    ProductList *current = head_product;
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


void RiyalValueOfAllWarehouseProducts(ProductList *head)
{
    ProductList *current = head;
    int sum = 0 , price;
    while (current != NULL)
    {
        price = atoi(current->product.ProductPrice);
        sum = sum + price;
        current = current->next;
    }
    sleep(5);
}


void RiyalValueOfAParticularProductInTheWarehouse()
{
    int price;
    char ProductName[100];
    printf("Please enter a product name  : ");
    gets(ProductName);
    ProductList *current = head_product;
    while (current != NULL)
    {
        if (strcmp(current->product.NameOfTheProduct , ProductName) == 0)
        {
            price = atoi(current->product.ProductPrice);
            printf("Riyal value of ( %s ) = %d" , current->product.NameOfTheProduct , price);
        }
        current = current->next;
    }
    sleep(5);
}

