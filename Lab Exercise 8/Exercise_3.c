
#include <stdio.h> 
#include <string.h>
char getInput();
char reverseText(char[]);


int main(){
	getInput();
}

char getInput(){
	char words[250];
	
	printf("Enter a string: ");
    gets(words);
	reverseText(words);
    return 0;

}

char reverseText(char words[]){
	    printf ("\nAfter the reverse of a string: %s ", strrev(words));
    return 0;

}