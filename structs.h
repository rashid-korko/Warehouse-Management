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
    int ProductID;
    char TransactionType[100];
    int NumberOfProductsInThisTransaction;
    char TransactionDate[100];
    int RegistrantUserID;
};


typedef struct ProductNode
{
    struct ImportAndExportProductFromWarehouse product;
    struct ProductNode *next;
} Product_list;


struct ProductData
{
    int ProductID;
    char NameOfTheProduct[100];
    char BrandOfTheProduct[100];
    char ModelOfTheProduct[100];
    char ProductPrice[100];
    char Explanations[100];
    char UniqueProductIdentifiers[100];
};
