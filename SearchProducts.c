#include<stdio.h>
#include<stdlib.h>
#include "structs.h"

extern ProductList *head_product;

extern struct ProductData product;

void SearchProducts(ProductList *head , char NameOfTheProduct[])
{
    ProductList *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (strstr(current->product.NameOfTheProduct , NameOfTheProduct))
        {
            count++;
            printf("%d." , count);
            printf("\n\tProduct ID : %d" , current->product.ID);
            printf("\n\tName of the product : %s" , current->product.NameOfTheProduct);
            printf("\n\tBrand of the product : %s" , current->product.BrandOfTheProduct);
            printf("\n\tModel of the product : %s" , current->product.ModelOfTheProduct);
            printf("\n\tProduct price : %s" , current->product.ProductPrice);
            printf("\n\tExplanations : %s" , current->product.Explanations);
        }
        current = current->next;
    }
    return 0;
}
