#include<stdio.h>
int rows_begin = 0, columns_begin = 0;
int check = 10;
void printgrid(int *g, int rows, int columns){
	for (int i = rows_begin; i <10; i++){
		for (int j = columns_begin; j < 10; j++)
		{
			printf("%d  ", g[i*10+j]);
		}
		printf("\n");
	}
}
void removeElements(int *g, int row, int col_start, int col_end, int rows, int cols){
	int i = 0, j = 0;
	for (i = row; i > rows_begin; i--)
	{
		for (j = col_start; j <= col_end; j++){
			g[i*rows + j] = g[(i - 1)*rows + j];
		}
	}
	i = rows_begin;
	for (j = col_start; j <= col_end; j++)
	{
		g[i*rows +j] = 1;
	}

}
void checkShrink(int *g, int rows, int columns){
	int row_count = 0,col_count=0;
	for (int i = rows; i < 10; i++){
		row_count += g[i * 10];
	}
	if (row_count == check){
		for (int i = rows; i < 10; i++){
			col_count += g[rows * 10 + i];
		}
		if (col_count == check)
		{
			rows_begin = rows_begin + 1;
			columns_begin = columns_begin + 1;
			check = check - 1;
		}
	}
}
int main()
{
	int grid[10][10],count=0;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++)
		{
			count++;
			if (count % 3 == 0 || count % 4 == 0)
			{
				grid[i][j] = 1;

			}
			else{
				grid[i][j] = 0;
				}
		}
	}
	while (rows_begin != 10)
	{
		printgrid(grid, rows_begin, columns_begin);
		int row = -1, col_end = -1, col_start = -1;
		printf("enter the row and col start and end to clear\n");
		scanf_s("%d%d%d", &row, &col_start, &col_end);
		if (row>9 || (col_end - col_start) < 1 || col_start > 9 || col_start < 0 || col_end < 0 || row < 0)
		{
			printf("wrong entry!\n");
			
		}
		else{
			removeElements(grid, row, col_start, col_end, 10, 10);
			checkShrink(grid, rows_begin, columns_begin);
		}
	}
	
}