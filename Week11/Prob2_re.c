#include <stdio.h>
#include <stdlib.h>

#define MAX 19
#define ROUTE 0
#define WALL 1
#define BACKTRACK 2

int map[MAX][MAX];
int cnt = 0;

void DFS(int x,int y,int N)
{
    if (map[x][y] == WALL || map[x][y] == BACKTRACK) //벽이거나 다녀온길이면 return
    {
        return;
    }
    if(x > N || y > N || x < 1 || y < 1)
    {//map에서 벗어날경우
        return;
    }
    else if(x == N && y == N)
    {//도착지면
        cnt++;
    }
    else
    {
        map[x][y] = BACKTRACK; //지나온길을 2로 바꿔

        DFS(x,y-1,N);
        DFS(x,y+1,N);
        DFS(x-1,y,N);
        DFS(x+1,y,N);
        //상하좌우 재귀 함수로 호출
        map[x][y] = ROUTE;// 앞길 모두 탐색했으면 다시 길로 바꿔줘 
        //왜냐 goal로 향한 모든 경우의 수를 count 하기 위해.
    }
}
int main(void)
{
    FILE *file = fopen("./Maze.txt","r");

    int num = 0;
    int arrnum = 0;
    fscanf(file,"%d",&num);//case수 카운트
    for (int  i = 1; i <= num; i++)
    {
        cnt=0;
        fscanf(file,"%d",&arrnum);
        for (int j = 1; j <= arrnum; j++)
        {
            for (int k = 1; k <= arrnum; k++)
            {
                fscanf(file,"%d",&map[j][k]);
                //printf("%3d",map[j][k]);
            }
            //printf("\n");
        }
        DFS(1,1,arrnum);
        printf("%d\n",cnt);
    }
    return 0;
}