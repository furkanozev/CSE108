#include <stdio.h>
#include <stdlib.h>
typedef struct Dyn_arr
{
	int *array;
	int size;
	int index;
}Dyn_arr;

void init(Dyn_arr *arr)
{
	int i;
	for(i=0; i<arr->size; i++)
	{
		arr->array[i] = 0;
	}
	arr->index = 0;
}

void add_to_last(Dyn_arr *arr, int input_value)
{
	int i;
	int *array_temp;
	int temp_size, temp_index;
	if(arr->index != arr->size)
	{
		arr->array[arr->index] = input_value;
		arr->index = arr->index + 1;
	}
	else
	{
		array_temp = (int *)calloc(arr->size,sizeof(int));
		temp_size = arr->size+5;
		temp_index = arr->index;
		for(i=0; i<arr->index; i++)
		{
			array_temp[i] = arr->array[i]; 
		}
		free(arr->array);
		arr->array = (int *)calloc(temp_size,sizeof(int));
		arr->size = temp_size;
		arr->index = temp_index;
		init(arr);
		arr->size = temp_size;
		arr->index = temp_index;
		for(i=0; i<arr->index; i++)
		{
			arr->array[i] = array_temp[i]; 
		}
		arr->array[arr->index] = input_value;
		arr->index = arr->index + 1;
		free(array_temp);
	}

}

void insert_after(Dyn_arr *arr, int index, int input_value)
{
	int i;
	int *array_temp;
	int temp_size, temp_index;
	if(arr->index != arr->size)
	{
		for(i=index+1; i<arr->index; i++)
		{
			arr->array[i+1] = arr->array[i];
		}
		arr->array[index+1] = input_value;
		arr->index = arr->index + 1;
	}
	else
	{
		array_temp = (int *)calloc(arr->size,sizeof(int));
		temp_size = arr->size+5;
		temp_index = arr->index;
		for(i=0; i<arr->index; i++)
		{
			array_temp[i] = arr->array[i]; 
		}
		free(arr->array);
		arr->array = (int *)calloc(temp_size,sizeof(int));
		arr->size = temp_size;
		arr->index = temp_index;
		init(arr);
		arr->size = temp_size;
		arr->index = temp_index;
		for(i=0; i<arr->index; i++)
		{
			arr->array[i] = array_temp[i]; 
		}
		arr->array[arr->index] = input_value;
		arr->index = arr->index + 1;

		for(i=index+1; i<arr->index; i++)
		{
			arr->array[i+1] = arr->array[i];
		}
		arr->array[index+1] = input_value;
		arr->index = arr->index + 1;
		free(array_temp);
	}
}


int main()
{
	Dyn_arr arr;
	arr.size = 5;
	arr.index = 0;
	arr.array = (int *)calloc(arr.size,sizeof(int));
	int i=0, num=0, input_value, index;
	printf("MENU");
	printf("\n1.Init");
	printf("\n2.Add");
	printf("\n3.İnsert");
	while(num != -1)
	{
		printf("\nMake chooice: ");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				init(&arr);
				break;
			case 2:
				printf("\n Enter the input value: ");
				scanf("%d", &input_value);
				add_to_last(&arr, input_value);
				break;
			case 3:
				printf("\n Enter the input value: ");
				scanf("%d", &input_value);
				printf("\n Enter the index: ");
				scanf("%d", &index);
				insert_after(&arr, index, input_value);
				break;
			default: 
				printf("\nWrong chooice");
		}
		printf("\n");
		for(i=0; i<arr.size; i++)
		{
			printf("%d ",arr.array[i]);
		}
		printf("\n");
	}
	free(arr.array);



}
