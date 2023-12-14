#include <stdio.h>
#include <string.h>

int isPalindrome(char *);

int main() {
    char word[100];

    printf("Enter a word: ");
    scanf("%s", word);

    if (isPalindrome(word)) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}

int isPalindrome(char *word) {
    int length = strlen(word);
    char *start = word;
    char *end = word + length - 1;

    while (start < end) {
        if (*start != *end) {
            return 0;  // Not a palindrome
        }
        start++;
        end--;
    }

    return 1;  // Palindrome
}
