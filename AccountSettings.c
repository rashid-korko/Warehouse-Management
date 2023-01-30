#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "structs.h"


extern char auth_user[100];
extern account_list *head_account;
extern struct AccountData user;

//This function is to enter the user settings in order to modify some data
void AccountSettings()
{
    int i , length , n = 1 , tempint , choice;
    char temp , Yes_check;
    char UserName[100] , Password[100];
    fflush(stdin);
    system("cls");
    account_list *current = head_account;
    while (current != NULL)
    {
        if (strcmp(current->user.UserName, auth_user) == 0 )
        {
            break;
        }
        current = current->next;
    }
    printf("====>Welcome to Warehouse Management account settings<====\n\n");
    printf("1.Name : %s\n" , current->user.Name);
    printf("2.LastName : %s\n" , current->user.LastName);
    printf("3.National Code : %s\n" , current->user.NationalCode);
    printf("4.Phone Number : %s\n" , current->user.PhoenNumber);
    printf("5.Email : %s\n" , current->user.Email);
    printf("6.Password : %s\n" , current->user.Password);
    printf("7.Date Of Birth : %s\n" , current->user.DateOfBirth);
    printf("8.Sex : %s\n" , current->user.Sex);
    printf("9.Exit\n==>Please enter the number of your choice for change this information : ");
    scanf("%d" , &choice);
    system("cls");
    fflush(stdin);
    switch (choice)
    {
      case 1:
          {
            printf("Name : ");
            gets(current->user.Name);
            break;
          }
      case 2:
          {
            printf("Last Name : ");
            gets(current->user.LastName);
            break;
          }
      case 3:
          {
            do
            {
              n = 1;
              printf("National Code (ex:0123456789) : ");
              gets(current->user.NationalCode);
              length = strlen(current->user.NationalCode);
              for ( i = 0 ; i < length ; i++ )
              {
                  tempint = current->user.NationalCode[i];
                  if (tempint < 48 || tempint > 57)
                  {
                      break;
                  }
              }
              if (tempint >= 48 && tempint <= 57)
              {
                 n = 0;
              }
              else
              {
                  printf("You must enter only numbers and ten numbers only, as shown in the example, please enter it again : \n");
                  current->user.NationalCode[length] = ".";
              }
            }while (n != 0);
            break;
          }
      case 4:
          {
            do
            {
              n = 1;
              printf("Phoen Number (ex:09123456789) : ");
              gets(current->user.PhoenNumber);
              length = strlen(current->user.PhoenNumber);
              for ( i = 0 ; i < length ; i++ )
              {
                  tempint = current->user.PhoenNumber[i];
                  if (tempint < 48 || tempint > 57)
                  {
                      break;
                  }
              }
              if (tempint >= 48 && tempint <= 57)
              {
                 n = 0;
              }
              else
              {
                  printf("You must enter only numbers and eleven numbers only, as shown in the example, please enter it again : \n");
                  current->user.PhoenNumber[length] = ".";
              }
            }while (n != 0);
            break;
          }
      case 5:
          {
            do
            {
              n = 1;
              printf("Email (ex:******@****.com) : ");
              gets(current->user.Email);
              length = strlen(current->user.Email);
              for ( i = 0 ; i < length ; i++ )
              {
                  temp = current->user.Email[i];
                  if (temp == ' ')
                  {
                      break;
                  }
              }
              if (temp != ' ')
              {
                 n = 0;
              }
              else
              {
                  printf("You do not have to enter a space in the Email, please enter it again : \n");
                  current->user.Email[length] = ".";
              }
            }while (n != 0);
            break;
          }
      case 6:
          {
            printf("New Password : ");
            gets(current->user.Password);
            do
            {
               n = 1;
               printf("Confirm Your New Password : ");
               gets(current->user.ConfirmYourPassword);
               if (strcmp(current->user.ConfirmYourPassword , current->user.Password) != 0)
               {
                   printf("Those passwords didn�t match. Try again.\n");
               }
               else
               {
                   n = 0;
               }
            }while (n != 0);
            break;
          }
      case 7:
          {
            printf("Date of birth (ex:yyyy/mm/dd) : ");
            gets(current->user.DateOfBirth);
            break;
          }
      case 8:
          {
            do
            {
               printf("Sex : \n\t1.Male\n\t2.Female\n\t3.Rather not say\n==>Please enter the number of your choice : ");
               scanf("%d" , &choice);
               n = 0;
               if (choice == 1)
                   strcpy(current->user.Sex , "Male");
               else if (choice == 2)
                   strcpy(current->user.Sex , "Female");
               else if (choice == 3)
                   strcpy(current->user.Sex , "Rather not say");
               else
               {
                   n = 1;
                   printf("You entered an incorrect option, please select again.\n");
               }
            }while (n != 0);
            break;
          }
      case 9:
        MainMenu();
        break;
      default:
        AccountSettings();
    }
    do
    {
        n = 0;
        printf("Are you want change another information ? (ans : y or n) : ");
        scanf("%c" , &Yes_check);
        if (Yes_check == 'y')
            AccountSettings();
        else if (Yes_check == 'n')
            MainMenu();
        else
            n = 1;
    }while (n != 0);
}
