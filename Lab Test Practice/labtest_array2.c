#include <stdio.h>

#define MAX_SIZE 100

int findChar(const char *str, char target) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            return i; // Return the index where the character is found
        }
    }

    return -1; // Return -1 if the character is not found
}

int main() {
    char str[MAX_SIZE];
    char target;

    // Input: Get the string from the user
    printf("Enter a string (up to %d characters): ", MAX_SIZE - 1);
    gets(str);
    // Input: Get the target character from the user
    printf("Enter the target character: ");
    scanf(" %c", &target);

    int index = findChar(str, target);

    if (index != -1) {
        printf("Character '%c' found at index %d.\n", target, index);
    } else {
        printf("Character '%c' not found in the array.\n", target);
    }

    return 0;
}
