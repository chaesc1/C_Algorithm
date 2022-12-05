//모든케이스 통과하였습니다.
#include <stdio.h>
#include <stdlib.h>

#define black 1
#define white 2
#define empty 0

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
            //printf("%d ",arr[i][j]);
        }
       //printf("\n");
    }
    int blackcnt = 0;
    int whitecnt = 0;
    int win = 0;
    //가로줄 체크 흑돌
    for (int i = 0; i < arrnum; i++)//i는 세로 j는 가로
    {
        blackcnt = 0;
        whitecnt = 0;
        for (int j = 0; j < arrnum; j++)
        {
            if(arr[i][j] == 1)//검은돌이면
            {
                blackcnt++;
            }
            else
            {
                blackcnt = 0;
               
            }

            if(arr[i][j] == 2)//백돌이면
            {
                whitecnt++;
            }
            else
            {
                whitecnt = 0;
               
            } 
            if (blackcnt ==  5)
            {
                printf("BLACK\n");
                win = 1;
            }
            if (whitecnt == 5)
            {
                printf("WHITE\n");
                win = 1;
            }
        }
    }
    for (int j = 0; j < arrnum; j++)
    {
        blackcnt = 0;
        whitecnt = 0;
        for (int i = 0; i < arrnum; i++)
        {
            if(arr[i][j] == 1)//검은돌이면
            {
                blackcnt++;
            }
            else
            {
                blackcnt = 0;
               
            }

            if(arr[i][j] == 2)//백돌이면
            {
                whitecnt++;
            }
            else
            {
                whitecnt = 0;
               
            } 
            if (blackcnt ==  5)
            {
                printf("BLACK\n");
                win = 1;
            }
            if (whitecnt == 5)
            {
                printf("WHITE\n");
                win = 1;
            }
            
        }
    }
    //대각선 체크 제일 까다로워
    //오른쪽 대각선 위
    for (int i = 0; i < arrnum-4; i++)//i세로 j가로
    {
        blackcnt = 0;
        whitecnt = 0;
        for (int j = 4; j < arrnum; j++)
        {
            int temp1 = i;
            int temp2 = j;
            for (int k = 0; k < 6; k++)
            {
                //printf("%d",whitecnt);

                if (arr[temp1++][temp2--] == 2)//백돌
                    whitecnt++;
                else
                    whitecnt = 0;
            }
            for (int k = 0; k < 6; k++)
            {
                if (arr[temp1++][temp2--] == 1)//흑돌
                    blackcnt++;
                else
                    blackcnt = 0;
            }
            
            if (blackcnt ==  5)
            {
                printf("BLACK\n");
                win = 1;
            }
            if (whitecnt == 5)
            {
                printf("WHITE\n");
                win = 1;
            }
            
        }
        
    }
    
    for (int i = 0; i < arrnum-4; i++)//i세로 j가로
    {
        blackcnt = 0;
        whitecnt = 0;
        for (int j = 0; j < arrnum-4; j++)
        {
            int temp1 = i;
            int temp2 = j;
            
            for (int k = 0; k < 6; k++)
            {
                if (arr[temp1++][temp2++] == 1)//흑돌
                    blackcnt++;
                else
                    blackcnt = 0;
            }
            if (blackcnt ==  5)
            {
                printf("BLACK\n");
                win = 1;
            }

            for (int k = 0; k < 6; k++)
            {
                if (arr[temp1++][temp2++] == 2)//백돌
                    whitecnt++;
                else
                    whitecnt = 0;
            }
            
            if (whitecnt == 5)
            {
                printf("WHITE\n");
                win = 1;
            }
            
        }
    }
     for (int i = 0; i < arrnum-4; i++)//i세로 j가로
    {
        blackcnt = 0;
        whitecnt = 0;
        for (int j = 0; j < arrnum-4; j++)
        {
            int temp1 = i;
            int temp2 = j;

            for (int k = 0; k < 6; k++)
            {
                if (arr[temp1++][temp2++] == 2)//백돌
                    whitecnt++;
                else
                    whitecnt = 0;
            }
            
            if (whitecnt == 5)
            {
                printf("WHITE\n");
                win = 1;
            }
            
        }
    }
    if (win == 0)
    {
        printf("NOT FINISHED\n");
    }
    
    return 0;
}