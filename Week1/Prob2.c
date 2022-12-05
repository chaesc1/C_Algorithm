//
//  main.c
//  prob2
//
//  Created by 채정훈 on 9/1/22.
//
//모든 테스트 케이스 통과했습니다.

#include <stdio.h>

int main(void)
{
    int input;
    
    scanf("%d",&input);
    int arr[input];
    
    for (int i=0; i<input; i++) {
        scanf("%d",&arr[i]);
    }
    
    int temp;
    
    for (int i=0; i<input-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<input; j++) {
            if (arr[j] <= arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    
    for (int i=0; i<input; i++) {
        printf("%d ",arr[i]);
    }
    
    return 0;
}
