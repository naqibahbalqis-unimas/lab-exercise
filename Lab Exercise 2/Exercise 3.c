//Lab 2 exercise (Exercise 3)

#include <stdio.h>

int main()
{
  	int num;
    int sum = 0;
    int i;
    float avg;
    printf("Enter 10 numbers: \n");
    for (i = 1; i <=10; i++)
    {
    	printf("Number #%d >> ", i);
        scanf("%d", &num);
        sum += num;
    }
    avg = (double)sum / 10.0;
    printf("The sum of 10 number is %d\n", sum);
    printf("The Average is %.2f\n", avg);
    return 0;
}