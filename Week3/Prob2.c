#include <stdio.h>

typedef struct dic
{
    int key;
    int value;
}dic;

int main(void)
{
    int interval;//구간의 개수
    int firstnum[100];
    int secondnum[100];

    scanf("%d",&interval);

    for (int i = 0; i < interval; i++)
    {
        scanf("%d %d",&firstnum[i],&secondnum[i]);
    }
    printf("\n");
    
    int tmp;
    int tmp2;

    for (int i = 0; i < interval-1; i++)
    {
        int min = i;
        int min2 = i;
        for (int j = i+1; j < interval; j++)
        {
            if (firstnum[j] <firstnum[min])
            {
                min = j; 
                
                tmp2 = secondnum[min];
                secondnum[min] = secondnum[i];
                secondnum[i] = tmp2;//firstnum의 위치를 secondnum이 따라가게 만든다.
                //printf("i = %d, j = %d, min = %d\n",i,j,min);
            }
        }   
        tmp = firstnum[min];
        firstnum[min] = firstnum[i];
        firstnum[i] = tmp;
    }
    for (int i = 0; i < interval-1; i++)
    {
        int min2 = i;
        for (int j = i+1; j < interval; j++)
        {
            if (firstnum[j] == firstnum[min2])
            {
                if (secondnum[j] < secondnum[min2])
                {
                    min2 = j;
                } 
            }
        }   
        tmp2 = secondnum[min2];
        secondnum[min2] = secondnum[i];
        secondnum[i] = tmp2;
    }
    for (int i = 0; i < interval; i++)
    {
        printf("%d %d\n",firstnum[i],secondnum[i]);
    }
    
    
    return 0;
}