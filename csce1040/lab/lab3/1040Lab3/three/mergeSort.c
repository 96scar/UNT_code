#include <stdio.h>
#include <stdlib.h>

#define SIZE 50000	// number of integers to sort

void merge(int [], int, int, int);

void mergesort(int items[], int low, int high)
{
	int mid;

	// ENTER CODE HERE FOR MERGESORT
	int sorted[SIZE]; // SIZE is array size
	int i, j, k;
	i = low; //index for lower division
	j = mid + 1; // low index for higher division
	k = low; // index for the sorted array

	//sort by comparision
	while (i <= mid && j <= high)
	{
		if(items[i] < items[j])
		{
			sorted[k] = items[i];
			k = k +1;
			i = i +1;
		}
		else
		{
			sorted[k] = items[j];
			k = k+1;
			j = j+1;
		}
	}

	//copy remaining items from 1st division
	while (i <= mid)
        {
                        sorted[k] = items[i];
                        k = k +1;
                        i = i +1;
        }
	//copy reamining items from 2nd division
	while(j <= high)
        {
                        sorted[k] = items[j];
                        k = k+1;
                        j = j+1;
        }
	//copy sorted items into original array
	for( i = low; i < k; i = i+1)
	{
		items[i] = sorted[i];
	}



	return;
}

void merge(int items[], int low, int high, int mid)
{
	// ENTER CODE HERE FOR MERGING	
	if(low<high)
	{
		mid = (low + high) /2;
		mergesort(items, low, mid);
		mergesort(items, mid, high);
		merge(items, low, high, mid);
	}
	else
		;
	

	return;
}

int ITEMS[SIZE];

int main(void)
{
	int n = SIZE;
	int i, j;

	srand ((unsigned int)time(NULL));
	for(i = 0; i < n; i++) {
		ITEMS[i] = random() % 1000000;
	}

	printf("\n\n\nThe unsorted array is:\n");
	for(i = 0; i < n/10; i++) {
		for(j = 0; j < 10; j++) {
			printf("%d ", ITEMS[i*10+j]);
		}
		printf("\n");
	}

	mergesort(ITEMS,0,SIZE-1);

	printf("\n\n\nThe sorted array is:\n");
	for(i = 0; i < n/10; i++) {
		for(j = 0; j < 10; j++) {
			printf("%d ", ITEMS[i*10+j]);
		}
		printf("\n");
	}

	return 0;
}

