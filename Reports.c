#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


//This is a list of reports

void Reports()
{
    int choice;
    system("cls");
    printf("====>Welcome to Reports main menu<====\n\n\t");
    printf("1- Quantity of each product in the warehouse\n\t");
    printf("2- The list of products of which we have more than a certain amount\n\t");
    printf("3- The List of products of which we have less than a certain amount\n\t");
    printf("4- Riyal value of all warehouse products\n\t");
    printf("5- Riyal value of a particular product in the warehouse\n\t");
    printf("6- The number of arrivals of a specific product in a specific historical period\n\t");
    printf("7- The number of releases of a specific product in a specific historical period\n\t");
    printf("8- Report of the arrival and departure of a specific item in a detailed historical period\n\t");
    printf("9- Exit\n");
    printf("==>Please enter the number of your choice : ");
    scanf("%d" , &choice);
    system("cls");
    switch (choice)
    {
      case 1:
        QuantityOfEachProductInTheWarehouse();
        Reports();
        break;
      case 2:
        TheListOfProductsOfWhichWeHaveMoreThanACertainAmount();
        Reports();
        break;
      case 3:
        TheListOfProductsOfWhichWeHaveLessThanACertainAmount();
        Reports();
        break;
      case 4:
        RiyalValueOfAllWarehouseProducts();
        Reports();
        break;
      case 5:
        RiyalValueOfAParticularProductInTheWarehouse();
        Reports();
        break;
     case 6:
       TheNumberOfArrivalsOfASpecificProductInASpecificHistoricalPeriod();
       Reports();
       break;
      case 7:
        TheNumberOfReleasesOfASpecificProductInASpecificHistoricalPeriod();
        break;
      case 8:
        ReportOfTheArrivalAndDepartureOfASpecificItemInADetailedHistoricalperiod();
        break;
      case 9:
        break;
      default:
        Reports();
    }
}
