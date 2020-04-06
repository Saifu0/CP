#include<stdio.h>
void main()
{
	int age,prm,city,amnt;
	char chr;
	printf("enter the age");
	scanf("%d",&age);
	printf("enter the gender\n");
	scanf(" %c",&chr);
	//fgets(chr);
	printf("enter the city\n");
	scanf("%d",&city);
	if(age>25&&age<35&&chr=='m'&&city==1)
	{
		printf("enter the amount\n");
		scanf("%d",&amnt);
		prm=amnt*4;
		if(prm<200000)
		{
			printf("pemium amount=%d",prm);
		}
		else
		{
			printf("policy amountcannot exceed");
		}
	}
	else
	printf("invalid input");
}



