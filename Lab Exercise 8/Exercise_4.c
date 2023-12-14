#include <stdio.h>
#include <ctype.h>

void propercase(char[]);

int main() {
    char str[250];

    printf("Enter your string: ");
    fgets(str, sizeof(str), stdin);

    propercase(str);


    return 0;
}

void propercase(char str[]) {
    if (str[0] != '\0') {
        str[0] = toupper(str[0]);
    }

    printf("The proper case for you is as follows: %s\n", str);

}
