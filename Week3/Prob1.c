#include <stdio.h>

int main(void)
{
    int input;
    int num[100];

    scanf("%d",&input);

    for (int i = 0; i < input; i++) 
    {
        scanf("%d",&num[i]);
    }//input만큼 입력값을 받아

    int temp;

    for (int i = 0; i < input-1; i++)
    {
        int min = i;
        for (int j = i+1; j < input; j++)
        {
            if(num[j]<=num[min])
            {
                min = j;
            }
        }
        temp = num[min];
        num[min] = num[i];
        num[i] = temp;
    }
    
    for (int i = 0; i < input; i++)
    {
        printf("%d ",num[i]);
    }
    
    return 0;
}