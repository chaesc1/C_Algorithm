//
//  main.c
//  prob3
//
//  Created by 채정훈 on 9/1/22.
//
//모든 테스트 케이스 통과했습니다.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

int is_include(int *arr, int arr_size, int value) { // 배열이 값을 포함하고 있는지 확인

    for(int i = 0; i < arr_size; i++) {
        if(arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int input;
    int arr[100];
    int cnt = 0;
    
    while (1) {
        scanf("%d",&input);
        
        if(input == -1)
        {
            break;
        }
        
        arr[cnt] = input;
        cnt++;
        int temp;
        for (int i=0; i<cnt; i++) {
            int minIndex = i;
            for (int j=i+1; j<cnt; j++) {
                if (arr[j] == arr[minIndex]) {
                    cnt--;
                    printf("duplicated");
                }
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
        
        for (int i=0; i<cnt; i++) {
            printf("%3d",arr[i]);
        }
        printf("\n");
    }
    
    
    return 0;
}
