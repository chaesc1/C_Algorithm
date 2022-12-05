#include <stdio.h>

void bubblesort(int n,int num[]);

int main(void)
{
    int n;
    int num[100];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }

    bubblesort(n,num);

    // 1 2 3 3 3 4 4 5 5 7 8 9 9
    int j = 0;//살아남은 마지막 인덱스.
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || num[i] > num[i-1]) // survive
        {
            num[j++] = num[i];
        }
    }
    printf("%d: ",j);
    for (int i = 0; i < j; i++)
    {
        printf("%d ",num[i]);
    }
    

    return 0;
}

void bubblesort(int n,int num[])
{
    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(num[j]>num[j+1])
            {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }
        
    }
    
}