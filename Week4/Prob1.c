//모든케이스 통과입니다.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int cnt = 0;
    int first = arr[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (first > arr[j])
            {
                cnt++;
            }
        }
        first = arr[i];
    }
    
    printf("%d",cnt);
    return 0;
}