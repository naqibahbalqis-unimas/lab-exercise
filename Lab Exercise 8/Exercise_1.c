#include <stdio.h>
#include <ctype.h>
void main (void)
{
char ch;
printf ("Enter a character, any character including symbol: ");
scanf ("%c", &ch);
/*copy paste the following code here, one by one and observe the result*/
if(islower(ch)){
	printf("%c is a lowercase letter\n", ch);
}

if(isupper(ch)){
	printf("%c is a uppercase letter\n", ch);
}

 if(isalpha(ch)){
 	printf("%c is a letter\n", ch);
 }
 
 if(isdigit(ch)) 
 {
 	printf("%c is a  digit\n", ch);
 }

 if(isalnum(ch))
 {
 	 printf("%c is a alphanumeric character\n", ch);
 }
 
 if(isxdigit(ch)){
 	printf("%c is a hexadecimal digit\n", ch);

 }
 if(ispunct(ch))
 {
 printf("%c is a punctuation character\n", ch);	
 }

}

