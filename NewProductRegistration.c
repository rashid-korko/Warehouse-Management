#include<stdio.h>
#include<string.h>
#include "structs.h"

void NewProductRegistration()
{
    FILE *ProductDataFile;
    struct ProductData product;
    ProductDataFile = fopen("ProductData.txt" , "a+");
    if (ProductDataFile == NULL)
    {
        printf("ERROR , File could not be opened");
    }
    else
    {
        fflush(stdin);
        printf("====>Welcome to the new product registration page<====\n\n");
        printf("We need some information about the new product, please enter this information....\n\n");
        printf("Product ID : ");
        scanf("%d" , &product.ProductID);
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
        printf("Unique product identifiers : ");
        gets(product.UniqueProductIdentifiers);
        fwrite(&product , sizeof(struct ProductData) , 1 , ProductDataFile);
        fclose(ProductDataFile);
    }
}
