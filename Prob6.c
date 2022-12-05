//
//  main.c
//  Prob6
//
//  Created by 채정훈 on 9/5/22.
//모든 테스트 케이스 통과했습니다.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double power(double num1,int num2)//제곱함수
{
    if(num2 <= 0)
    {
        return 1;
    }
    else
    {
        return (num1 * power(num1,num2-1));
    }
}
double combination(int n,int r)//조합함수
{
    if (n==r||r==0)
    {
        return 1;
    }

    return combination(n-1,r-1) + combination(n-1,r);
    
}
double prob(int n,int k)
{
    int dice = 6;
    int r;
    int cnt = 0;
    double rate1;//1이 나올 확률
    double rate2;
    double res;
    
    for (int i=0; i<1000000; i++) {
        r = (rand() % dice)+1;//1-6랜덤생성.
        //printf("%d",r);
        if(r == k)
        {
            cnt++;
        }
    }//백만번 던졌을때 1이 나올 횟수
    
    rate1 = cnt/1000000.0;//1이 나오는 확률
    rate2 = 1.0-rate1;//1이 안나올 확률
    
    res = 1;
    while (k>0)
    {
        res -= combination(n,k-1)*power(rate1,(k-1))*power(rate2,(n+1-k));
        k--;
    }
    return res;
}

int main(void)
{
    srand((unsigned int) time(NULL));
    
   // printf("%lf\n",prob(12, 2));
    double res1,res2;

    res1 = prob(6,1);
    res2 = prob(12,2);

    printf("%.6lf\n",res1);
    printf("%.6lf",res2);
    return 0;
}


