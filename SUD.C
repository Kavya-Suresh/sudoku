#include<stdio.h>

int rows(int n,int puzz[9][9],int row)
{	int i;
	for (i=0;i<9;i++)
	{	if(puzz[row][i]==n) 	//check all columns of the row (1 if poss)
			return 0;
	}
	return 1;
}
int columns(int n,int puzz[9][9],int col)
{	int i;
	for (i=0;i<9;i++)
	{	if(puzz[i][col]==n) 	// check all rows in that column (1 if poss)
			return 0;
	}
	return 1;
}
int block(int n, int puzz[9][9],int row, int col)
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
void print(int puzz[9][9])			//print
{   int i,j;
	for(i=0;i<9;i++)
	{	for (j=0;j<9;j++)
			printf("  %d",puzz[i][j]);
		printf("\n");
	}
}

int valid(int n,int puzz[9][9],int row,int col)
{	int r=0,c=0,b=0;
	r=rows(n,puzz,col);				// 1 if possible
	c=columns(n,puzz,row);			// 1 if possible
	b=block(n,puzz,row,col);		// 1 if possible
	return (r&&c&&b) ;
}

int blank(int puzz[9][9],int row,int col)
{	if(puzz[row][col]==0);
	{	return 1;  }
							//if blank returns 1

}

void solve(int puzz[][9])
{	int n,i,j;
	for(i=0;i<9;i++)
	{	for(j=0;j<9;j++)
		{	if(blank(puzz,i,j))			//if blank:
			{	for(n=1;n<10;n++)
				{	if(valid(n,puzz,i,j))		//if n is possible
					{	puzz[i][j]=n;			// assign n
						print(puzz);			//print after each assignment
					}
				}

			}
		}
	}
}

void main()
{	int Sudoku[9][9]={{0,3,7, 0,5,2, 0,1,0},
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
	solve(Sudoku[9][9]);
}