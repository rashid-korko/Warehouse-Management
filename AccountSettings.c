#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

void AccountSettings()
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
    int i , length , n = 1 , tempint , choice;
    char temp , Yes_check;
    char UserName[100] , Password[100];
    fflush(stdin);
    system("cls");
    printf("====>Welcome to Warehouse Management account settings<====\n\n");
    printf("Please enter your username and password for your account security : \n");
    do
    {
        AccountData = fopen("AccountData.txt" , "rb");
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
                break;
            }
        }while (!feof(AccountData));
        if (n != 0)
        {
            printf("Wrong credentials\nInvalid username or password...\n");
            n = 1;
        }
        fclose(AccountData);
    }while (n != 0);
    system("cls");
    printf("1.Name : %s\n" , user.Name);
    printf("2.LastName : %s\n" , user.LastName);
    printf("3.National Code : %s\n" , user.NationalCode);
    printf("4.Phone Number : %s\n" , user.PhoenNumber);
    printf("5.Email : %s\n" , user.Email);
    printf("6.Password : %s\n" , user.Password);
    printf("7.Date Of Birth : %s\n" , user.DateOfBirth);
    printf("8.Sex : %s\n" , user.Sex);
    printf("9.Exit\n==>Please enter the number of your choice for change this information : ");
    scanf("%d" , &choice);
    system("cls");
    fflush(stdin);
    switch (choice)
    {
      case 1:
          {
            printf("Name : ");
            gets(user.Name);
            break;
          }
      case 2:
          {
            printf("Last Name : ");
            gets(user.LastName);
            break;
          }
      case 3:
          {
            do
            {
              n = 1;
              printf("National Code (ex:0123456789) : ");
              gets(user.NationalCode);
              length = strlen(user.NationalCode);
              for ( i = 0 ; i < length ; i++ )
              {
                  tempint = user.NationalCode[i];
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
                  user.NationalCode[length] = ".";
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
              gets(user.PhoenNumber);
              length = strlen(user.PhoenNumber);
              for ( i = 0 ; i < length ; i++ )
              {
                  tempint = user.PhoenNumber[i];
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
                  user.PhoenNumber[length] = ".";
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
              gets(user.Email);
              length = strlen(user.Email);
              for ( i = 0 ; i < length ; i++ )
              {
                  temp = user.Email[i];
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
                  user.Email[length] = ".";
              }
            }while (n != 0);
            break;
          }
      case 6:
          {
            printf("New Password : ");
            gets(user.Password);
            do
            {
               n = 1;
               printf("Confirm Your New Password : ");
               gets(user.ConfirmYourPassword);
               if (strcmp(user.ConfirmYourPassword , user.Password) != 0)
               {
                   printf("Those passwords didn’t match. Try again.\n");
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
            gets(user.DateOfBirth);
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
                   strcpy(user.Sex , "Male");
               else if (choice == 2)
                   strcpy(user.Sex , "Female");
               else if (choice == 3)
                   strcpy(user.Sex , "Rather not say");
               else
               {
                   n = 1;
                   printf("You entered an incorrect option, please select again.\n");
               }
            }while (n != 0);
            break;
          }
      case 9:
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
