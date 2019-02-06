#include <stdio.h>
int lcm (int number_1, int number_2 , int largest)
{
	if(number_2 != 0)
	{
		return lcm(number_2, number_1%number_2 , largest);
	}
	else return largest / number_1;
}

int count_of_vowels(const char *text, char *vowels, int vowels_count)
{
	int i;
	if(*text != '\0')
	{
		for(i = 0; vowels[i] != '\0'; i++)
		{
			if(*text == vowels[i]) vowels_count++;
		}
		return count_of_vowels(text+1, vowels, vowels_count);
	}
	else return vowels_count;

}

int max_of_aray(const int *arr, int arr_size, int largest)
{
	if(arr_size != 0)
	{
		if(arr[0] >= largest) largest = arr[0];
		max_of_aray(arr+1, arr_size-1, largest);
	}
	else return largest;
}

int main()
{
	int num1,num2,res;
	printf("Enter the numbers: ");
	scanf("%d%d",&num1,&num2);
	res = lcm(num1,num2,num1*num2);
	printf("LCM of %d and %d is %d", num1, num2, res);

	char text[100];
	char vowels[11] = {'a','A','e','E','i','I','o','O','u','U'};
	int vowels_count = 0, res2;
	res2 = count_of_vowels("This is an example. Try to get numbers of vowels that are in the sentence.", vowels, vowels_count);
	printf("\n\nNumber of Vowels = %d", res2);

	int arr[10] = {12,1,162,523,22,621,76,36,57,235};
	int largest, index=0;
	largest = max_of_aray(arr, 10 , 0);
	for( index = 0 ; arr[index] != largest; index++);
	printf("\n\nIndex of maximum item in the array is %d and the number is %d", index, largest);
	return 0; 
}
