//
//  main.c
//  Prob5
//
//  Created by 채정훈 on 9/5/22.
//
//모든 테스트 케이스 통과했습니다.

#include <stdio.h>

int main(void)
{
    int arr[100];
    int arrSize;
    scanf("%d",&arrSize);
    
    for (int i=0; i<arrSize; i++) {
        scanf("%d",&arr[i]);
    }
    
    int temp;
    
    for (int i=0; i<arrSize-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<arrSize; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    int b[100];
    int n=1;
    int cnt=1;
    b[0] = arr[0];
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] != b[n - 1])
        {
            b[n++] = arr[i];
            cnt++;
        }
    }
    
    printf("%d: ",cnt);
    for (int i = 0; i < n; i++)
            printf("%d ", b[i]);
    
    return 0;
}
