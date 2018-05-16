#include <stdio.h>

void sort(int v[], int n);
void swap(int v[], int k);

int main()
{
	int i, val[10];
	
	printf("Enter 10 integer values: ");
	for(i=0; i<10; i++)
	{
		scanf("%d", &val[i]);
	}
	
	sort(val, 10);
	
	printf("Sorted: ");
	for(i=0; i<10; i++)
	{
		printf("%d ", val[i]);
	}
	printf("\n");
	
	return 0;
}

void sort (int v[], int n)
{
	int i, j;
	for (i = 0; i < n; i += 1)
	{
		for (j = i - 1;
		j >= 0 && v[j] > v[j + 1];
		j -= 1)
		{
			swap(v,j);
		}
	}
}

void swap(int v[], int k)
{
	int temp;
	temp = v[k];
	v[k] = v[k+1];
	v[k+1] = temp;
}
