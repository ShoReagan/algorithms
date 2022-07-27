#include <stdio.h>

int FunctionR(int z[], int a, int b, int e, int f)
{
	printf("%d-", z[e] + z[f]);

	if(a >b)
	{
		z[e] -= z[f];
		FunctionR(z, z[f+1], z[e+1], f, e);
		printf("%d-", z[f-1]+z[e-1]);
	}
}

int main(void)
{
	int a[] = {1032, 687, 648, 765, 981};
	int x = 2;
	int y = 3;

	FunctionR(a, a[0], a[1], x, y);

	return 0;
}