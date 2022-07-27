//Sho Reagan 1001925250
#include <stdio.h>
#include <string.h>
#define MAX 6

int ReadFileIntoArr(int argc, char *argv[], char *arr, int **matrix)
{
	FILE *fp;
	char buffer[16];
	char holder[16];
	int counter = 0;
	int x = 0;

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
		arr[counter] = strtok(buffer, ",");
		counter++;
	}
	
	fseek(fp, 0, SEEK_SET);

	return counter;
}

int main(int argc, char *argv[])
{

}