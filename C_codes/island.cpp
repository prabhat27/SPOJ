#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
#define ROW 5
#define COL 5
bool bound(int row, int col,int M[][COL],bool visited[][COL])
{
    return (row >= 0) && (row < ROW) &&     // row number is in range
           (col >= 0) && (col < COL) &&     // column number is in range
           (M[row][col] && !visited[row][col]); // value is 1 and not yet visited
}
void DFS(int i,int j,int M[][COL],bool visited[][COL])
{
	static int row[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int col[] = {-1,  0,  1, -1, 1, -1, 0, 1};
	visited[i][j]=true;
    for (int k = 0; k < 8; ++k)
    if (bound(i+row[k],j+ col[k],M,visited) )
         DFS(i+row[k],j+ col[k],M, visited);
}
int countIslands(int M[][COL])
{
	bool visited[ROW][COL];
	memset(visited,false, sizeof(visited));

	int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            if (M[i][j] && !visited[i][j]) // If a cell with value 1 is not
            {                              // visited yet, then new island found
                DFS(i, j,M, visited);     // Visit all cells in this island.
                ++count;                   // and increment island count
            }
 
    return count;
}
int main()
{
    int M[][COL]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 
    printf("Number of islands is: %d\n", countIslands(M));
 
    return 0;
}
