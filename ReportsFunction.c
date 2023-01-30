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
    printf("\n\nPlease enter any thing to exit this page.....");
    getch();
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
    printf("\n\nPlease enter any thing to exit this page.....");
    getch();
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
    printf("\n\nPlease enter any thing to exit this page.....");
    getch();
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
    printf("\n\nPlease enter any thing to exit this page.....");
    getch();
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
    printf("\n\nPlease enter any thing to exit this page.....");
    getch();
}


void TheNumberOfArrivalsOfASpecificProductInASpecificHistoricalPeriod()
{
    struct Date
    {
        int year;
        int month;
        int day;
    };
    struct Date date[3];
    ProductList *current = head_product;
    char FirstDate[100] , LastDate[100] , ProductName[100] , DateTransection[100];
    int count = 0 , sum = 0;
    printf("Please enter a product name  : ");
    scanf("%s" , ProductName);
    printf("Please enter a First Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , FirstDate);
    date[0].year = atoi(strtok(FirstDate , "/"));
    date[0].month = atoi(strtok(NULL , "/"));
    date[0].day = atoi(strtok(NULL , "/"));
    printf("Please enter a Last Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , LastDate);
    date[1].year = atoi(strtok(LastDate , "/"));
    date[1].month = atoi(strtok(NULL , "/"));
    date[1].day = atoi(strtok(NULL , "/"));
    while (current != NULL)
    {
        if (strcmp(current->product.NameOfTheProduct , ProductName) == 0)
        {
            ImportAndExportProductList *current_1 = head_transaction_product;
            while (current_1 != NULL)
            {
                if ((current_1->transaction.ProductID == current->product.ID) && (strcmp(current_1->transaction.TransactionType , "Enter") == 0))
                {
                    strcpy(DateTransection , current_1->transaction.TransactionDate);
                    date[2].year = atoi(strtok(DateTransection , "/"));
                    date[2].month = atoi(strtok(NULL , "/"));
                    date[2].day = atoi(strtok(NULL , "/"));
                    if ((date[0].year <= date[2].year) && (date[1].year >= date[2].year))
                    {
                        if ((date[0].month <= date[2].month) || (date[1].month >= date[2].month))
                        {
                            if ((date[0].day <= date[2].day) || (date[1].day >= date[2].day))
                            {
                                count++;
                                sum += current_1->transaction.NumberOfProductsInThisTransaction;
                            }
                        }
                    }
                }
                current_1 = current_1->next;
            }
        }
        current = current->next;
    }
    printf("\nThe %s was inserted %d times during the time period between %d/%d/%d and %d/%d/%d\n" , ProductName , count , date[0].year , date[0].month , date[0].day , date[1].year , date[2].month , date[1].day);
    printf("\nThe number of pieces entered during this time period : %d\n" , sum);
    printf("\n\nPlease enter any thing to exit this page.....");
    getch();
}


void TheNumberOfReleasesOfASpecificProductInASpecificHistoricalPeriod()
{
    struct Date
    {
        int year;
        int month;
        int day;
    };
    struct Date date[3];
    ProductList *current = head_product;
    char FirstDate[100] , LastDate[100] , ProductName[100] , DateTransection[100];
    int count = 0 , sum = 0;
    printf("Please enter a product name  : ");
    scanf("%s" , ProductName);
    printf("Please enter a First Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , FirstDate);
    date[0].year = atoi(strtok(FirstDate , "/"));
    date[0].month = atoi(strtok(NULL , "/"));
    date[0].day = atoi(strtok(NULL , "/"));
    printf("Please enter a Last Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , LastDate);
    date[1].year = atoi(strtok(LastDate , "/"));
    date[1].month = atoi(strtok(NULL , "/"));
    date[1].day = atoi(strtok(NULL , "/"));
    while (current != NULL)
    {
        if (strcmp(current->product.NameOfTheProduct , ProductName) == 0)
        {
            ImportAndExportProductList *current_1 = head_transaction_product;
            while (current_1 != NULL)
            {
                if ((current_1->transaction.ProductID == current->product.ID) && (strcmp(current_1->transaction.TransactionType , "Exit") == 0))
                {
                    strcpy(DateTransection , current_1->transaction.TransactionDate);
                    date[2].year = atoi(strtok(DateTransection , "/"));
                    date[2].month = atoi(strtok(NULL , "/"));
                    date[2].day = atoi(strtok(NULL , "/"));
                    if ((date[0].year <= date[2].year) && (date[1].year >= date[2].year))
                    {
                        if ((date[0].month <= date[2].month) || (date[1].month >= date[2].month))
                        {
                            if ((date[0].day <= date[2].day) || (date[1].day >= date[2].day))
                            {
                                count++;
                                sum += current_1->transaction.NumberOfProductsInThisTransaction;
                            }
                        }
                    }
                }
                current_1 = current_1->next;
            }
        }
        current = current->next;
    }
    printf("\nThe %s was removed %d times during the time period between %d/%d/%d and %d/%d/%d\n" , ProductName , count , date[0].year , date[0].month , date[0].day , date[1].year , date[2].month , date[1].day);
    printf("\nThe number of pieces removed during this time period : %d\n" , sum);
    printf("\n\nPlease enter any thing to exit this page.....");
    getch();
}


void ReportOfTheArrivalAndDepartureOfASpecificItemInADetailedHistoricalperiod()
{
    struct Date
    {
        int year;
        int month;
        int day;
    };
    struct Date date[3];
    ProductList *current = head_product;
    char FirstDate[100] , LastDate[100] , ProductName[100] , DateTransection[100];
    int count = 0;
    printf("Please enter a product name  : ");
    scanf("%s" , ProductName);
    printf("Please enter a First Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , FirstDate);
    date[0].year = atoi(strtok(FirstDate , "/"));
    date[0].month = atoi(strtok(NULL , "/"));
    date[0].day = atoi(strtok(NULL , "/"));
    printf("Please enter a Last Date (ex: yyyy/mm/dd) : ");
    scanf("%s" , LastDate);
    date[1].year = atoi(strtok(LastDate , "/"));
    date[1].month = atoi(strtok(NULL , "/"));
    date[1].day = atoi(strtok(NULL , "/"));
    while (current != NULL)
    {
        if (strcmp(current->product.NameOfTheProduct , ProductName) == 0)
        {
            ImportAndExportProductList *current_1 = head_transaction_product;
            while (current_1 != NULL)
            {
                if (current_1->transaction.ProductID == current->product.ID)
                {
                    strcpy(DateTransection , current_1->transaction.TransactionDate);
                    date[2].year = atoi(strtok(DateTransection , "/"));
                    date[2].month = atoi(strtok(NULL , "/"));
                    date[2].day = atoi(strtok(NULL , "/"));
                    if ((date[0].year <= date[2].year) && (date[1].year >= date[2].year))
                    {
                        if ((date[0].month <= date[2].month) || (date[1].month >= date[2].month))
                        {
                            if ((date[0].day <= date[2].day) || (date[1].day >= date[2].day))
                            {
                                count++;
                                printf("\n%d." , count);
                                printf("\n\tProduct ID : %d" , current_1->transaction.ProductID);
                                printf("\n\tNumber Of Products In This Transaction : %d" , current_1->transaction.NumberOfProductsInThisTransaction);
                                printf("\n\tTransaction Type : %s" , current_1->transaction.TransactionType);
                                printf("\n\tTransaction Date : %s" , current_1->transaction.TransactionDate);
                            }
                        }
                    }
                }
                current_1 = current_1->next;
            }
        }
        current = current->next;
    }
    printf("\n\nPlease enter any thing to exit this page.....");
    getch();
}