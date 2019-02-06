#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Students
{
	union
	{
		char student_number[12];  
		int social_number;
	}Identifier;
	char name[10];
	char Surname[10];
	int Midterm_01;
	int Midterm_02;
	int Final;
	double grade;
	int Idtype;
}Students;

void create(Students *student)
{
	printf("\n\nEnter name: ");
	scanf("%s", student->name);
	printf("\nEnter surname: ");
	scanf("%s", student->Surname);
	student->Midterm_01 = rand()%100;
	student->Midterm_02 = rand()%100;
	student->Final = rand()%100;
}

void print(Students student)
{
	printf("\n");
	if(student.Idtype == 0)
	{
		printf("\nStudent id: %s", student.Identifier.student_number);
	}
	else
	{
		printf("\nStudent social number: %d", student.Identifier.social_number);
	}
	printf("\nName: %s", student.name);
	printf("\nSurname: %s", student.Surname);
	printf("\nMidterm_01: %d", student.Midterm_01);
	printf("\nMidterm_02: %d", student.Midterm_02);
	printf("\nFinal: %d", student.Final);
	printf("\nGrade: %lf", student.grade);
}

void calc_grade (Students *student)
{
	double temp = 0;
	temp += (double) student->Midterm_01 / 4;
	temp += (double) student->Midterm_02 / 4;
	temp += (double) student->Final / 2;
	student->grade = temp;
}

int main()
{
	srand(time(NULL));
	Students *student;
	Students temp;
	int num,i,x,tempid;
	x = rand()%2;
	printf("Enter the student size: ");
	scanf("%d",&num);
	student = (Students *) calloc(num, sizeof(Students));
	for(i=0 ; i<num; i++)
	{
		create(&temp);
		calc_grade(&temp);
		student[i] = temp;
		if(x%2 == 0)
		{
			tempid = rand()%900+100;
			sprintf(student[i].Identifier.student_number,"2018-CS-%d",tempid);
			student[i].Idtype = 0;
		}
		else
		{
			student[i].Identifier.social_number = rand()%9000+1000;
			student[i].Idtype = 1;
		}
		print(student[i]);
	}

}