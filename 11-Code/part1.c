#include <stdio.h>
typedef struct
{
	char name[20];
	double quiz1;
	double quiz2;
	double midterm;
	double final;
}grade;


int main()
{
	grade course;
	char a;
	double count=0, t_quiz1=0, t_quiz2=0, t_midterm=0, t_final=0, average=0, total=0;
	do
	{
		count++;
		printf("Enter the student's name: ");
		scanf("%s", course.name);
		printf("Enter the student's quiz #1: ");
		scanf("%lf", &course.quiz1);
		printf("Enter the student's quiz #2: ");
		scanf("%lf", &course.quiz2);
		printf("Enter the student's midterm: ");
		scanf("%lf", &course.midterm);
		printf("Enter the student's final: ");
		scanf("%lf", &course.final);
		total = (course.quiz1 + course.quiz2)*10 / 8 + (course.midterm / 4) + (course.final / 2);
		t_quiz1 += course.quiz1;
		t_quiz2 += course.quiz2;
		t_midterm += course.midterm;
		t_final += course.final;
		average += total;
		printf("\n %s's numeric score for the entire course is %lf\n", course.name, total);
		printf("\nWould you like to enter another student record? y(yes) or no(no)?\n");
		scanf(" %c", &a);
	}while(a == 'y');
	printf("\nThe class statictics: \n");
	printf("\nThe average score on quiz1 is %lf", t_quiz1/count);
	printf("\nThe average score on quiz2 is %lf", t_quiz2/count);
	printf("\nThe average score on midterm is %lf", t_midterm/count);
	printf("\nThe average score on final is %lf", t_final/count);
	printf("\nThe average score for the entire course is %lf", average/count);
	return 0;
}