#include<stdio.h>
#include<stdlib.h>
#include"structs.h"

extern struct ImportAndExportProductFromWarehouse product;
extern Product_list head_product;


void PushProductFromFile(Product_list *head, struct ImportAndExportProductFromWarehouse product)
{
   Product_list *current = head;
   while (current->next != NULL)
   {
       current = current->next;
   }
   current->next = (Product_list *) malloc(sizeof(Product_list));
   current->next->product = product;
   current->next->next = NULL;
}



void ImportProductDataFromFile()
{
  size_t checked_end_of_file;
  FILE *EntryAndExityProductsFile;
  EntryAndExityProductsFile = fopen("EntryAndExityProducts.txt" , "r");
  checked_end_of_file = fread(&product , sizeof(struct ImportAndExportProductFromWarehouse) , 1 , EntryAndExityProductsFile);
  if (checked_end_of_file)
  {
       head_product.product = product;
       head_product.next = NULL;
  }
  while (checked_end_of_file)
  {
      checked_end_of_file = fread(&product , sizeof(struct ImportAndExportProductFromWarehouse) , 1 , EntryAndExityProductsFile);
      if(checked_end_of_file)
      {
          PushProductFromFile(&head_product , product);
      }
  }
}
