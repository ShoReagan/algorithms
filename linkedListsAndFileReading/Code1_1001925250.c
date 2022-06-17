/* Coding Assignment 1 */
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
}

void ReadFileIntoLL(int argc,  char *argv[], NODE **LLH)
{
	FILE *fp;
	char buffer[10];

	if(argc == 1) 
	{
		printf("File must be provided on command line...exiting");
	}
	else
	{
		fp = fopen(argv[1], "r");
		if(fp == NULL)
		{
			printf("Invalid file name");
			exit(0);
		}
	}
	while(fgets(buffer, 10, fp) != NULL)
	{
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
}

void PrintLL(NODE *LLH) 
{ 
	NODE *tempNode = LLH;
	while(tempNode != NULL)
	{
		printf("\n%d", tempNode->number);
		tempNode = tempNode->next_ptr;
	}

}

void FreeLL(NODE **LLH) 
{ 
}

int main(int argc, char *argv[]) 
{ 
	NODE *LLH = NULL;
	clock_t start, end;
	
	/* capture the clock in a start time */
	ReadFileIntoLL(argc, argv, &LLH);
	/* capture the clock in an end time */
	//printf("\n%ld tics to write the file into the linked list\n", end-start);

	/* capture the clock in a start time */
	PrintLL(LLH);
	/* capture the clock in an end time */
	//printf("\n%ld tics to print the linked list\n", end-start);
	
	/* capture the clock in a start time */
	//FreeLL(&LLH);
	/* capture the clock in an end time */
	//printf("\n%ld tics to free the linked list\n", end-start);
	
	return 0; 
} 
