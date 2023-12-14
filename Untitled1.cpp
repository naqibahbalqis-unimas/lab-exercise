#include <stdio.h>
#include <windows.h>

int main() {
    char studentName[250];
    int matricNumber;
    char studentNickname[250];
    char answer;

    FILE *file;  // File pointer for writing to a text file

    file = fopen("student_info.txt", "w");  // Open or create the text file for writing

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    fprintf(file, "Student name                Matric No.              Nickname\n");
    fprintf(file, "====================================================\n");

    do {
        printf("Enter student name: ");
        scanf("%s", studentName);
        printf("Enter student matric number: ");
        scanf("%d", &matricNumber);
        printf("Enter student nickname: ");
        scanf("%s", studentNickname);

        fprintf(file, "%-27s %-22d %-20s\n", studentName, matricNumber, studentNickname);
        printf("Student name \t\t\t Matric No. \t\t\t Nickname\n");
        printf("===================================================================\n");
        printf("%-27s %-22d %-20s\n", studentName, matricNumber, studentNickname);

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &answer);  // Notice the space before %c to consume any whitespace

    } while (answer == 'Y' || answer == 'y');

    printf("//\\----------------------/\\ - /\\----------------------//\\ \n");
    for (int i = 0; i < 4; i++) {
        Beep(4000, 300);
    }
    printf("Beep! Beep! Beep!\n");
    fprintf(file, "//\\----------------------/\\ - /\\----------------------//\\ \n");
    fprintf(file, "Beep! Beep! Beep!\n");

    fclose(file);  // Close the file
    system("notepad student_info.txt");

    return 0;
}
