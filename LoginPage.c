#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


extern account_list head_account;

void LoginPage()
{
    int choice , n;
    printf("====>Welcome to Warehouse Management program<====\n\n");
    printf("\t1.SignUp\n\t2.LogIn\n\t3.Exit\n==>Please enter the number of your choice : ");
    scanf("%d" , &choice);
    system("cls");
    switch (choice)
    {
      case 1:
        SignUp();
        LoginPage();
        break;
      case 2:
        LogIn();
        MainMenu();
        break;
      case 3:
      WriteAccountsInFile(head_account);
        break;
      default:
        LoginPage();
    }
}
