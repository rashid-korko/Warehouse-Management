#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>


void LogIn()
{
    FILE *AccountData;
    struct AccountData
    {
        char UserName[100];
        char Name[100];
        char LastName[100];
        char NationalCode[11];
        char PhoenNumber[12];
        char Email[100];
        char Password[100];
        char ConfirmYourPassword[100];
        char DateOfBirth[100];
        char Sex[100];
    };
    struct AccountData user;
    char UserName[100] , Password[100];
    int n = 1;
    system("cls");
    printf("====>Welcome to the login page<====\n\n");
    fflush(stdin);
    do
    {
        AccountData = fopen("AccountData.txt" , "r");
        printf("Username : ");
        gets(UserName);
        printf("Password : ");
        gets(Password);
        do
        {
            fread(&user , sizeof(struct AccountData) , 1 , AccountData);
            if ((strcmp(UserName , user.UserName) == 0) && (strcmp(Password , user.Password) == 0))
            {
                n = 0;
            }
        }while (!feof(AccountData));
        if (n != 0)
        {
            printf("Wrong credentials\nInvalid username or password...\n");
            n = 1;
        }
        fclose(AccountData);
    }while (n != 0);
}

