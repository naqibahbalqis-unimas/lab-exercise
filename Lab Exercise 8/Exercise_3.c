
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
	 fgets(words, sizeof(words), stdin);
	
	reverseText(words);


}

char reverseText(char words[]){
	    printf ("\nAfter the reverse of a string: %s ", strrev(words)); 
}