#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

struct ImportAndExportProductFromWarehouse product;
account_list * head_account = NULL;
struct AccountData user;
Product_list *head_product = NULL;


void main()
{
    ImportProductDataFromFile();
    ImportDataFromFile();
    LoginPage();
}
