#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "structs.h"

extern struct AccountData user;

void LogIn()
{
    FILE *AccountDataFile;
    char UserName[100] , Password[100];
    int n = 1;
    system("cls");
    printf("====>Welcome to the login page<====\n\n");
    fflush(stdin);
    do
    {
        AccountDataFile = fopen("AccountData.txt" , "r");
        printf("Username : ");
        gets(UserName);
        printf("Password : ");
        gets(Password);
        do
        {
            fread(&user , sizeof(struct AccountData) , 1 , AccountDataFile);
            if ((strcmp(UserName , user.UserName) == 0) && (strcmp(Password , user.Password) == 0))
            {
                n = 0;
            }
        }while (!feof(AccountDataFile));
        if (n != 0)
        {
            printf("Wrong credentials\nInvalid username or password...\n");
            n = 1;
        }
        fclose(AccountDataFile);
    }while (n != 0);
}

