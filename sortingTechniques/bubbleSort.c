#include <stdio.h>
#define MAX 100


void bubbleSort(int x[], int n)
{
	int i,j,lock;
	
	lock = 1;
	for(i=0; i<n-1 && lock ; i++)
	{
		lock = 0;
		for(j=0; j<n-1-i ;j++)
		{
			if(x[j]>x[j+1])
			{
				//swapping 
				x[j] = x[j] ^ x[j+1];
				x[j+1] = x[j] ^ x[j+1];
				x[j] = x[j] ^ x[j+1];
				lock = 1;
			}
		}
	}
}


int main()
{
	int x[MAX],n,i;
	
	printf("\nEnter the no of elements u want in the array : ");
	scanf("%d",&n);
	

	printf("\nEnter %d elements 1 by 1 : ",n);

	for(i=0; i<n; i++)
		scanf("%d",(x+i));

	printf("\nYour array contains : ");
	for(i=0; i<n; i++)
		printf("%d ",*(x+i));

	//calling the function bubble sort 
	bubbleSort(x,n);

	printf("\nYour sorted array : ");
	for(i=0; i<n; i++)
		printf("%d ",x[i]);


return 0;
}

