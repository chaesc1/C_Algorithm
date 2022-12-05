#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    char *word[5000];
    int counter[5000] = {0};//빈도수 체크. 
    int n = 0;
    char buf[40];

    FILE *fp = fopen("./harry.txt","r");

    //어떤 방식으로 file을 읽을건지. 1.한글자씩 2.한 단어씩 3.한즐씩
    
    while (fscanf(fp,"%s",buf)!=EOF)
    {
        //printf("%s\n",buf);
        //중복된 문자 없애 고 정렬해 
        if (strlen(buf) < 6)
        {
            continue;
        }
        
        bool dup = false;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(buf,word[i])==0)
            {
                dup = true;
                counter[i]++;
                break; //중복일경우 브레이크
            }
        }
        if (!dup)//중복된 단어가 아니라면
        {
            int idx = n -1;//맨마지막 인덱스
            while (idx >= 0 && strcmp(buf,word[idx]) < 0)
            {
                word[idx+1] = word[idx];
                counter[idx+1] = counter[idx];
                idx--;
            }
            word[idx+1]  = strdup(buf);
            counter[idx+1] = 1;
            n++;
        }
    }
    fclose(fp);

    /*for (int i = 0; i < n; i++)
    {
        printf("%s\n",word[i]);
    }
    */
    for (int i = 0; i < n; i++)
    {
        printf("%s: %d\n",word[i],counter[i]);
    }
    printf("%d\n",n);
    return 0;
}