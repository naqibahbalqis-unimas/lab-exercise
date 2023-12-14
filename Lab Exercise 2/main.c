#include <stdio.h>

int sum(int a, int b);
double average(int total);
int main() {
	hello();
	int a = 5213; 
	int b = 6786;
	printf("A = %d\n",a);
	printf("B = %d\n",b);
	printf("Total = %d\n",sum(a,b));
	printf("Average = %f\n",average(sum(a,b)));
	
	return 0;
}

int sum(int a, int b)
{
	int total = a+b;
	return total;
}

double average(int total){
	double average = (double)total/2;
	return average;
}

int hello(){
	printf("Hello\n");
	return 0;
}

int recursion