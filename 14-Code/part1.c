#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int val;
	struct node *next;
}node_t;

int delete(node_t** list)
{
	int num,count=0, flag=0;
	node_t *temp = (*list);
	printf("\nEnter the number for delete:");
	scanf("%d",&num);
	if(num == 0)
	{
		temp = (*list);
		(*list) = (*list)->next;
		free(temp);
		flag = 2;
	}
	else
	{
		while((*list) != NULL)
		{
			if((*list)->val > num)
			{
				if(count == 0)
				{
					flag = 1;
				}
				temp->next = (*list)->next;
			}
			temp = (*list);
			(*list) = (*list)->next;
			count++;
		}
	}
	return flag;
}


int main()
{
	node_t *list, *head, *temp;
	int num,count=0, flag;
	printf("\n Creating linked list, -1\n");
	do
	{
		printf("Enter value: ");
		scanf("%d",&num);
		if(num != -1)
		{
			list = (node_t *) malloc(sizeof(node_t));
			list->val = num;
			list->next = NULL;
			if(count == 0) 
			{
				head = list;
				temp = list;
			}
			else
			{
				temp->next = list;
				temp = list;
			}
			list = list->next;
		}
		count++;
	}while(num != -1);
	temp = head;
	flag = delete(&temp);
	if(flag == 1) head = head->next;
	else if(flag == 2) head = NULL;
	temp = head;
	while(temp != NULL)
	{
		printf("%d->",temp->val);
		temp = temp->next;
	}


}