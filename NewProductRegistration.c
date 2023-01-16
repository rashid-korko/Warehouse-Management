#include<stdio.h>
#include<string.h>


void NewProductRegistration()
{
    FILE *ProductData;
     struct ProductData
    {
        char NameOfTheProduct[100];
        char BrandOfTheProduct[100];
        char ModelOfTheProduct[100];
        char ProductPrice[100];
        char Explanations[100];
        char UniqueProductIdentifiers[100];
    };
    struct ProductData product;
    ProductData = fopen("ProductData.txt" , "ab");
    if (ProductData == NULL)
    {
        printf("ERROR , File could not be opened");
    }
    else
    {
        fflush(stdin);
        printf("====>Welcome to the new product registration page<====\n\n");
        printf("We need some information about the new product, please enter this information....\n\n");
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
        fwrite(&product , sizeof(struct ProductData) , 1 , ProductData);
        fclose(ProductData);
    }
}
