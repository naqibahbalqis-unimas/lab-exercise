//Program to demonstrate multi-selection using switch-case
#include <stdio.h>
#include <ctype.h>
int main() {
    char color;
    int blue;
    char choice;
    do {
        printf("Please enter your choice [B-Blue | C-Cyan | G-Green | R-Red | Y-Yellow : ");
        scanf(" %c", &color);
        color = toupper(color);
        switch (color) {
            case 'B':
                printf("Your chosen color is BLUE\n");
                printf("[1]Light Blue or [2]Dark Blue? ");
                if (scanf("%d", &blue) == 1) {
                    switch (blue) {
                        case 1:
                            printf("You have chosen Light Blue\n");
                            break;
                        case 2:
                            printf("You have chosen Dark Blue\n");
                            break;
                        default:
                            printf("WRONG ENTRY, TRY AGAIN!!!\n");
                    }
                } else {
                    printf("WRONG ENTRY, TRY AGAIN!!!\n");
                }
                break;
            case 'C':
                printf("Your chosen color is CYAN\n");
                break;
            case 'G':
                printf("Your chosen color is GREEN\n");
                break;
            case 'R': //another approach to accept capital letter R or small letter r
                printf("Your chosen color is RED\n");
                break;
            case 'Y':
                printf("Your chosen color is YELLOW\n");
                break;
            default:
                printf("WRONG ENTRY, TRY AGAIN!!!\n");
        }
        printf("Do you want to continue? [Y/N] ");
        scanf(" %c", &choice);

    }while (choice == 'Y' || choice == 'y');
    return 0;
}
