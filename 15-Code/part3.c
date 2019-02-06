#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int num;
	struct list* nlist;
}NODE;

int super_digit(int number)
{
	int num;
	if(number < 10) return number;
	else
	{
		num = number%10 + super_digit(number/10);
		if(num > 9) super_digit(num);
	};
}


int main()
{

	int num;
	scanf("%d", &num);
	printf("The super digit of the %d is %d", num , super_digit(num));
}