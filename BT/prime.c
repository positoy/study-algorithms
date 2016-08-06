#include <stdio.h>
#include <stdlib.h>

int isPrime(int n)
{
	int r;

	if (n)
	for (r=2; r*r<n; r++)
	{
		if (n%r == 0)
			return 0;
	}

	return 1;
}

/*********************
 에라토스테네스의 체
 *********************/
int *eratos(int n)
{
	int i,j;
	int* primeArray = malloc(sizeof(int) * (n+1));
 
	if (n < 2)
		return NULL;

	for (i=2; i<=n; i++)
		primeArray[i] = 1;

	for (i=2; i*i<=n; i++)
	{
		for (j=2; i*j<=n; j++)
			primeArray[i*j] = 0;
	}
}

int main()
{
	int i;
	int *primeArray = eratos(255);

	for (i=0; i<256; i++)
		if (primeArray[i])
			printf("%d ", i);

}
