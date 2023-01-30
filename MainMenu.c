#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


extern account_list *head_account;
extern ProductList *head_product;
extern ImportAndExportProductList *head_transaction_product;


void MainMenu()
{
    int choice;
    system("cls");
    system("color 7");
    printf("====>Welcome to Warehouse Management Main menu<====\n\n\t");
    printf("1- New product registration\n\t");
    printf("2- Transactions\n\t");
    printf("3- Reports\n\t");
    printf("4- Account settings\n\t");
    printf("5- Logout\n\t");
    printf("6- Exit\n");
    printf("==>Please enter the number of your choice : ");
    scanf("%d" , &choice);
    system("cls");
    switch (choice)
    {
      case 1:
        NewProductRegistration();
        MainMenu();
        break;
     case 2:
        Transactions();
        MainMenu();
        break;
     case 3:
        Reports();
        MainMenu();
        break;
      case 4:
        AccountSettings();
        MainMenu();
        break;
      case 5:
        WriteAccountsInFile(head_account);
        WriteProductsInFile(head_product);
        WriteTransactionProductsInFile(head_transaction_product);
        CleanARAM(head_account);
        CleanPRAM(head_product);
        CleanTRAM(head_transaction_product);
        LogOut();
        break;
      case 6:
        WriteAccountsInFile(head_account);
        WriteProductsInFile(head_product);
        WriteTransactionProductsInFile(head_transaction_product);
        CleanARAM(head_account);
        CleanPRAM(head_product);
        CleanTRAM(head_transaction_product);
        exit(0);
        break;
      default:
          MainMenu();
    }
}
