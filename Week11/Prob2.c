#include <stdio.h>
#include <stdlib.h>

#define MAX 19
int map[MAX][MAX];
int cnt = 0;

void DFS(int x,int y,int N)
{
    if (map[x][y] == 1)
        return;

    if (x > N || y > N || x < 1 || y < 1)
        return;
    else if (x == N && y == N)
        cnt++;
    else 
    {
        map[x][y] = 1;
        //지나온 길 1로 바꿔
        DFS(x, y - 1,N); 
        DFS(x, y + 1,N);
        DFS(x - 1, y,N);
        DFS(x + 1, y,N);
        //상하좌우 이동하는 재귀함수 호출
        map[x][y] = 0;//앞길 모두 탐색 -> 0으로 치환하여 다른 경우의수 카운트할때 반영x
    }  
}

int main(void)
{
    int N = 0;
    scanf("%d",&N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }

    DFS(1,1,N);

    printf("%d\n",cnt);
    
    return 0;
}