#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

struct ImportAndExportProductFromWarehouse product;
account_list * head_account = NULL;
struct AccountData user;
Product_list *head_product = NULL;
int authenticate = 0;
char auth_user[100];
int debuging = 0;


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
    debug(1, 1);
    ImportDataFromFile();
    while (1)
    {
        if (authenticate)
        {
            ImportProductDataFromFile();
            MainMenu();
        }else{
            LoginPage();
        }
    }

}
