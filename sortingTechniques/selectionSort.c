#include <stdio.h>
#define MAX 100
void selectionSort(int x[],int n)
{
	int i,j,large,index;

	for(i=n-1; i>=0; i--)
	{
		large = x[0];
		index = 0;

		for(j=1; j<=i; j++)
		{
			if(large<x[j])
			{
				large = x[j];
				index = j;
			}
		}

		x[index] = x[i];
		x[i] = large;
	}
}


int main()
{
	int x[MAX],n,i;


	printf("\nEnter the no of elements u want in the array : ");
	scanf("%d",&n);

	printf("\nENter the array elements 1 by 1 : ");
	for(i=0;i<n;i++)
		scanf("%d", x+i);

	printf("\nYour array contains : ");
	for(i=0;i<n;i++)
		printf("%d ",*(x+i));

	selectionSort(x,n);

	printf("\nYour sorted array : ");
	for(i=0; i<n; i++)
		printf("%d ",*(x+i));

return 0;
}
