#include <stdio.h>

void printArgs(int argc, char *argv[]);

int main (int argc, char **argv)
{
	printArgs(argc, argv);

	return 0;
}

void printArgs(int argc, char *argv[])
{
	int i;

	printf("There are %d arguments\n", argc);

	for (i = 0; i < argc; i++)
	{
		printf("argument %d = %s\n", i, argv[i]);
	}

}
