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
    head_account.user = user;
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
        head_account.user = user;
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
