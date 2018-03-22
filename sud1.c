#include<stdio.h>
int puzz[9][9];

int rows(int n,int row)
{	int i;
	for (i=0;i<9;i++)
		if(puzz[row][i]==n) 	//check all columns of the row (1 if poss)
			return 0;
	return 1;
}
int columns(int n,int col)
{	int i;
	for (i=0;i<9;i++)
	if(puzz[i][col]==n) 	// check all rows in that column (1 if poss)
			return 0;
	return 1;
}
int block(int n,int row, int col)
{	int r,c,i,j;
	r=(row/3)*3;
	c=(col/3)*3;
	for(i=r;i<r+3;i++)
		for(j=c;j<c+3;j++)
			if(puzz[i][j]==n)		//check block
				return 0;
	return 1;
}
void print()			//print
{   int i,j;
    printf("The Solved Sudoku is \n");
	for(i=0;i<9;i++){
		for (j=0;j<9;j++)
		printf("  %d",puzz[i][j]);
		printf("\n");
}
getch();
}
void solve(int row,int col)
{
    if(row>8)
		print();
	if(puzz[row][col]!=0)
	{	if(col<8)
			solve(row,col+1);
		else
			solve(row+1,0);
	}
	else
	{ int i;
		for (i=1;i<9;i++)
		{	if((rows(i,row)&&columns(i,col)&&block(i,row,col))==1){
			puzz[row][col]=i;					// assign n=x
			if(col<8)
				solve(row,col+1);
			else
				solve(row+1,0);
		}
		 }
		puzz[row][col]=0;
	}			
}

int main() 
{ int row,column;
 printf("Enter the sudoku to be solved and enter 0 for unknown entries\n"); 
 for(row=0;row<9;row++) 
	 for(column=0;column<9;column++) 
		 scanf("%d",&puzz[row][column]); 
 solve(0,0);
}
