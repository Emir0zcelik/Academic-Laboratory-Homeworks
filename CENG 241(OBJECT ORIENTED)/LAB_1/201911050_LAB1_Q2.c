#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int n, i;
	double *storage;
	
	printf("Pointer : Find the largest element using Dynamic Memory Allocation\n");
	printf("---------------------------------------------------------------------------\n");
	printf("Input total number of elements(1 to 100): ");
	scanf("%d", &n);
	
	storage = (double *)calloc(n, sizeof(double));
	
	if (storage == NULL)
	{
		exit(0);
	}
	
	//Getting numbers
	for(i = 0; i < n; i++)
	{
		printf("Number %d: ", i+1);
		scanf("%lf", storage + i);
	}
	
	//Largest number
	for (i = 0; i < n; i++)
	{
		if (*storage < *(storage + i))
		{
			*storage = *(storage + i);
		}
	}
	
	printf("The Largest element is : %.2lf" , *storage);
	
	free(storage);
	
	return 0;
}
