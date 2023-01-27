#include<stdio.h>
#include<string.h>
#include "structs.h"

extern ProductList *head_product;

extern struct ProductData product;

int CheckUsedID(ProductList *head , int ID)
{
    ProductList *current = head;
    while (current != NULL)
    {
        if (current->product.ID == ID )
        {
            printf("Your ID is being used in another product.\nPlease enter another ID...\n");
            return 1;
        }
        current = current->next;
    }
    return 0;
}




void NewProductRegistration()
{
    int check;
    fflush(stdin);
    printf("====>Welcome to the new product registration page<====\n\n");
    printf("We need some information about the new product, please enter this information....\n\n");
    do 
    {
        printf("Product ID : ");
        scanf("%d" , &product.ID);
        check = CheckUsedID(head_product , product.ID);
    }while(check != 0);
    fflush(stdin);
    printf("Name of the product : ");
    gets(product.NameOfTheProduct);
    printf("Brand of the product : ");
    gets(product.BrandOfTheProduct);
    printf("Model of the product : ");
    gets(product.ModelOfTheProduct);
    printf("Product price : ");
    gets(product.ProductPrice);
    printf("Explanations : ");
    gets(product.Explanations);
    PushProductFromFile(head_product, product);

}
