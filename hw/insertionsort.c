#include <stdio.h>

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

int main() 
{
	int size = 6;
	int A[] = {329, 131, 561, 200, 782, 331};
	insertionSort(A, size);
	for(int i = 0; i < 6; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}