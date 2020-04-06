#include<stdio.h>
void main()
{
	int i,k,j,n;
	printf("enter the value of n");
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
		for(i=k;i>=1;i--)
		{
			printf("%d\t",i);
			if(i==1)
			{
				for(j=2;j<=k;j++)
				{
					printf("%d\t",j);
				}
			}
		}
		printf("\n");
	}
}

