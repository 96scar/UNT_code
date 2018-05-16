#include <stdio.h>
#include <stdlib.h>

int main()
{
	//char *buff = (char *) malloc (128);
	char buff[128];
	
	FILE *fp, *fp2;
	fp = fopen("file.txt", "rb");
	//system("rm copy.txt");
	fp2 = fopen("copy.txt", "w");
	
	if(fp == NULL)
	{
		printf("File error\n");
		exit(1);
	}
	
	int i=0;
	while(i<8)
	{
		printf("i: %d\n", i);
		fseek(fp, 128*i, SEEK_SET);
		fread(buff, 1, 128, fp);	
		printf("buff: %s\n", buff);
		fprintf(fp2, "%s", buff);
		
		i++;
	}
	
	fclose(fp);
	//free(buff);
	
	return 0;
}