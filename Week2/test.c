//
//  main.c
//  Week2_prob2
//
//  Created by 채정훈 on 9/14/22.
//

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void sort2(char **arr,int size){
	int i,j,k;
	char *temp;
	//    
	for(i=0;i<size;i++){
		k=i;
		for(j=i+1;j<size;j++){
			if(strcmp(arr[k],arr[j])>0){
				k=j;
			}
		}
		if(k!=i){
			temp=arr[k];
			arr[k]=arr[i];
			arr[i]=temp;
		}
	} 
}

int main(void)
{
    char* token;
    char *words[3000];
    char * arr= malloc(sizeof(char) * 30);
    char tmp[3000];
    scanf("%s",arr);
    int nwords;
    FILE * file = fopen("/Users/chaejunghun/Desktop/harry.txt", "r");
    char line[10000];
    
     if (file == NULL) {
            printf("파일열기 실패\n");
            return 1;
        }
    
     int count = 0;
     int cnt = 0;
    int total = 0;
    int i=0;
    while (!feof(file))
    {
        fscanf(file,"%s",tmp);
        if(strncmp(tmp,arr,strlen(arr))==0)
            {
                words[nwords] = strdup(tmp);
                nwords++;
            }
    }
    sort2(words,nwords);//정렬 후 중복 제거.
    /*for (int i = 0; i < nwords; i++)
    {
        printf("%s\n",words[i]);
    }
    */
    //중복제거.
    int unique_cnt = 0;//고유한 문자의 개수
    char* unique[3000];

    for (int i = 0; i < nwords; i++)
    {
        int p = 0;
        while(p<i && strcmp(words[i],words[p]) != 0) p++;
        if (p == i)
        {
            unique[unique_cnt] = strdup(words[i]);
            unique_cnt++;
        }
        
    }
    
    for (int i = 0; i < unique_cnt; i++)
    {
        printf("%s\n",unique[i]);
    }
    printf("%d",unique_cnt);
    fclose(file);
    
    return 0;
}
