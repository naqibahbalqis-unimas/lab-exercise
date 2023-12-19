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
    int i = 0;
    if (str[0] != '\0') {
        str[0] = toupper(str[0]);
    }else{
        str[i] = tolower(str[i]);
    }

    printf("The proper case for you is as follows: %s\n", str);

}
