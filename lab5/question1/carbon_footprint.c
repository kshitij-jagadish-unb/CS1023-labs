#include <stdio.h>

void buildingFootprint(void){

    double electricity = 0;
    double carbonF = 0;

    printf("\n How much is your annual Electricty usage? (kW/h): \n");
    scanf("%lf", &electricity);

    carbonF = electricity * 0.12;  // 0.12 kg CO2 per kWh

    printf("The amount of Carbon Footprint produced is: %.2f kg CO2 / year. \n", carbonF);  
}

void carFootprint(void){

    double fuel = 0;
    double carbonF = 0;

    printf("\n How much fuel does your car take to reach full tank? (liters): \n");
    scanf("%lf", &fuel);

    carbonF = fuel * 2.31; // 2.31 kg CO2 per liter of gasoline

    printf("The amount of Carbon Footprint produced is: %.2f kg CO2 / full tank. \n", carbonF);
}

void bicycleFootprint(void){

    double km = 0;
    double carbonF = 0;

    printf("\n How much distance do you travel in a day on your bicycle? (approx. km): \n");
    scanf("%lf", &km);

    carbonF = km * 0.016; // 0.016 kg C2 per km

    printf("The amount of Carbon Footprint produced is: %.2f kg CO2 / day. \n", carbonF);
}

int main(void){

    void (*Calculator[])(void) = {buildingFootprint , carFootprint, bicycleFootprint};

    int option = 0;

    while( option != 4){

        printf("\n 1 - Building");
        printf("\n 2 - Car");
        printf("\n 3 - Bicycle");
        printf("\n 4 - Exit");

        printf("\n Option: ");
        scanf("%d", &option);

        switch(option){

            case 1:
                Calculator[0]();
                break;

            case 2:
                Calculator[1]();
                break;

            case 3:
                Calculator[2]();
                break;

            case 4:
                printf("\n Thank You!");
                break;

            default:
                printf("Choose an option Broski.");
        }

    }
    return 0;
}
