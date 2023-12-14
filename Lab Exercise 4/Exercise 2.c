#include <stdio.h>

void getUserInput(int *x, int *y);
void displayUserInput(int x, int y);
int addition(int x, int y);
int subtraction(int x, int y); 
int multiplication(int x, int y);
double division(int x, int y);
void menu(int x, int y);
//
//double testFunction(int y){
//	return y*0.5;


int main(  ){
int x;
int y;


menu(x,y);

}

void getUserInput(int *x, int *y) {
    printf("Enter two numbers: ");
    scanf("%d %d", x, y);
}


void displayUserInput(int x, int y) {
    printf("You've entered %d and %d.\n", x, y);
    
    
    
    
}

int addition(int x, int y){
	return x + y;
}

int subtraction(int x, int y) {
    return x - y;
}
	

int multiplication (int x, int y){
	return x * y;
	
}

double division(int x, int y){
	return (double)x / y;
}


void menu(int x, int y){
	int choice ;
	printf("Choose Operation\n\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	printf("5. Exit\n");
	printf("Input Choices:");
	scanf("%d", &choice); 
    getUserInput(&x, &y);
    displayUserInput(x, y);
	
	switch(choice){
		case 1:printf("%d + %d = %d\n", x,y, addition(x,y));
		break;
		case 2:printf("%d - %d = %d\n", x,y, subtraction(x,y));
		break;
		case 3:printf("%d X %d = %d\n", x,y, multiplication(x,y));
		break;
		case 4:printf("%d / %d = %.2f\n", x,y, division(x,y));
		break;
		default: printf("Invalid choice.\n");
        break;
		break;
	}
	return 0;
}