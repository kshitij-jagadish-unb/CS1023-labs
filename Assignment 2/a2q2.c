#include <stdio.h>

int main(void) {
    int payCode = 0;

    double salary = 0;
    double wage = 0;
    double hours = 0;
    double sales = 0;
    double payPerItem = 0;

    int items = 0;

    double weeklyPay = 0;

    printf("Enter pay code (1-4): ");

    scanf("%d", &payCode);

    switch (payCode) {

        case 1:

            printf("Enter fixed weekly salary: ");
            scanf("%lf", &salary);

            weeklyPay = salary;
            break;

        case 2:

            printf("Enter hourly wage: ");
            scanf("%lf", &wage);

            printf("Enter hours worked: ");
            scanf("%lf", &hours);

            if (hours <= 40) {
                weeklyPay = wage * hours;
            }
            else {
                weeklyPay = (40 * wage) + ((hours - 40) * wage * 1.5);
            }

            break;

        case 3:

            printf("Enter weekly sales: ");
            scanf("%lf", &sales);

            weeklyPay = 250 + (sales * 0.057);
            break;

        case 4:

            printf("Enter payment per item: ");
            scanf("%lf", &payPerItem);

            printf("Enter number of items produced: ");
            scanf("%d", &items);

            weeklyPay = payPerItem * items;
            break;

        default:
        
            printf("Invalid pay code.\n");
            return 0;
    }

    printf("Weekly pay: %.2f\n", weeklyPay);

    return 0;
}