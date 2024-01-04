#include <stdio.h>
#include <ctype.h>
#include <string.h>
char name[50];
int matricNo;
char major[3];
int choice;
char targetMajor[3];
FILE *cfPtr;
FILE *file;

void readData();
void writeData();
void searchByMajor(const char targetMajor[]);
int main() {
    int menu;

    do {
        printf("Enter 1 to write data to file\n");
        printf("Enter 2 to read data from file\n");
        printf("Enter your choice: ");

        while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
            printf("Invalid choice. Enter 1 or 2: ");
            while (getchar() != '\n');  // Clear input buffer
        }

        switch (choice) {
            case 1:
                writeData();
                break;
            case 2:
                readData();
                break;
            case 3:
                printf("Enter the major to search (e.g., SE, MC): ");
                scanf("%s", targetMajor);
                searchByMajor(targetMajor);
                break;
        }

        printf("Enter 1 to return to the menu, or any other number to exit: ");
        while (scanf("%d", &menu) != 1) {
            printf("Invalid input. Enter 1 or any other number: ");
            while (getchar() != '\n');  // Clear input buffer
        }

    } while (menu == 1);

    return 0;
}

void readData(){

    // Open the file in read mode
    if ((file = fopen("student.dat", "r")) == NULL) {
        printf("File could not be opened\n");
    } else {
        printf("\n%-10s%-10s%-10s\n", "Name", "Matric No", "Major");
        printf("--------------------------------\n");

        // Read and display student details from the file
        while (fscanf(file, "%s%d%s", name, &matricNo, major) == 3) {
            printf("%-10s%-10d%-10s\n", name, matricNo, major);
        }

        fclose(file);  // Close the file after reading data
    }
}
void writeData(){
    if ((cfPtr = fopen("student.dat", "a")) == NULL) {
        printf("File could not be opened\n");
    } else {
        printf("Enter the student name, matric number and major\n");
        printf("Enter EOF to end input.\n");
        printf("? ");

        // write data to file
        while (scanf("%s%d%s", name, &matricNo, major) == 3) {
            fprintf(cfPtr, "%s %d %s\n", name, matricNo, major);
            printf("? ");
        }

        fclose(cfPtr);  // Close the file after writing data
    }
}

void searchByMajor(const char targetMajor[]) {
    // Open the file in read mode
    if ((file = fopen("student.dat", "r")) == NULL) {
        printf("File could not be opened\n");
    } else {
        int found = 0;

        printf("\n%-10s%-10s%-10s\n", "Name", "Matric No", "Major");
        printf("--------------------------------\n");

        // Read and display student details from the file matching the target major
        while (fscanf(file, "%s%d%s", name, &matricNo, major) == 3) {
            if (strcmp(major, targetMajor) == 0) {
                printf("%-10s%-10d%-10s\n", name, matricNo, major);
                found = 1;
            }
        }

        if (!found) {
            printf("No students found with major %s\n", targetMajor);
        }

        fclose(file);  // Close the file after reading data
    }
}
