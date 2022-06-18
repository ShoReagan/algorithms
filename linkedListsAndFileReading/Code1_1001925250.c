/* Coding Assignment 1 */
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
	NODE *LLH = NULL;
	clock_t start, end;
	
	/* capture the clock in a start time */
	start = clock();
	ReadFileIntoLL(argc, argv, &LLH);
	end = clock();
	/* capture the clock in an end time */
	printf("\n%ld tics to write the file into the linked list\n", end-start);

	/* capture the clock in a start time */
	#ifdef PRINT
	start = clock();
	PrintLL(LLH);
	/* capture the clock in an end time */
	end = clock();
	printf("\n%ld tics to print the linked list\n", end-start);
	#endif
	
	/* capture the clock in a start time */
	start = clock();
	FreeLL(&LLH);
	/* capture the clock in an end time */
	end = clock();
	printf("\n%ld tics to free the linked list\n", end-start);
	
	return 0; 
} 
