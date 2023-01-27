#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "structs.h"

extern struct AccountData user;
extern account_list *head_account;
extern int authenticate;
extern char auth_user[100];

int LogIn()
{
    char UserName[100] , Password[100];
    int check_login = 0;
    system("cls");
    printf("====>Welcome to the login page<====\n\n");
    fflush(stdin);
    printf("Username : ");
    gets(UserName);
    printf("Password : ");
    gets(Password);
    check_login = checkLogin(head_account, UserName, Password);
    return check_login;
}


int checkLogin(account_list *head, char username[], char password[])
{
    int auth = 0;
    account_list *current = head;
    while (current != NULL)
    {
        if ((strcmp(current->user.UserName, username)) == 0 && (strcmp(current->user.Password, password) == 0))
        {
            auth = 1;
            authenticate = 1;
            strcpy(auth_user, username);
            return auth;
        }
        current = current->next;
    }
    return auth;
}