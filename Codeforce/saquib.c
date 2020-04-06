#include<stdio.h>

int main(){
	int apin,amnt;
	printf("enter the atm pin");
	scanf("%d",&apin);
	if(apin>=1000&&apin<10000)
	{
		printf("enter thw amount");
        	scanf("%d",&amnt);
		if(amnt<=20000)
		{
			printf("cash withdrawal");
		}
		else
		{
			printf("limit cross");
		}
	}
	else 
	{
		printf("invalid pin");
	}
		  


	return 0;
}
