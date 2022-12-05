//모든케이스 통과입니다.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <math.h>

int main(void)
{
    //분산 -> 평균 구하고 
    //각 항목의 값을 평균으로 빼고 제곱하여 합산
    //표준편차 -> 분산을 항목수로 나눈다.

    int num;
    int arrnum;
    FILE * file= fopen("./input.txt","r");
    int arr[10][10];

    fscanf(file,"%d",&arrnum);

    printf("%d\n",arrnum);
    for (int i = 0; i < arrnum; i++)
    {
        for (int j = 0; j < arrnum; j++)
        {
            fscanf(file,"%d",&arr[i][j]);
        }
    }
    //scanf("%d",&num);
    int sum_ROWS;//가로 합
    int sum_COLS;//세로 합
    double avg_ROWS[arrnum];
    double avg_COLS[arrnum];
    double variance;
    double variance_ROWS[arrnum];
    double variance_COLS[arrnum];
    
    double deviation_ROWS[arrnum];
    double deviation_COLS[arrnum];
    
    int cnt = 0;

    /*for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%d",&arr[i][j]);//배열에 저장.
        }
    }*/
    
    int row = 0;
    for (int i = 0; i < arrnum; i++)
    {
        sum_ROWS = 0;
        sum_COLS = 0;
        variance = 0;
        for (int j = 0; j < arrnum; j++)
        {
            sum_ROWS += arr[i][j];
            sum_COLS += arr[j][i];
            avg_ROWS[i] = (double)sum_ROWS/arrnum;
            avg_COLS[i] = (double)sum_COLS/arrnum;
        }
    }
    //분산과정

    for (int i = 0; i < arrnum; i++)
    {
        
        for (int j = 0; j < arrnum; j++)
        {
            variance_ROWS[i] += pow(arr[i][j]-avg_ROWS[i],2);
            variance_COLS[i] += pow(arr[j][i]-avg_COLS[i],2);
        } 
        variance_ROWS[i] = variance_ROWS[i] / arrnum;
        variance_COLS[i] = variance_COLS[i] /arrnum;
    }
    
    for (int i = 0; i < arrnum; i++)
    {
        deviation_ROWS[i] = sqrt(variance_ROWS[i]);
        deviation_COLS[i] = sqrt(variance_COLS[i]);
    }
    //출력과정
    for (int i = 0; i < arrnum; i++)
    {
        for (int j = 0; j < arrnum; j++)
        {
            printf(" %d",arr[i][j]);
        }
        printf(" %.2f",avg_ROWS[i]);
        printf(" %.2f",deviation_ROWS[i]);
        printf("\n");
    }
    for (int i = 0; i < arrnum; i++)
    {
        printf(" %.2f",avg_COLS[i]);
    }
    printf("\n");
    for (int i = 0; i < arrnum; i++)
    {
        printf(" %.2f",deviation_COLS[i]);
    }
    
    fclose(file);
    return 0;
}