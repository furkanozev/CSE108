#include <stdio.h>

int f(int n)
{
	int x;
	if(n == 1) {x = 3;}
	else if(n == 2) x = 5;
	else if(n % 2 == 0) x = f(n-1) + f(n-2);
	else if(n % 2 == 1) x = f(n-1) - f(n-2);
	return x;
}


int main()
{
	int num,i;
	printf("Enter number: ");
	scanf("%d", &num);
	for(i=1; i<=num; i++)
	{
		printf("\nf( %d ) = %d",i,f(i));
	}
	return 0;
}