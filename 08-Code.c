#include <stdio.h>


void pretty_print(int grid[][9]);
int is_valid_row(int grid[][9], int row);
int is_valid(int grid[][9]);
int is_valid_column(int grid[][9], int col);
int is_valid_block(int grid[][9], int r, int c);

void read_a_solution(int grid [][9], char * file_name);
void print_board(int grid[][9]);
void test_game(char * file_name);


int main() {
	test_game("game001.txt");
	test_game("game002.txt");
}


void pretty_print(int grid[][9]) {
	int i,j;
	for(i=0 ; i<9 ; i++)
	{
		if(i==0 || i==3 || i== 6)
		{
			printf("-------------------------");
		}
		printf("\n| ");
		for(j=0 ; j<9 ; j++)
		{
			printf("%d ",grid[i][j]);
			if(j==2 || j==5)
			{
				printf("| ");
			}
		}
		printf("|\n");
	}
	printf("-------------------------\n");
}


int is_valid_row(int grid[][9], int row) {
	int i,j,check=0;
	int array[10]={0};
	for(j=0 ; j<10 ; j++)
	{
		for(i=0 ; i<9; i++)
		{
			if(grid[row][i] == j)
			{
				array[j] += 1;
			}
		}
		if((j == 0 && array[j] != 0) || (j != 0 && array[j] != 1))
		{
			check = -1;
		}
	}
	if(check == 0)
	{
		return 1;
	}
	else return 0;
}


int is_valid_column(int grid[][9], int col) {
	int i,j,check=0;
	int array[10]={0};
	for(j=0 ; j<10 ; j++)
	{
		for(i=0 ; i<9; i++)
		{
			if(grid[i][col] == j)
			{
				array[j] += 1;
			}
		}
		if((j == 0 && array[j] != 0) || (j != 0 && array[j] != 1))
		{
			check = -1;
		}
	}
	if(check == 0)
	{
		return 1;
	}
	else return 0;
}


int is_valid_block(int grid[][9], int r, int c) {
	int i,j,k,check=0,array[10]={0};
	for(i=0 ; i<10; i++)
	{
		for(k=r*3 ; k<r*3+3; k++)
		{
			for(j=c*3 ; j<c*3+3; j++)
			{
				if(grid[k][j] == i)
				{
					array[i] += 1;
				}
			}
		}
		if((i == 0 && array[i] != 0) || (i != 0 && array[i] != 1))
		{
			check = -1;
		}
	}
	if(check == 0)
	{
		return 1;
	}
	else return 0;
}


int is_valid(int grid[][9]) {
	int i,j,check1=0,check2=0,check3=0;
	for(i=0 ; i<9; i++)
	{
		check1 += is_valid_row(grid, i);
	}
	for(i=0 ; i<9; i++)
	{
		check2 += is_valid_column(grid, i);
	}
	for(i=0 ; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			check3 += is_valid_block(grid, i, j);
		}
	}
	if(check1+check2+check3 == 27)
	{
		return 1;
	}
	else return 0;
}


void read_a_solution(int grid [][9], char * file_name) {
	FILE * fin;
    int i, j;

	fin = fopen(file_name, "rt");
	if (fin==NULL) {
		printf("Cannot open file %s for reading the game...\n", file_name);
	}
	else {
	    for (i = 0; i < 9; i++)
	        for (j = 0; j < 9; j++)
	            fscanf(fin, "%d", &grid[i][j]);
	}
}


void print_board(int grid[][9]) {
    int i, j;

	for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}


void test_game(char * file_name) {
    int grid[9][9];
	printf("Testing game in %s.............................\n", file_name);
    read_a_solution(grid, file_name);
	pretty_print(grid);
	print_board(grid);
    if (is_valid(grid)==1)
       printf("Valid solution\n");
    else
		printf("Invalid solution\n");
}
