//
//  main.c
//  prob4
//
//  Created by 채정훈 on 9/5/22.
//
//모든 테스트 케이스 통과했습니다.
#include <stdio.h>

int main(void)
{
    int arrSize;
    int num,k;
    int res[100];
    
    scanf("%d",&arrSize);
    int arr[arrSize];
    
    for (int i=0; i<arrSize; i++) {
        scanf("%d",&num);
        arr[i] = num;
    }
    
    scanf("%d",&k);
    
    int minIndex = 0;
    
    for (int i=0; i<arrSize; i++) {
        res[i] = arr[i] - k;
        if(res[i]<0)
        {
            res[i] = -res[i];//차이를 배열에 저장하고 그 인덱스의 arr를 뽑아내야해.
        }
    }
    int min = res[0];
    
    for (int i = 0; i < arrSize; i++) {
            if (res[i] < min)
            {
                min = res[i];
                minIndex = i;
            }
        }
    
    printf("%d",arr[minIndex]);
    return 0;
}
