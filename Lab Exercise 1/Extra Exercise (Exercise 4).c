#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
    char name[250];
    FILE *file;  // File pointer for writing to a text file

    file = fopen("Greeting.txt", "w");  // Open or create the text file for writing

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Enter your name: ");
    scanf(" %[^\n]", name);  // Use the correct format specifier to read the whole line, including spaces

    fprintf(file, "Enter your name: %s\n", name);
    fprintf(file, "Hello %s! Nice to meet you.", name);

    fclose(file);  // Close the file
    system("notepad Greeting.txt");

    return 0;
}
