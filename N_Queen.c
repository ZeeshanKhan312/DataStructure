//N Queen's Problem
// NO Queen's to be in same row or column and nor in the same diagonal

#include <stdio.h>
#include <stdbool.h>
#define N 5 // No of Queens 
int board[N][N];

bool safe(int x,int y)
{
	int row,col;
	for(row=0,col=y;row<x;row++)//to check in same coulmn above
	if(board[row][col])
	return false;
	for(row=x,col=y;col>=0 && row>=0 ;row--,col--)//to check the diagonal on the upper left
	if(board[row][col])
	return false;
	for(row=x,col=y; row>=0 && col<N;row--,col++)// to check the diagonal on the upper right
	if(board[row][col])
	return false;

	return true;// if none of the above condition becomes true it means this position is safe to place the Queen
}
bool NQueens(int x)
{
	if(x>=N)//if all the rows are filled which means all possible queens are placed
	return true;
	for(int col=0;col<N;col++)//checking for each column using loop
	{
		if(safe(x,col))
		{
		board[x][col]=1;
		if(NQueens(x+1))//checking for next row after placing the Queen in current law
		return true;
		board[x][col]=0;//if the next row has no safe position remove the place from this position and continue the loop
		}
	}
	return false;
}
void main()
{
	if(NQueens(0))//Searching for the Queens position
	{
		for (int i = 0; i < N; i++) {//printing the final answer with safe position of Queens
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
      }
	}
	else//if the Queens cann't be placed without being in Danger
	printf("Solution doesn't exist!!");
}