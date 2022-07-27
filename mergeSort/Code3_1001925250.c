/* Coding Assignment 3 */
//Sho Reagan 1001925250
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <time.h>

void merge(int arr[], int left, int middle, int right);

typedef struct node
{
	int number;
	struct node *next_ptr;
}
NODE;

void mergeSort(int arr[], int L, int R)
{
	if(L < R)
	{
		int M = (L + R) / 2;
		mergeSort(arr, L, M);
		mergeSort(arr, M+1, R);
		merge(arr, L, M, R);
	}
}

void merge(int arr[], int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	int L[n1], R[n2];

	for(i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for(j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void insertionSort(int A[], int n)
{
	int i, key, j;

	for(j = 1; j < n; j++)
	{
		key = A[j];
		i = j - 1;

		while(i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}

int ReadFileIntoArr(int argc, char *argv[], int **arr)
{
	FILE *fp;
	char buffer[10];
	int counter = 0;

	if(argc == 1) 
	{
		printf("File must be provided on command line...exiting\n");
		exit(0);
	}
	else
	{
		fp = fopen(argv[1], "r");
		if(fp == NULL)
		{
			printf("Invalid file name\n");
			exit(0);
		}
	}

	while(fgets(buffer, 10, fp) != NULL)
	{
		counter++;
	}
	
	fseek(fp, 0, SEEK_SET);
	*arr = malloc(counter * sizeof(int));


	int i;
	for(i = 0; i < counter; i++)
	{
		fgets(buffer, 10, fp);
		(*arr)[i] = atoi(buffer);
	}

	return counter;
}

void PrintArray(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

int main(int argc, char *argv[]) 
{ 
	int *arr = NULL;
	clock_t mergeStart, mergeEnd, inserStart, inserEnd;

	int size = ReadFileIntoArr(argc, argv, &arr);
	#ifdef PRINTARRAY
	printf("Unsorted Array\n");
		PrintArray(arr, size);
	#endif
	
	mergeStart = clock();
	mergeSort(arr, 0, size-1);
	mergeEnd = clock();

	#ifdef PRINTARRAY
		printf("\nMerge Sort\n");
		PrintArray(arr, size);
		printf("\n");
	#endif

	free(arr);

	size = ReadFileIntoArr(argc, argv, &arr);
	
	inserStart = clock();
	insertionSort(arr, size);
	inserEnd = clock();

	#ifdef PRINTARRAY
		printf("\nInsertion Sort\n");
		PrintArray(arr, size);
		printf("\n");
	#endif

	free(arr);


	printf("Processed %d records\n", size);
	printf("Merge Sort Tics = %ld\n", mergeEnd - mergeStart);
	printf("Insertion Sort Tics = %ld\n", inserEnd - inserStart);
	
	return 0; 
} 
