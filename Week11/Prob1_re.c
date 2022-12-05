#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool check(int *graph,int row)
{
    for (int i = row-1; i >= 0; i--)
    {
        if (graph[i] == graph[row])
        {
            return false;
        }
        if (abs(graph[row]-graph[i]) == abs(row - i))
        {
            return false;
        }
    }
    return true;
}

int answer = 0;
void backTracking(int *graph,int row,int n)
{
    if (row == n)
    {
        answer++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        graph[row] = col; //각 행마다 퀸을 놓아본다
        if (check(graph,row))
        {
            backTracking(graph,row+1,n); //되면 다음행 안되면 다음열
        }
        graph[row] = 0;
    }
}
int main(void)
{
    int *graph;

    for (int i = 1; i <= 15; i++)
    {
        graph = (int *)malloc(sizeof(int) * i);
        graph[i] = 0;
        answer = 0;
        backTracking(graph,0,i);
        printf("%d : %d\n",i,answer);
    }
    
    return 0;
}