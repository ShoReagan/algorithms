/* Coding Assignment 2 */
//Sho Reagan 1001925250
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <time.h>

typedef struct node
{
	int number;
	struct node *next_ptr;
}
NODE;

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

void AddNodeToLL(int Number, NODE **LinkedListHead)
{
	NODE *newNode;
	newNode = malloc(sizeof(NODE));
	newNode->number = Number;
	newNode->next_ptr = NULL;

	NODE *tempNode;
	tempNode = *LinkedListHead;

	while(tempNode->next_ptr != NULL)
		tempNode = tempNode->next_ptr;
	tempNode->next_ptr = newNode;
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

void ReadFileIntoLL(int argc,  char *argv[], NODE **LLH)
{
	FILE *fp;
	char buffer[10];
	long sum = 0;
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
		sum += atoi(buffer);
		NODE *newNode;
		newNode = malloc(sizeof(NODE));
		newNode->number = atoi(buffer);
		newNode->next_ptr = NULL;

		NODE *tempNode = *LLH;

		if(*LLH == NULL)
		{
			*LLH = newNode;
		}
		else
		{
			while(tempNode->next_ptr != NULL)
				tempNode = tempNode->next_ptr;
			tempNode->next_ptr = newNode;
		}
	}
	printf("\n%d records were read for a total sum of %ld\n", counter, sum);
}

void PrintLL(NODE *LLH) 
{ 
	NODE *tempNode = LLH;
	while(tempNode != NULL)
	{
		printf("\n%p %d %p\n",tempNode, tempNode->number, tempNode->next_ptr);
		tempNode = tempNode->next_ptr;
	}

}

void PrintArray(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void FreeLL(NODE **LLH) 
{
	NODE *tempNode;
	int counter = 0;
	long sum = 0;
	while(*LLH != NULL)
	{
		tempNode = *LLH;
		*LLH = (*LLH)->next_ptr;
		#ifdef PRINT
		printf("\nFreeing %p %d %p\n", tempNode, tempNode->number, tempNode->next_ptr);
		#endif
		counter++;
		sum += tempNode->number;
		free(tempNode);
	}
	printf("\n%d nodes were deleted for a total sum of %ld\n", counter, sum);
}

int main(int argc, char *argv[]) 
{ 
	int *arr = NULL;
	clock_t start, end;

	int size = ReadFileIntoArr(argc, argv, &arr);
	#ifdef PRINTARRAY
		PrintArray(arr, size);
	#endif
	
	start = clock();
	insertionSort(arr, size);
	end = clock();

	#ifdef PRINTARRAY
		printf("\n\n");
		PrintArray(arr, size);
		printf("\n");
	#endif

	printf("Processed %d records\n", size);
	printf("Insertion Sort Tics = %ld\n", end - start);
	
	return 0; 
} 
