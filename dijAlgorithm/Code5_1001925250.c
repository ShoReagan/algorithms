//Sho Reagan 1001925250
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 6

typedef struct vertex 
{
	int index;
	char label[6];
	int distance;
	int previous;
	int visited;
}
VERTEX;

int ReadFileIntoArr(int argc, char *argv[], VERTEX VertexArray[], int matrix[][MAX])
{
	FILE *fp;
	char buffer[16];
	char *token;
	int counter = 0;
	int index = 0;
	int SmallestVertexIndex;

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
		VertexArray[counter].index = counter;
		VertexArray[counter].visited = 0;
		VertexArray[counter].previous = -1;
		VertexArray[counter].distance = INT_MAX;
		strcpy(VertexArray[counter].label, token);
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
	return counter;
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

void PrintVertexArr(VERTEX VertexArray[MAX])
{
	printf("I    L    D    P    V\n");
	for(int i = 0; i < MAX; i++)
	{
		printf("%-5d%-5s%-5d%-5d %-5d\n", VertexArray[i].index, VertexArray[i].label, VertexArray[i].distance, VertexArray[i].previous, VertexArray[i].visited);
	}
}

void dijAlgo(VERTEX VertexArray[MAX], int matrix[][MAX], int counter)
{
	char startingVertex[6] = " ";
	int CurrentVertex = 0;
	int x;
	int i;
	int j;
	int dofu;
	int cofuv;
	int dofv;
	int SmallestVertexIndex;

	printf("\nWhat is the starting vertex? ");
	scanf("%s", startingVertex);

	for(i = 0; i < counter; i++)
	{
		if(!strcmp(VertexArray[i].label, startingVertex))
			CurrentVertex = VertexArray[i].index;
	}

	VertexArray[CurrentVertex].distance = 0;
	VertexArray[CurrentVertex].previous = -1;
	VertexArray[CurrentVertex].visited = 1;

	for (x = 0; x < counter-1; x++)
	{
		for(i = 0; i < counter; i++)
		{
			if (matrix[CurrentVertex][i] != -1 && !VertexArray[i].visited)  
			{
				dofu = VertexArray[CurrentVertex].distance;
				cofuv = matrix[CurrentVertex][i];
				dofv = VertexArray[i].distance;

				printf("%d %d %d %d %d\n",CurrentVertex, i, dofu, cofuv, dofv);

				if (dofu + cofuv < dofv)
				{
					dofv = dofu + cofuv;
					VertexArray[i].distance = dofv;
					VertexArray[i].previous = CurrentVertex;
				}
			}
		}
		
		SmallestVertexIndex = -1;
		int SmallestVertex = INT_MAX;

		for(i = 0; i < counter; i++)
		{
			if (!VertexArray[i].visited)
			{
				if (VertexArray[i].distance < SmallestVertex)
				{
					SmallestVertex = VertexArray[i].distance;
					SmallestVertexIndex = i;
				}
			}
		}
		CurrentVertex = SmallestVertexIndex;
		VertexArray[CurrentVertex].visited = 1;
	}

}

int main(int argc, char *argv[])
{
	int counter;
	int i;
	int j;
	int matrix[MAX][MAX];
	VERTEX VertexArray[MAX];
	
	for(i = 0; i < MAX; i++)
	{
		for(j = 0; j < MAX; j++)
		{
			matrix[i][j] = -1;
		}
	}

	counter = ReadFileIntoArr(argc, argv, VertexArray, matrix);
	PrintArr(matrix);

	dijAlgo(VertexArray, matrix, counter);

	PrintVertexArr(VertexArray);	

	return 0;

}
