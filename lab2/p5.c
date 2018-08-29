#include<stdio.h>
#include<omp.h>

void main()
{
	int a[9]={5,4,3,2,1,2,6,9,8};
	int n=9,i;
	printf("The array elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	int sum=0;

	#pragma omp parallel num_threads(4)
	{
		#pragma omp for ordered reduction(+:sum)
		for (i = 0; i < n; ++i)
		{
			sum+=a[i];
		}
	}

	printf("\n%d\n",sum );
}