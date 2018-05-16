#include <stdio.h>

int main()
{
	char letter;

	printf("\n\nType words. \n\nWhen you can't handle it any longer...\n\npress CTRL-D.\n\n");

	while((letter = getchar()) != EOF)
	{
		putchar(letter);
		putchar(letter);
	}
	
	printf("\nYou're a wimp.\n\nWimp.\n\n");

	return 0;
}
