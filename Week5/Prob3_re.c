#include <stdio.h>
#include <stdlib.h>

#define black 1
#define white 2
#define empty 0

int arr[19][19];

int RightUp(int x,int y,int Color)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        int yy = y - i;
        int xx = x + i;
        if (arr[yy][xx] == Color)
        {
            count++;
        }
        
    }
    if (count!=5)
    {
        return 0;
    }
    if (arr[y+1][x-1]==Color)   
    {
        return 0;
    }
    if (arr[y-5][x+5] == Color)
    {
        return 0;
    }
    
    return 1;
}

int Right(int x,int y,int Color)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        int xx = x + i;
        if (arr[y][xx] == Color)
        {
            count++;
        }
        
    }
    if (count!=5)
    {
        return 0;
    }
    if (arr[y+1][x-1]==Color)   
    {
        return 0;
    }
    if (arr[y][x+5] == Color)
    {
        return 0;
    }
    return 1;
}

int RightDown(int x,int y,int Color)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        int xx = x + i;
        int yy = y + i;
        if (arr[yy][xx] == Color)
        {
            count++;
        }
        
    }
    if (count!=5)
    {
        return 0;
    }
    if (arr[y-1][x-1]==Color)   
    {
        return 0;
    }
    if (arr[y+5][x+5] == Color)
    {
        return 0;
    }
    return 1;
}

int DOWN(int x,int y,int Color)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        int yy = y + i;
        if (arr[yy][x] == Color)
        {
            count++;
        }
        
    }
    if (count!=5)
    {
        return 0;
    }
    if (arr[y-1][x]==Color)   
    {
        return 0;
    }
    if (arr[y+5][x] == Color)
    {
        return 0;
    }
    return 1;
}
int main(void)
{
    FILE * file= fopen("./board.txt","r");
    int arrnum = 0;
    
    fscanf(file,"%d",&arrnum);
    int arr[arrnum][arrnum];

    for (int i = 0; i < arrnum; i++)
    {
        for (int j = 0; j < arrnum; j++)
        {
            fscanf(file,"%d",&arr[i][j]);
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}