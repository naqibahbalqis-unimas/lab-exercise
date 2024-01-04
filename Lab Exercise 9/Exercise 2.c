#include <stdio.h>
#include <string.h>

// Define the struct before using it
struct student {
    char name[50];
    char faculty[50];
    float gpa;
    int student_id;
};

// Function prototype
void printRecord(struct student *std);

int main() {
    // Declare struct variables
    struct student student1, student2, student3;

    // Assign values to student1
    strcpy(student1.name, "John");
    strcpy(student1.faculty, "FKEKK");
    student1.gpa = 3.5;
    student1.student_id = 12345;

    // Assign values to student2
    strcpy(student2.name, "Jane");
    strcpy(student2.faculty, "FKEKK");
    student2.gpa = 3.8;
    student2.student_id = 12346;

    // Display information for student1
    printf("Student 1 name : %s\n", student1.name);
    printf("Student 1 faculty : %s\n", student1.faculty);
    printf("Student 1 GPA : %.2f\n", student1.gpa);
    printf("Student 1 student ID : %d\n", student1.student_id);
    printf("\n");

    // Display information for student2
    printf("Student 2 name : %s\n", student2.name);
    printf("Student 2 faculty : %s\n", student2.faculty);
    printf("Student 2 GPA : %.2f\n", student2.gpa);
    printf("Student 2 student ID : %d\n", student2.student_id);
    printf("\n");

    // Input information for student3
    printf("Enter the name of the student: ");
    gets(student3.name);

    printf("Enter the faculty of the student: ");
    gets(student3.faculty);

    printf("Enter the GPA of the student: ");
    scanf("%f", &student3.gpa);

    printf("Enter the student ID of the student: ");
    scanf("%d", &student3.student_id);

    printf("\n");

    // Display information for student3 using the function
    printRecord(&student1);
    printRecord(&student2);
    printf("Student ID of student 2 before function call: %d\n", student2.student_id);
    printRecord(&student3);

    printf("\n");
    return 0;
}

// Function definition to print student information and modify student_id
void printRecord(struct student *std) {
    printf("Student name : %s\n", std->name);
    printf("Student faculty : %s\n", std->faculty);
    printf("Student GPA : %.2f\n", std->gpa);
    printf("Student student ID : %d\n", std->student_id);

    // Modify student_id using the pointer
    std->student_id = 99999;

    printf("Student ID of student after function call: %d\n", std->student_id);
    printf("\n");
}
