#include <stdio.h>

int main()
{
	int i, j, n; //set value of variables later
	
	printf("\nEnter a positive number: "); //.asciiz input
	scanf("%d", &n); //ask input
	
	for(i=1; i<=n; i++) //FOR1:
	{
		for(j=1; j<=(n-i); j++) //FOR2:
			printf("  "); //.asciiz spaces
		
		for(j=1; j<=i; j++) //FOR3:
			printf("* "); //.asciiz stars
	
		printf("\n"); //newline character
	}
	
	return 0; //syscall 10
}