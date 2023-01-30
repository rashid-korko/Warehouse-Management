#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

account_list *head_account = NULL;
ProductList *head_product = NULL;
ImportAndExportProductList *head_transaction_product = NULL;

struct AccountData user;
struct ProductData product;
struct ImportAndExportProductFromWarehouse transaction;

int authenticate = 0;
char auth_user[100];
int debuging = 1;


void debug(int step, int sleep_time){
    if (debuging)
    {
        printf("\n*** %d ***\n", step);
        sleep(sleep_time);
    }
}

void main()
{
    int action_user;
    ImportAccountDataFromFile();
    while (1)
    {
        if (authenticate)
        {
            ImportProductDataFromFile1();
            ImportTransactionProductDataFromFile();
            MainMenu();
        }
        else
        {
            LoginPage();
        }
    }

}
