#include <stdio.h>

void add(double a, double b)
{
    printf("\nOperation: Addition\n");
    printf("First value: %.2f\n", a);
    printf("Second value: %.2f\n", b);
    printf("Result: %.2f\n", a + b);
}

void subtract(double a, double b)
{
    printf("\nOperation: Subtraction\n");
    printf("First value: %.2f\n", a);
    printf("Second value: %.2f\n", b);
    printf("Result: %.2f\n", a - b);
}

void multiply(double a, double b)
{
    printf("\nOperation: Multiplication\n");
    printf("First value: %.2f\n", a);
    printf("Second value: %.2f\n", b);
    printf("Result: %.2f\n", a * b);
}

void divide(double a, double b)
{
    printf("\nOperation: Division\n");
    printf("First value: %.2f\n", a);
    printf("Second value: %.2f\n", b);

    if (b == 0)
    {
        printf("Error: Division by zero is not allowed.\n");
        return;
    }

    printf("Result: %.2f\n", a / b);
}

int main()
{
    void (*operations[4])(double, double) =
    {
        add,
        subtract,
        multiply,
        divide
    };

    int choice;
    double num1, num2;

    do
    {
        printf("\n===== Calculator Menu =====\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
        {
            printf("Enter first number: ");
            scanf("%lf", &num1);

            printf("Enter second number: ");
            scanf("%lf", &num2);

            operations[choice - 1](num1, num2);
        }
        else if (choice == 5)
        {
            printf("\nExiting program...\n");
        }
        else
        {
            printf("\nInvalid menu selection.\n");
        }

    } while (choice != 5);

    return 0;
}

