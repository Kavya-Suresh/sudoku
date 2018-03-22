#include<stdio.h>
int puzz[9][9];

int rows(int n,int row)
{	int i;
	for (i=0;i<9;i++)
	{	if(puzz[row][i]==n) 	//check all columns of the row (1 if poss)
			return 0;
	}
	return 1;
}
int columns(int n,int col)
{	int i;
	for (i=0;i<9;i++)
	{	if(puzz[i][col]==n) 	// check all rows in that column (1 if poss)
			return 0;
	}
	return 1;
}
int block(int n,int row, int col)
{	int r,c,i,j;
	r=(row/3)*3;
	c=(col/3)*3;
	for(i=r;i<r+3;i++)
	{	for(j=c;j<c+3;j++)
		{	if(puzz[i][j]==n)		//check block
				return 0;
		}
	}
	return 1;
}
void print()			//print
{   int i,j;
	for(i=0;i<9;i++)
	{	for (j=0;j<9;j++)
			printf("  %d",puzz[i][j]);
		printf("\n");
	}
}
void solve(int row,int col)
{	int count=0,i;
    if(row>8)
		print();
	if(puzz[row][col]!=0)
	{	if(col<8)
			solve(row,col+1);
		else
			solve(row+1,0);
	}
	else
	{	count=0;
		for (i=0;i<9;i++)
		{	if((rows(i,row)&&columns(i,col)&&block(i,row,col))==1)
			{	count=count+1;
				printf("[%d][%d]:%d*%d,",row,col,i,count);
			}
		}
		if(count==1)
		{	puzz[row][col]=i;					// assign n=x
			if(col<8)
				solve(row,col+1);
			else
				solve(row+1,0);
		}
		puzz[row][col]=0;
	}			
}

void main()
{	int puzz[9][9] = {{0,3,7, 0,5,2, 0,1,0},
				  {9,0,1, 7,0,0, 0,8,6},
				  {2,0,0, 1,0,9, 7,0,3},

				  {0,0,9, 2,8,0, 5,3,0},
				  {8,0,6, 3,0,0, 0,9,4},
				  {5,7,0, 9,0,1, 0,6,0},

				  {0,6,0, 0,2,7, 9,0,0},
				  {7,1,0, 0,9,3, 6,0,8},
				  {0,9,2, 0,1,0, 3,0,5}};
	/*
	for(i=0;i<9;i++)
		for (j=0;j<9;j++)
		{	printf("%d%d: "i,j);
			scanf("%d",&Sudoku[i][j]);
	*/
	solve(0,0);
}
