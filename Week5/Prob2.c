//모든케이스 통과하였습니다.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE * file= fopen("./data.txt","r");
    int arrnum = 0;
    int x,p,y,q;
    char command[100];

    fscanf(file,"%d",&arrnum);
    int arr[arrnum][arrnum];

    for (int i = 0; i < arrnum; i++)
    {
        for (int j = 0; j < arrnum; j++)
        {
            fscanf(file,"%d",&arr[i][j]);
            
        }
        //printf("\n");
    }

    while (1)
    {
        printf("$");
        scanf("%s",command);

        if (strcmp(command,"show")==0)
        {
            for (int i = 0; i < arrnum; i++)
            {
                for (int j = 0; j < arrnum; j++)
                {
                    printf("%d ",arr[i][j]);
                }
                printf("\n");
            }
        }
        else if(strcmp(command,"colmax")==0)
        {   
            for (int i = 0; i < arrnum; i++)
            {
                int max = arr[0][i];
                for (int j = 0; j < arrnum; j++)
                {
                    if(arr[j][i] >= max)
                    {
                        max = arr[j][i];
                    }
                }
                printf("%d ",max);
            }
            printf("\n");
        }
        else if(strcmp(command,"colmin")==0)
        {
            for (int i = 0; i < arrnum; i++)
            {
                int min = arr[0][i];
                for (int j = 0; j < arrnum; j++)
                {
                    if(arr[j][i] <= min)
                    {
                        min = arr[j][i];
                    }
                }
                printf("%d ",min);
            }
            printf("\n");
        }
        else if(strcmp(command,"rowmax")==0)
        {
            for (int i = 0; i < arrnum; i++)
            {
                int max = arr[i][0];
                for (int j = 0; j < arrnum; j++)
                {
                    if(arr[i][j] >= max)
                    {
                        max = arr[i][j];
                    }
                }
                printf("%d ",max);
            }
            printf("\n");
        }
        else if(strcmp(command,"rowmin")==0)
        {
            for (int i = 0; i < arrnum; i++)
            {
                int min = arr[i][0];
                for (int j = 0; j < arrnum; j++)
                {
                    if(arr[i][j] <= min)
                    {
                        min = arr[i][j];
                    }
                }
                printf("%d ",min);
            }
            printf("\n");
        }
        else if(strcmp(command,"slice")==0)
        {
            scanf("%d %d %d %d",&x,&p,&y,&q);
            for (int i = x; i < arrnum; i+=p)
            {
                for (int j = y; j < arrnum; j+=q)
                {
                    printf("%d ",arr[i][j]);
                }
                printf("\n");
            }
            
        }
        else if(strcmp(command,"exit")==0)
        {
            break;
        }
        else
        {
            break;
        }
    }

     fclose(file);
    return 0;
}