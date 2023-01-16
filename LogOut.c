#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

void LogOut()
{
    fflush(stdin);
    char Yes_check;
    printf("Are you sure??? (ans : y or n) : ");
    scanf("%c" , &Yes_check);
    if (Yes_check == 'y')
        LoginPage();
    else if (Yes_check == 'n')
        MainMenu();
    else
        LogOut();
}
