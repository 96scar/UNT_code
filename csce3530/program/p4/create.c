#include <stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("file.txt", "w");
	
	char hi = 'a';
	
	int i =0;
	while(i<1024)
	{
		fprintf(fp, "%c", hi);
		i++;
	}
	
	fclose(fp);
	return 0;
}