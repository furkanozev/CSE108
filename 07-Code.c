#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum{wall, space, start, finish} def;

void init_maze01(def array[8][8])
{
	int i,j;
	for(i=0 ; i<8 ; i++)
	{
		for(j=0 ; j<8 ; j++)
		{
			if(i==0)
			{
				if(j<6)
				{
					array[i][j]=0;
				}
				array[i][6]=3;
			}
			if(i==1)
			{
				if(j==0 || j==4 || j==7)
				{
					array[i][j]=0;
				}
			}
			if(i==2)
			{
				if(j==0 || j==2 || j==4 || j==7)
				{
					array[i][j]=0;
				}
			}
			if(i==3)
			{
				if(j==0 || j==2 || j==4 || j==7)
				{
					array[i][j]=0;
				}
				if(j==3)
				{
					array[i][j]=2;
				}
			}
			if(i==4)
			{
				if(j==0 || j==2 || j==5 || j==7)
				{
					array[i][j]=0;
				}
			}
			if(i==5)
			{
				if(j==0 || j==2 || j==3 || j==5 || j==7)
				{
					array[i][j]=0;
				}
			}
			if(i==6)
			{
				if(j==0 || j==7)
				{
					array[i][j]=0;
				}
			}
			if(i==7)
			{
					array[i][j]=0;
			}
		}
	}

}

void init_maze02(def array[10][10])
{
	int i,j;
	for(i=0 ; i<10 ; i++)
	{
		for(j=0 ; j<10 ; j++)
		{
			if(i==0)
			{
				array[i][j]=0;
			}
			if(i==1)
			{
				if(j==0 || j==2 || j==6 || j==9)
				{
					array[i][j]=0;
				}
				array[i][1]=2;
			}
			if(i==2)
			{
				if(j==0 || j==2 || j==4 || j==6 || j==8 || j==9)
				{
					array[i][j]=0;
				}
			}
			if(i==3)
			{
				if(j==0 || j==4 || j==6 || j==9)
				{
					array[i][j]=0;
				}
			}
			if(i==4)
			{
				if(j==0 || j==2 || j==4 || j==9)
				{
					array[i][j]=0;
				}
			}
			if(i==5)
			{
				if(j==0 || j==2 || j==4 || j==5 || j==7 || j==9)
				{
					array[i][j]=0;
				}
			}
			if(i==6)
			{
				if(j==0 || j==2 || j==5 || j==7)
				{
					array[i][j]=0;
				}
				array[i][9]=3;
			}
			if(i==7)
			{
				if(j==0 || j==2 || j==3 || j==5 || j==6 || j==7 || j==9)
				{
					array[i][j]=0;
				}
			}
			if(i==8)
			{
				if(j==0 || j==3 || j==9)
				{
					array[i][j]=0;
				}
			}
			if(i==9)
			{
				array[i][j]=0;
			}
		}
	}

}

void show_maze01(def array[8][8])
{
	int i,j;
	for(i=0 ; i<8 ; i++)
	{
		for(j=0 ; j<8 ; j++)
		{
			if(array[i][j]==0)
			{
				printf("*");
			}
			if(array[i][j]==1)
			{
				printf(" ");
			}
			if(array[i][j]==2)
			{
				printf("S");
			}
			if(array[i][j]==3)
			{
				printf("F");
			}
		}
		printf("\n");
	}
}
void show_maze02(def array[10][10])
{
	int i,j;
	for(i=0 ; i<10 ; i++)
	{
		for(j=0 ; j<10 ; j++)
		{
			if(array[i][j]==0)
			{
				printf("*");
			}
			if(array[i][j]==1)
			{
				printf(" ");
			}
			if(array[i][j]==2)
			{
				printf("S");
			}
			if(array[i][j]==3)
			{
				printf("F");
			}
		}
		printf("\n");
	}
}

