#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#include "structs.h"

extern struct AccountData user;
extern account_list *head_account;


extern int authenticate;
extern char auth_user;


void LogOut()
{
    fflush(stdin);
    char Yes_check;
    printf("Are you sure??? (ans : y or n) : ");
    scanf("%c" , &Yes_check);
    if (Yes_check == 'y'){
        authenticate = 0;
        auth_user = '\0';
        LoginPage();
    }
    else if (Yes_check == 'n')
        MainMenu();
    else
        LogOut();
}
