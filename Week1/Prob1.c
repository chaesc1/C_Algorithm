//
//  main.c
//  prob1.c
//
//  Created by 채정훈 on 9/1/22.
//
//모든 테스트 케이스 통과했습니다.
#include <stdio.h>

void func(int num)
{
    int res;
    res = num/2;
    
    if(num/2 == 0){
        printf("%3d\n",res);
    }
    else{
        printf("%3d",res);
        func(res);
    }
}

int main(void)
{
    int num;
    
    scanf("%d",&num);
    func(num);
    
    return 0;
}
