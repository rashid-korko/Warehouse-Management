#include<stdio.h>
#include<stdlib.h>
#include "structs.h"

//Here there are functions for taking data from files and putting them into linked lists, and functions for unloading memory

extern struct AccountData user;
extern account_list *head_account;


extern ImportAndExportProductList *head_transaction_product;
extern struct ImportAndExportProductFromWarehouse transaction;

extern struct ProductData product;
extern ProductList *head_product;

/// Account Data get and set file

void PushAccountFromFile(account_list *head, struct AccountData user)
{
    account_list *current = head;
    if(!current)
    {
        head_account = (account_list *) malloc(sizeof(account_list));
        head_account->user = user;
        head_account->next = NULL;
        return;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (account_list *) malloc(sizeof(account_list));
    current->next->user = user;
    current->next->next = NULL;
}
void ImportAccountDataFromFile()
{
   size_t checked_end_of_file;
   FILE *AccountDataFile;
   AccountDataFile = fopen("AccountData.txt" , "r");
   checked_end_of_file = fread(&user , sizeof(struct AccountData) , 1 , AccountDataFile);
   if (checked_end_of_file)
   {
       head_account = (account_list *) malloc(sizeof(account_list));
       head_account->user = user;
       head_account->next = NULL;
   }
   while (checked_end_of_file)
   {
       checked_end_of_file = fread(&user , sizeof(struct AccountData) , 1 , AccountDataFile);
       if(checked_end_of_file)
       {
           PushAccountFromFile(head_account , user);
       }
   }
}
void WriteAccountsInFile(account_list *head)
{
    FILE *file;
    file = fopen("AccountData.txt" , "w");
    account_list *current = head;
    while (current != NULL)
    {
        fwrite(&current->user , sizeof(struct AccountData) , 1 , file);
        current = current->next;
    }
    fclose(file);
}



/// prodcut get and set file

void PushProductFromFile(ProductList *head , struct ProductData product)
{
   ProductList *current = head;
   if(!current)
   {
        head_product = (ProductList *) malloc(sizeof(ProductList));
        head_product->product = product;
        head_product->next = NULL;
        return;
   }
   while (current->next != NULL)
   {
       current = current->next;
   }
   current->next = (ProductList *) malloc(sizeof(ProductList));
   current->next->product = product;
   current->next->next = NULL;
}

void ImportProductDataFromFile1()
{
  size_t checked_end_of_file;
  FILE *file;
  file = fopen("ProductData.txt" , "r");
  checked_end_of_file = fread(&product , sizeof(struct ProductData) , 1 , file);
  if (checked_end_of_file)
  {
       head_product = (ProductList *) malloc(sizeof(ProductList));
       head_product->product = product;
       head_product->next = NULL;
  }
  while (checked_end_of_file)
  {
      checked_end_of_file = fread(&product , sizeof(struct ProductData) , 1 , file);
      if(checked_end_of_file)
      {
          PushProductFromFile(head_product , product);
      }
  }
}
void WriteProductsInFile(ProductList *head)
{
    FILE *file;
    file = fopen("ProductData.txt" , "w");
    ProductList *current = head;
    while (current != NULL)
    {
        fwrite(&current->product , sizeof(struct ProductData) , 1 , file);
        current = current->next;
    }
    fclose(file);
}


// tarnsaction get data from file functions


void ImportTransactionProductDataFromFile()
{
  size_t checked_end_of_file;
  FILE *file;
  file = fopen("EntryAndExityProducts.txt" , "r");
  checked_end_of_file = fread(&transaction , sizeof(struct ImportAndExportProductFromWarehouse) , 1 , file);
  if (checked_end_of_file)
  {
       head_transaction_product = (ImportAndExportProductList *) malloc(sizeof(ImportAndExportProductList));
       head_transaction_product->transaction = transaction;
       head_transaction_product->next = NULL;
  }
  while (checked_end_of_file)
  {
      checked_end_of_file = fread(&transaction , sizeof(struct ImportAndExportProductFromWarehouse) , 1 , file);
      if(checked_end_of_file)
      {
          PushTransactionProductFromFile(head_transaction_product , transaction);
      }
  }
}

void PushTransactionProductFromFile(ImportAndExportProductList *head, struct ImportAndExportProductFromWarehouse transaction)
{
   ImportAndExportProductList *current = head;
   if(!current){
        head_transaction_product = (ImportAndExportProductList *) malloc(sizeof(ImportAndExportProductList));
        head_transaction_product->transaction = transaction;
        head_transaction_product->next = NULL;
        return;
    }
   while (current->next != NULL)
   {
       current = current->next;
   }
   current->next = (ImportAndExportProductList *) malloc(sizeof(ImportAndExportProductList));
   current->next->transaction = transaction;
   current->next->next = NULL;
}


void WriteTransactionProductsInFile(ImportAndExportProductList *head)
{
    FILE *file;
    file = fopen("EntryAndExityProducts.txt" , "w");
    ImportAndExportProductList *current = head;
    while (current != NULL)
    {
        fwrite(&current->transaction , sizeof(struct ImportAndExportProductFromWarehouse) , 1 , file);
        current = current->next;
    }
    fclose(file);
}

// function for clean RAM

void CleanARAM(account_list *head)
{
    account_list *temp;
   while (head != NULL)
    {
       temp = head;
       head = head->next;
       free(temp);
    }
}


void CleanPRAM(ProductList *head)
{
    ProductList *temp;
   while (head != NULL)
    {
       temp = head;
       head = head->next;
       free(temp);
    }
}

void CleanTRAM(ImportAndExportProductList *head)
{
    ImportAndExportProductList *temp;
   while (head != NULL)
    {
       temp = head;
       head = head->next;
       free(temp);
    }
}