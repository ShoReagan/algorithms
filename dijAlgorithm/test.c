#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 6

void ReadFileIntoArr(int argc, char *argv[], char arr[MAX], int matrix[][MAX])
{
	FILE *fp;
	char buffer[16];
	char *token;
	int counter = 0;
	int index = 0;

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

	while(fgets(buffer, 16, fp) != NULL)
	{
		buffer[strlen(buffer) - 1] = '\0';
		token = strtok(buffer, ",");
		arr[counter] = token[0];
		while(token != NULL)
		{
			token = strtok(NULL, ",");
			if(token != NULL)
				index = atoi(token);
			token = strtok(NULL, ",");
			if(token != NULL)
				matrix[counter][index] = atoi(token);
		}
		counter++;
	}
}

void PrintArr(int matrix[][MAX])
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	int matrix[MAX][MAX];
	char arr[MAX] = " ";
	
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			matrix[i][j] = -1;
		}
	}

	ReadFileIntoArr(argc, argv, arr, matrix);
	PrintArr(matrix);

	return 0;

}