void move01(def maze[8][8], int pos_x, int pos_y)
{
	int x,counter=0;
	srand(time(NULL));
	while(counter<100)
	{
		x=rand()%4;
		switch(x)
		{
			case 0:
				if(maze[pos_x][pos_y+1]==1)
				{
					if(maze[pos_x][pos_y+1]==3)
					{
						counter = 105;
					}
					maze[pos_x][pos_y]=1;
					maze[pos_x][pos_y+1]=2;
					pos_y += 1;
					break;
				}
				else
				{
					x++;
				}
			case 1:
				if(maze[pos_x][pos_y-1]==1)
				{
					if(maze[pos_x][pos_y-1]==3)
					{
						counter = 105;
					}
					maze[pos_x][pos_y]=1;
					maze[pos_x][pos_y-1]=2;
					pos_y -= 1;
					break;
				}
				else
				{
					x++;
				}
			case 2:
				if(maze[pos_x+1][pos_y]==1)
				{
					if(maze[pos_x+1][pos_y]==3)
					{
						counter = 105;
					}
					maze[pos_x][pos_y]=1;
					maze[pos_x+1][pos_y]=2;
					pos_x +=1;
					break;
				}
				else
				{
					x++;
				}
			case 3:
				if(maze[pos_x-1][pos_y]==1)
				{
					if(maze[pos_x-1][pos_y]==3)
					{
						counter = 105;
					}
					maze[pos_x][pos_y]=1;
					maze[pos_x-1][pos_y]=2;
					pos_x -= 1;
					break;
				}
			
		}
		printf("\n");
		show_maze01(maze);
		counter++;
	}
	if(counter == 106)
	{
		printf("\nOh, trap!");
	}
	else
	{
		printf("\nNothing like freedom!");
	}

}
void move02(def maze[10][10], int pos_x, int pos_y)
{
	int x,counter=0;
	srand(time(NULL));
	while(counter<100)
	{
		x=rand()%4;
		switch(x)
		{
			case 0:
				if(maze[pos_x][pos_y+1]==1)
				{
					if(maze[pos_x][pos_y+1]==3)
					{
						counter = 105;
					}
					maze[pos_x][pos_y]=1;
					maze[pos_x][pos_y+1]=2;
					pos_y+=1;
					break;
				}
				else
				{
					x++;
				}
			case 1:
				if(maze[pos_x][pos_y-1]==1)
				{
					if(maze[pos_x][pos_y-1]==3)
					{
						counter = 105;
					}
					maze[pos_x][pos_y]=1;
					maze[pos_x][pos_y-1]=2;
					pos_y-=1;
					break;
				}
				else
				{
					x++;
				}
			case 2:
				if(maze[pos_x+1][pos_y]==1)
				{
					if(maze[pos_x+1][pos_y]==3)
					{
						counter = 105;
					}
					maze[pos_x][pos_y]=1;
					maze[pos_x+1][pos_y]=2;
					pos_x +=1;
					break;
				}
				else
				{
					x++;
				}
			case 3:
				if(maze[pos_x-1][pos_y]==1)
				{
					if(maze[pos_x-1][pos_y]==3)
					{
						counter = 105;
					}
					maze[pos_x][pos_y]=1;
					maze[pos_x-1][pos_y]=2;
					pos_x -=1;
					break;
				}
		}
		printf("\n");
		show_maze02(maze);
		counter++;
	}
	if(counter == 106)
	{
		printf("\nOh, trap!");
	}
	else
	{
		printf("\nNothing like freedom!");
	}

}

int main()
{
	def maze01[8][8];
	def maze02[10][10];
	int i,j;
	for(i=0; i<8 ; i++)
	{
		for(j=0; j<8 ; j++)
		{
			maze01[i][j]=1,1;
		}
	}
	for(i=0; i<10 ; i++)
	{
		for(j=0; j<10 ; j++)
		{
			maze02[i][j]=1,1;
		}
	}
	init_maze01(maze01);
	show_maze01(maze01);
	move01(maze01,3,3);
	init_maze02(maze02);
	show_maze02(maze02);
	move02(maze02,1,1);

	return 0;

}