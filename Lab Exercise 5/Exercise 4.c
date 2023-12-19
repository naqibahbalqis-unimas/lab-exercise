#include <stdio.h>
#include <alg.h>

int average(int marks[]);
int display(int marks[]);

int main () {
    int marks[10];
    int i,j;

    for(i=0;i<10;i++) {
        printf("Enter the marks of the quiz %d = ", i + 1);
        scanf("%d", &marks[i]);
    }

    display(marks);

}

int average(int marks[]) {
    int i;
    int sum = 0;
    for(i=0;i<10;i++) {
        sum += marks[i];
    }
    return sum/10;
}

int display(int marks[]) {
    int i;
    for(i=0;i<10;i++) {
        printf("The marks of student %d = %d\n", i + 1, marks[i]);
    }
    printf("The average marks is %d\n", average(marks));
}