//
//  main.c
//  Prob7
//
//  Created by 채정훈 on 9/5/22.
//
//모든 테스트 케이스 통과했습니다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char string[51];
    int length;
} str;

void merge(str* arr, int first, int mid, int last);
void mergeSort(str* arr, int first, int last);
str sort[20001];

void merge(str* arr, int first, int mid, int last) {
    int i = first;
    int j = mid + 1;
    int k = first;

    while(i <= mid && j <= last) {
        if (arr[i].length < arr[j].length) {
            sort[k++] = arr[i++];
        } else if (arr[i].length > arr[j].length) {
            sort[k++] = arr[j++];
        } else {
            if (strcmp(arr[i].string, arr[j].string) < 0) {
                sort[k++] = arr[i++];
            }
            else {
                sort[k++] = arr[j++];
            }
        }
    }
    if (i > mid) {
        while (j <= last)
            sort[k++] = arr[j++];
    }
    else {
        while (i <= mid)
            sort[k++] = arr[i++];
    }
    for (k = first; k <= last; k++) 
        arr[k] = sort[k];
}

void mergeSort(str* arr, int first, int last) {
    int mid;
    if (first < last) {
        mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}
int main(void)
{
    int N;
    scanf("%d", &N);
    str arr[N];

    for(int i = 0; i < N; i++) {
        scanf("%s", arr[i].string);
        arr[i].length = strlen(arr[i].string);
    }

    mergeSort(arr, 0, N - 1);
    printf("\n");
    printf("%s\n", arr[0].string);
    for (int i = 1; i < N; i++) {
        if (strcmp(arr[i-1].string, arr[i].string) != 0)
            printf("%s\n", arr[i].string);
    }
    return 0;
}