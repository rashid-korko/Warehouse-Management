#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


extern account_list head_account;
extern int authenticate;

void LoginPage()
{
    int choice;
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
        system("cls");
        if (!authenticate)
        {
            printf("\n\n\n\t\tWrong credentials\n\t\tInvalid username or password...\n\t\tPlease try agian\n\n\n");
        }
        break;
    case 3:
        WriteAccountsInFile(head_account);
        exit(0);
        break;
    }
}
