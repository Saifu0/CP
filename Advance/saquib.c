#include<stdio.h>
void main()
{
	int co,stock;
	char credit[2];
	printf("enter the coustomer");
	scanf("%d",&co);
	printf("enter the stock");
	scanf("%d",&stock);
	printf("enter the credit");
	scanf("%s",&credit);
	if(credit[0]=='O' && credit[1]=='K' &&co<=stock)
		printf("supply has requirement");
	else if(credit[0]=='O'&&credit[1]=='K'&&stock<co)
		printf("%d the balancebwill be shipped",stock);
	else
		printf("send him initimation");

}
