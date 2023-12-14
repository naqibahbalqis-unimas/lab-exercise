#include <stdio.h>


int main(){
    int number;
    int *ptr;
    ptr = &number;
    number = 7;

    printf("The value of number is %d\n", number);
    printf("The address of number is %p\n", &number);
    printf("The value of ptr is %p\n", ptr);
    printf("The value of *ptr is %d\n", *ptr);
    printf("The address of ptr is %p\n", &ptr);



}