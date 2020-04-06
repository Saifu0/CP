#include<stdio.h>
void main()
{
	int n, i, z;
	printf("enter the value of n");
	scanf("%d",&n);
	if(n==0||n==1)
	{
		z=0;
	}
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			z=0;
			break;
		}
	}
	if(z==0)
		printf("not prime");
	else
		printf("prime");
}
