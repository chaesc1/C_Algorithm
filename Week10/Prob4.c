//
//  main.c
//  Week10_prob4
//
//  Created by 채정훈 on 11/22/22.
//

#include <stdio.h>

int flooring(int data[],int start,int end,int target)
{
    if (end < 0) {
        return -1;
    }
    else if(data[end] > target){ //data가 target보다 크면 end하나 줄여
        end--;
        return flooring(data, start, end, target);
    }
    else if(data[end] < target){
        return data[end];
    }
    else
    {
        return -1;
    }
}

int ceiling(int data[],int start,int end,int target)
{
    if (start > end) {
        return -1;
    }
    else if(data[start] < target){ //data가 target보다 작으면 start늘려줘
        start++;
        return ceiling(data, start, end, target);
    }
    else if(data[start] > target){
        return data[start];
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int N = 0;
    int K = 0;
    scanf("%d",&N);
    
    int data[100];
    
    for (int i=0; i < N; i++) {
        scanf("%d",&data[i]);
    }
    scanf("%d",&K);
    
    printf("%d\n",flooring(data,0,N-1,K));
    printf("%d\n",ceiling(data,0,N-1,K));
    return 0;
}
