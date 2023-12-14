//Lab 8 Exercise - Question 2

#include <stdio.h> 

int main()
{
	char str[50], ch, *ch2;
	int i = 0;

	printf("Enter a string: ");
	gets(str);
	printf("Enter a character to find its frequency: ");
	scanf("%c", &ch);
	ch2 = &str[0];
	
	while(*ch2 != '\0')
	{
		if(ch == *ch2)
			i++;
		ch2++; //*ch2++
	}
	printf("Frequency of %c = %d.\n", ch, i);
	
	return 0;
}

