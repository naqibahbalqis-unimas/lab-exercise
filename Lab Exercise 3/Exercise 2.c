#include <stdio.h>
#include <ctype.h>

int main (){
    char word;

    printf("Enter a Character:");
    scanf("%c", &word);
    printf("Your Character is %c\n", word);

    if(word == 'e' || word == 'E'){
        for(int i=1;i<=5;i++){
            printf("E");
        }

    }else{
        printf("Your Character is not E\n");
    }

        return 0;
}