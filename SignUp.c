#include<stdio.h>
#include<string.h>

void SignUp()
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
    char temp , robot_check;
    AccountData = fopen("AccountData.txt" , "ab");
    if (AccountData == NULL)
    {
        printf("ERROR , File could not be opened");
    }
    else
    {
        printf("====>Welcome to the sign up page<====\n\n");
        printf("We need some information, please enter this information....\n\n");
        fflush(stdin);
        do
        {
          printf("Username : ");
          gets(user.UserName);
          length = strlen(user.UserName);
          for ( i = 0 ; i < length ; i++ )
          {
              temp = user.UserName[i];
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
              printf("You do not have to enter a space in the username, please enter it again : \n");
              user.UserName[length] = ".";
          }
        }while (n != 0);
        printf("Password : ");
        gets(user.Password);
        do
        {
           n = 1;
           printf("Confirm Your Password : ");
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
        printf("Name : ");
        gets(user.Name);
        printf("Last Name : ");
        gets(user.LastName);
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
        printf("Date of birth (ex:yyyy/mm/dd) : ");
        gets(user.DateOfBirth);
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
        fwrite(&user , sizeof(struct AccountData) , 1 , AccountData);
        fflush(stdin);
        do
        {
            n = 0;
            printf("If you are not a robot please enter (y) : \n");
            scanf("%c" , &robot_check);
            if (robot_check != 'y')
                n = 1;
        }while (n != 0);
        fclose(AccountData);
        printf("Your data has been saved........\nThank you for this information....");
    }
}


