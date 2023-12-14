//Lab 2 exercise (Exercise 2)
#include <stdio.h>
#include <ctype.h>

int main()
{
    char color;
    printf("Please enter your choice (B - Blue / C - Cyan / G - Green / R - Red / Y - Yellow) : ");
    scanf("%c", &color);
    color = toupper(color);
    switch(color){
        case 'B': printf("Your chosen color is BLUE");
        break;
        case 'C': printf("Your chosen color is CYAN");
        break;
        case 'G': printf("Your chosen color is GREEN");
        //break;
        case 'R': printf("Your chosen color is RED");
        break;
        case 'Y': printf("Your chosen color is YELLOW");
        break;
        default: printf("Invalid choice");
    }
    return 0;
}