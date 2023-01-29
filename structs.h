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


typedef struct Node
{
    struct AccountData user;
    struct Node *next;
} account_list;


struct ImportAndExportProductFromWarehouse
{
    int NumberOfProductsInThisTransaction; 
    int ProductID;
    char UserName[100];
    char TransactionType[100];
    char TransactionDate[100];
};


typedef struct ImportAndExportProductNode
{
    struct ImportAndExportProductFromWarehouse transaction;
    struct ImportAndExportProductNode *next;
} ImportAndExportProductList;


struct ProductData
{
    int ID;
    int count;
    char NameOfTheProduct[100];
    char BrandOfTheProduct[100];
    char ModelOfTheProduct[100];
    char ProductPrice[100];
    char Explanations[100];
};



typedef struct ProductNode
{
    struct ProductData product;
    struct ProductNode *next;
} ProductList;

