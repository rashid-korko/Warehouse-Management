
//This page is there structchers

//this struct for account data
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

//this struct for account data in linked list
typedef struct Node
{
    struct AccountData user;
    struct Node *next;
} account_list;

//this struct for Import And Export Product From Warehouse (Transactions)
struct ImportAndExportProductFromWarehouse
{
    int NumberOfProductsInThisTransaction; 
    int ProductID;
    char UserName[100];
    char TransactionType[100];
    char TransactionDate[100];
};

//this struct for Import And Export Product From Warehouse (Transactions)in linked list
typedef struct ImportAndExportProductNode
{
    struct ImportAndExportProductFromWarehouse transaction;
    struct ImportAndExportProductNode *next;
} ImportAndExportProductList;

//this struct for Product Data
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


//this struct for Product Data in linked list
typedef struct ProductNode
{
    struct ProductData product;
    struct ProductNode *next;
} ProductList;

