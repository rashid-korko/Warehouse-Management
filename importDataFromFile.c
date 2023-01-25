#include<stdio.h>
#include<stdlib.h>
#include "structs.h"

extern struct AccountData user;
extern account_list head_account;
struct Node temprature;

void PushAccountFromFile(account_list * head, struct AccountData user) 
{
    account_list * current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = (account_list *) malloc(sizeof(account_list));
    strcpy(current->next->user.UserName, "12345789123457891245679");
    strcpy(current->next->user.Name, user.Name);
    strcpy(current->next->user.LastName, user.LastName);
    strcpy(current->next->user.NationalCode, user.NationalCode);
    strcpy(current->next->user.PhoenNumber, user.PhoenNumber);
    strcpy(current->next->user.Email, user.Email);
    strcpy(current->next->user.Password, user.Password);
    strcpy(current->next->user.ConfirmYourPassword, user.ConfirmYourPassword);
    strcpy(current->next->user.DateOfBirth, user.DateOfBirth);
    strcpy(current->next->user.Sex, user.Sex);
    current->next->next = NULL;
}



void WriteAccountsInFile(account_list * head) 
{
    FILE *AccountDataFile;
    AccountDataFile = fopen("AccountData.txt" , "w");
    if (AccountDataFile == NULL)
    {
        printf("ERROR , File could not be opened");
        return;
    }
    account_list * current = head;
    while (current != NULL) {
        printf("%s\n", current->user.UserName);
        fwrite(&current->user , sizeof(struct AccountData) , 1 , AccountDataFile);
        current = current->next;
    }
}


void ImportDataFromFile()
{
   size_t checked_end_of_file;
   FILE *AccountDataFile;
   AccountDataFile = fopen("AccountData.txt" , "r");
   checked_end_of_file = fread(&user , sizeof(struct AccountData) , 1 , AccountDataFile);
   if (checked_end_of_file)
   {
        strcpy(head_account.user.UserName, user.UserName);
        strcpy(head_account.user.Name, user.Name);
        strcpy(head_account.user.LastName, user.LastName);
        strcpy(head_account.user.NationalCode, user.NationalCode);
        strcpy(head_account.user.PhoenNumber, user.PhoenNumber);
        strcpy(head_account.user.Email, user.Email);
        strcpy(head_account.user.Password, user.Password);
        strcpy(head_account.user.ConfirmYourPassword, user.ConfirmYourPassword);
        strcpy(head_account.user.DateOfBirth, user.DateOfBirth);
        strcpy(head_account.user.Sex, user.Sex);
        head_account.next = NULL;
        checked_end_of_file = fread(&user , sizeof(struct AccountData) , 1 , AccountDataFile);
   }
   while (checked_end_of_file)
   {
       checked_end_of_file = fread(&user , sizeof(struct AccountData) , 1 , AccountDataFile);
       if(checked_end_of_file){
           PushAccountFromFile(&head_account , user);
       }
   }
   WriteAccountsInFile(&head_account);
}
