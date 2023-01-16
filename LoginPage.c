#include <stdio.h>
#include <stdlib.h>

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
      case 2:
        LogIn();
        MainMenu();
        break;
      case 3:
        break;
      default:
        LoginPage();
    }
}
