#include <stdio.h>

int main() {
    char choice;
    do {

        int counter = 1;
        int number;
        int sum = 0; // Initialize sum to zero
        double average;
        printf("Please enter 10 numbers. \n");

        while (counter <= 10) {
            printf("Number #%d >> ", counter);
            scanf("%d", &number);
            sum += number; // sum = sum + number;
            ++counter;     // counter = counter + 1;
        }

        average = (double) sum / 10.0; // Ensure that one of the operands is a double to perform floating-point division
        printf("\nSum of the 10 numbers is %d \n", sum);
        printf("The average of these numbers is %lf \n", average);
        printf("Continue? (Y/N) >> ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    return 0;
}
