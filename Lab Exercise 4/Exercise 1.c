#include <stdio.h>
#include <math.h>

int main(){
	int num;
	printf("Enter number you want to find square root of:");
	scanf("%d", &num);
	
	printf("The square root of %d is %2f", num, sqrt(num));
}