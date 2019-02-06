#include <stdio.h>
#include <stdlib.h>
typedef struct str
{
	char name[200];
	char lastname[200];
	int work_year;
	int salary;
	int account_number;
}str;

void fill(str **list, int size, int count)
{
	int i;
	(*list) = (str *) calloc(size,sizeof(str));
	for(i=0 ; i<count; i++)
	{
		printf("\nEnter name: ");
		scanf("%s",(*list)[i].name);
		printf("\nEnter lastname: ");
		scanf("%s",(*list)[i].lastname);
		printf("\nEnter work_year: ");
		scanf("%d",&(*list)[i].work_year);
		printf("\nEnter salary: ");
		scanf("%d",&(*list)[i].salary);
		printf("\nEnter account number: ");
		scanf("%d",&(*list)[i].account_number);
	}
}

void record(str *list, int count)
{
	FILE *input = fopen("data.bin","wb");
	fwrite(&list, sizeof(str), 1, input);
}

void read(str *list, int count)
{
	int i;
	FILE *output = fopen("data.bin","rb");
	fwrite(&list, sizeof(list), 1, output);
	for(i=0 ; i<count; i++)
	{
		printf("\nname: %s",list[i].name);
		printf("\nEnter lastname: %s",list[i].lastname);
		printf("\nEnter work_year: %d",list[i].work_year);
		printf("\nEnter salary: %d",list[i].salary);
		printf("\nEnter account number: %d",list[i].account_number);
		printf("\n");
	}
}

void update(str **list, int count)
{
	int i;
	for(i=0 ; i<count; i++)
	{
		if(2018 - (*list)[i].work_year < 5)
		{
			(*list)[i].salary = (*list)[i].salary + ((*list)[i].salary / 5);
		}
		else
		{
			(*list)[i].salary = (*list)[i].salary + ((*list)[i].salary / 10);
		}
	}
}

int main()
{
	str *account;
	int size, count;
	printf("\nEnter the size of dynamic array : ");
	scanf("%d", &size);
	printf("\nEnter the count : ");
	scanf("%d", &count);
	fill(&account, size, count);

	record(account, count);
	read(account, count);
	update(&account, count);
	record(account, count);
	read(account, count);
}