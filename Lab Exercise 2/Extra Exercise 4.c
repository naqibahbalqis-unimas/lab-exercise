

#include <stdio.h>

int main()
{
    char choice;
    int num;
    int i = 0;

    do
    {
        printf("===========Print Stars===========\n");
        printf("Enter a number of asterisk to print: ");
        scanf("%d", &num);
        printf("%d stars \t\t", num);
        while (i < num)
        {

            printf("*");
            i++;
        }
        printf("\n");

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);

        i = 0;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}