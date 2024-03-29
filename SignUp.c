#include<stdio.h>
#include<string.h>
#include "structs.h"


extern account_list *head_account;
extern struct AccountData user;

//This function is to ensure that the username is not repeated in memory
int CheckUsedUsername(account_list *head , char username[])
{
    account_list *current = head;
    while (current != NULL)
    {
        if (strcmp(current->user.UserName, username) == 0 )
        {
            printf("Your username is being used by someone else.\nPlease enter another username...\n");
            return 1;
        }
        current = current->next;
    }
    return 0;
}


//This function is for logging new users into the project and taking information from the user and keeping it in memory
void SignUp()
{
    struct AccountData user;
    int i , length , n = 1 , tempint , choice , p = 0;
    char temp , robot_check;
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
        n = CheckUsedUsername(head_account , user.UserName);
    }while (n != 0);
    printf("Password : ");
    do{
        user.Password[p]=getch();
        if(user.Password[p]!='\r')
        {
            printf("*");
        }
        p++;
    }while(user.Password[p-1]!='\r');
    user.Password[p-1]='\0';
    do
    {
        n = 1;
        printf("\nConfirm Your Password : ");
        p = 0;
        do{
            user.ConfirmYourPassword[p]=getch();
            if(user.ConfirmYourPassword[p]!='\r')
            {
                printf("*");
            }
            p++;
        }while(user.ConfirmYourPassword[p-1]!='\r');
        user.ConfirmYourPassword[p-1]='\0';
        if (strcmp(user.ConfirmYourPassword , user.Password) != 0)
        {
            printf("Those passwords didn't match. Try again.\n");
        }
        else
        {
            n = 0;
        }
    }while (n != 0);
    printf("\nName : ");
    gets(user.Name);
    printf("Last Name : ");
    gets(user.LastName);
    do
    {
        n = 1;
        printf("National Code (ex:0123456789) : ");
        scanf("%10s" , user.NationalCode);
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
    fflush(stdin);
    do
    {
        n = 1;
        printf("Phoen Number (ex:09123456789) : ");
        scanf("%11s" , user.PhoenNumber);
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
    fflush(stdin);
    do
    {
        n = 1;
        printf("\nEmail (ex:******@****.com) : ");
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
            printf("\nYou do not have to enter a space in the Email, please enter it again : \n");
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
    PushAccountFromFile(head_account , user);
    fflush(stdin);
    do
    {
        n = 0;
        printf("If you are not a robot please enter (y) : \n");
        scanf("%c" , &robot_check);
        if (robot_check != 'y')
            n = 1;
    }while (n != 0);
    system("cls");
    printf("Your data has been saved........\nThank you for this information....\n");
}



