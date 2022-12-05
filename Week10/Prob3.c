//
//  main.c
//  Week10_prob3
//
//  Created by 채정훈 on 11/21/22.
//

#include <stdio.h>

int count_cell(int data[],int start,int end,int target)
{
    int count=0;
    int sum = 0;
    sum = data[start] + data[end];
    
    if (start >= end) {
        return 0;
    }
    else if (sum > target) {
        end--;
        count_cell(data,start,end,target);
    }
    else if(sum<target)
    {
        start++;
        count_cell(data,start,end,target);
    }
    else
    {
        count++;
        start++;
        end--;
        
        count_cell(data,start,end,target);
    }
    //printf("%d\n",count);
    return count;
}
int main() {
    int N = 0;
    int K = 0;
    scanf("%d",&N);
    
    int data[100];
    
    for (int i=0; i < N; i++) {
        scanf("%d",&data[i]);
    }
    scanf("%d",&K);
    
    printf("%d",count_cell(data,0,N-1,K));
    return 0;
}
