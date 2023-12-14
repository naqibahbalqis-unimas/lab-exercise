#include <stdio.h>

int main() {
    char choice;
    do {

      int n;
        printf("Enter a number: ");
        scanf("%d", &n);
        if(n%2==0)
        {
            printf("%d is even\n", n);
        }
        else
        {
            printf("%d is odd\n", n);
        }

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);
        
    } while (choice == 'Y' || choice == 'y');
    return 0;
}
