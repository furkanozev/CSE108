#include <stdio.h>
typedef union
{
	double roll_no;
	char name[20];
	int age;
	char address[20];
}stdinfo;



int main()
{
	stdinfo stud[5][4];
	int i;
	for(i=0; i<5; i++)
	{
		printf("\n Enter the roll_no %d.student: ", i+1);
		scanf("%lf", &stud[i][0].roll_no);
	}
	for(i=0; i<5; i++)
	{
		printf("\n Enter the student name %d.student: ", i+1);
		scanf("%s", stud[i][1].name);
	}
	for(i=0; i<5; i++)
	{
		printf("\n Enter the student age %d.student: ", i+1);
		scanf("%d", &stud[i][2].age);
	}
	for(i=0; i<5; i++)
	{
		printf("\n Enter the address %d.student: ", i+1);
		scanf("%s", stud[i][3].address);
	}

	for(i=0; i<5; i++)
	{
		printf("\nStudent %d: ", i+1);
		printf("\nStudent roll_no: %lf", stud[i][0].roll_no);
		printf("\nStudent name: %s", stud[i][1].name);
		printf("\nStudent age: %d", stud[i][2].age);
		printf("\nStudent address: %s", stud[i][3].address);
	}


	return 0;
}