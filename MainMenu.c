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
    printf("====>Welcome to Warehouse Management Main menu<====\n\n\t");
    printf("1- New product registration\n\t");
    printf("2- Registering the entry of goods\n\t");
    printf("3- Registering the exit of goods\n\t");
    printf("4- Reports\n\t");
    printf("5- Account settings\n\t");
    printf("6- Logout\n\t"); // Done
    printf("7- Exit\n"); // Done
    printf("==>Please enter the number of your choice : ");
    scanf("%d" , &choice);
    system("cls");
    switch (choice)
    {
      case 1:
        NewProductRegistration();
        break;
     case 2:
        RegisteringTheEntryOfGoods();
        break;
    //  case 3:
    //    RegisteringTheExitOfGoods();
    //    break;
    //  case 4:
    //    Reports();
    //    break;
      case 5:
        AccountSettings();
        break;
      case 6:
        LogOut();
        break;
      case 7:
        WriteAccountsInFile(head_account);
        WriteProductsInFile(head_product);
        WriteTransactionProductsInFile(head_transaction_product);
        exit(0);
        break;
      default:
          MainMenu();
    }
}
