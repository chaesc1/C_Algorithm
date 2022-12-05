#include <stdio.h>

int main(void)
{
    int data[100];
    int n;

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&data[i]);
    }
    
    for (int i = n-1; i > 0; i--)
    {
        int max_index= 0;
        for (int j = 0; j <= i; j++)
        {
            if (data[j] > data[max_index])
            {
                max_index = j;
            }
        }
        int tmp = data[i];
        data[i] = data[max_index];
        data[max_index] = tmp;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",data[i]);
    }
    return 0;
}