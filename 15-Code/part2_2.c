#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
	int num;
	struct list* next_num;
}list;

int find(int number)
{
	int i;
	int sum=0;
	for(i=1; i<number; i++)
	{
		if(number % i == 0)
		{
			sum += i;
		}
	}
	if(sum == number && sum != 0) return 1;
	else return 0;
}
void listl(int number, list** llist)
{
	int i;
	list* new;
	list* temp = (*llist);
	for(i=1; i<number; i++)
	{
		if(number % i == 0)
		{
			new = (list*)malloc(sizeof(list));
			new->num = i;
			temp->next_num = new;
			temp = new;
			new->next_num = NULL;
		}
	}
}

int main()
{
	list* llist;
	int i;
	llist = (list*)malloc(sizeof(list));
	for(i=1; i<=1000; i++)
	{
		if(find(i) == 1)
		{
			printf("%d\n",i);
			listl(i , &llist);
		}
	}
	printf("\n");
	while(llist!= NULL)
	{
		printf("%d ", llist->num);
		llist=llist->next_num;
	}
	return 0;
}