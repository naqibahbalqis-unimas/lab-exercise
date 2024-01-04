#include <stdio.h>
#include <string.h>
struct Student {
    int studentNumber;
    char name[50];
    float itpMark;
    float dmMark;
    float sadMark;
};



void enterMarks(FILE *file);
void displayStudent(FILE *file);
void ReadFiles(FILE *file);

int main() {
    FILE *marksFile;

    // Open the file in binary read/write mode
    marksFile = fopen("Marks.bin", "ab+");

    // Check if the file opened successfully
    if (marksFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int choice;

    do {
        printf("\nEnter 1 to enter marks\n");
        printf("Enter 2 to display student information\n");
        printf("Enter 3 to show table\n");
        printf("Enter 4 to search student\n");
        printf("Enter 5 to exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterMarks(marksFile);
                break;
            case 2:
                displayStudent(marksFile);
                break;
            case 3:
                ReadFiles(marksFile);
                break;
            case 4:
                {
                    int targetStudentNo;
                    printf("Enter the student number to search: ");
                    scanf("%d", &targetStudentNo);
                    searchByStudentNo(marksFile, targetStudentNo);
                }
            case 5:
				printf("Exiting program.\n");
                break;
                	
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    // Close the file
    fclose(marksFile);

    return 0;
}

void enterMarks(FILE *file) {
    struct Student student;
    int studentCount = 0;  // To keep track of the student number

    while (1) {
        printf("\nEnter details for a student (Enter 'exit' to stop):\n");

        // Read student information
        printf("Enter name: ");
        scanf("%s", student.name);

        if (strcmp(student.name, "exit") == 0) {
            break;  // Exit the loop if the user enters "exit"
        }

        student.studentNumber = ++studentCount;  // Increment and assign the student number

        printf("Enter ITP mark: ");
        scanf("%f", &student.itpMark);

        printf("Enter DM mark: ");
        scanf("%f", &student.dmMark);

        printf("Enter SAD mark: ");
        scanf("%f", &student.sadMark);

        // Move the file pointer to the end of the file
        fseek(file, 0, SEEK_END);

        // Write the student information to the file
        fwrite(&student, sizeof(struct Student), 1, file);
    }

    printf("\nMarks entered successfully.\n");
}
void displayStudent(FILE *file) {
    struct Student student;

    // Rewind the file to the beginning
    rewind(file);

    // Display information for each student in the file
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        printf("\nStudent %d Information for %s:\n", student.studentNumber, student.name);

        // Display marks for each subject
        printf("Student %d - DM: %.2f\n", student.studentNumber, student.dmMark);
        printf("Student %d - ITP: %.2f\n", student.studentNumber, student.itpMark);
        printf("Student %d - Sad: %.2f\n", student.studentNumber, student.sadMark);

    }
}

void ReadFiles(FILE *file) {
    struct Student student;

    // Close and reopen the file in read mode
    fclose(file);
    file = fopen("Marks.bin", "rb");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    // Display header
    printf("\t\t\tMarks for Students\n");
    printf("-------------------------------------------------------------\n");

    // Display information for each student in the file
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        // Display student information in a table
        printf(" Student No.%-2d >> ITP: %-10.2f DM: %-10.2f SAD: %-10.2f\n",
               student.studentNumber,
               student.dmMark, student.itpMark, student.sadMark);
    }

    // Close the file after reading data
    fclose(file);
}

void searchByStudentNo(FILE *file, int targetStudentNo){
     struct Student student;
    int found = 0;

    // Rewind the file to the beginning
    rewind(file);

    // Search for the target student number
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        if (student.studentNumber == targetStudentNo) {
            // Display student information
            printf("\nStudent %d Information for %s:\n", student.studentNumber, student.name);
            printf("Student %d - DM: %.2f\n", student.studentNumber, student.dmMark);
            printf("Student %d - ITP: %.2f\n", student.studentNumber, student.itpMark);
            printf("Student %d - Sad: %.2f\n", student.studentNumber, student.sadMark);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student number %d not found.\n", targetStudentNo);
    }
}
