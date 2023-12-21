#include <stdio.h>

struct student {
    char name[50];
    int age;
    int marks[5]; // Specify the size of the marks array
};

void getInput(struct student *s); // Change return type to void
float calculateAverage(struct student *s);

int main() {
    struct student s; // Declare a struct student variable
    getInput(&s); // Pass the address of the struct variable

    // Display the information or perform other operations with the data if needed
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Average Marks: %.2f\n", calculateAverage(&s));

    return 0;
}

void getInput(struct student *s) {
    printf("Enter the name of the student: ");
    gets(s->name);

    printf("Enter the age of the student: ");
    scanf("%d", &s->age);

    // Enter marks on 5 subjects using a for loop and array
    printf("Enter the marks of the student: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &s->marks[i]);
    }
}

float calculateAverage(struct student *s) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += s->marks[i];
    }
    return (float)sum / 5; // Ensure floating-point division for accurate average
}
