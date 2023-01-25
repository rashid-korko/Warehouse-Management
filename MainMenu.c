#include <stdio.h>
#include <stdlib.h>

void MainMenu()
{
    int choice;
    system("cls");
    printf("====>Welcome to Warehouse Management Main menu<====\n\n");
    printf("\t1.New product registration\n\t2.Registering the entry of goods\n\t3.Registering the exit of goods\n\t4.Reports\n\t5.Account settings\n\t6.Logout\n\t7.Exit\n==>Please enter the number of your choice : ");
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
        break;
      default:
          MainMenu();
    }
}
