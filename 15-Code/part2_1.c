#include <stdio.h>

typedef struct
{
	double real;
	double imaginary;
}complex;


int main()
{
	complex num1, num2, total;
	char op;
	printf("\n For 1st complex number ");
	printf("\nEnter real and imaginary part respectively: ");
	scanf("%lf",&num1.real);
	scanf("%lf",&num1.imaginary);
	printf("\n For 2nd complex number ");
	printf("\nEnter real and imaginary part respectively: ");
	scanf("%lf",&num2.real);
	scanf("%lf",&num2.imaginary);
	printf("\n Choose your operator: ");
	scanf(" %c",&op);

	switch(op)
	{
		case '+':
			total.real = num1.real + num2.real;
			total.imaginary = num1.imaginary + num2.imaginary;
			break;
		case '-':
			total.real = num1.real - num2.real;
			total.imaginary = num1.imaginary - num2.imaginary;
			break;
		case '*':
			total.real = num1.real * num2.real;
			total.imaginary = num1.imaginary * num2.imaginary * -1;
			break;
	}
	printf("\n\n Sum of these two complex number = %.3lf + %.3lfi ", total.real, total.imaginary);

	return 0;
}