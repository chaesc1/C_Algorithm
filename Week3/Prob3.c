#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Word{
    char words[200];
    char meaning[3000];
}Word;

Word words[200000];

int main(void)
{
    char * token;
    char * word[200000];
    int nwords=0;
    char tmp[200000];
    char * arr= malloc(sizeof(char) * 200000);
    FILE * file= fopen("/Users/chaejunghun/Desktop/shuffled_dict.txt", "r");
    int linecnt = 1;
    
   if (file == NULL) {
            printf("파일열기 실패\n");
            return 1;
        }
    
    else
    {
        char buffer[200000];
        while (!feof(file)) {
            Word word;
 
            fgets(buffer, sizeof(buffer), file);//버퍼에 한 라인을 입력 받습니다.
            
            char *ptr = strtok(buffer, "\t");
            strcpy(word.words, ptr);
        
            while (ptr != NULL) {
                strcpy(word.meaning, ptr);
                ptr = strtok(NULL, "\n");
            }
            words[nwords] = word;
            nwords++;
        }
    }
    char temp[nwords];
    char temp2[nwords];
    for (int i = 0; i < nwords-1; i++)
        {
            int min = i;
            //int min2 = i;
            for (int j = i+1; j < nwords; j++)
            {
                if (strcmp(words[min].words, words[j].words) >  0)
                {
                    min = j;
                }
            }
            if (min != i) {
                strcpy(temp2, words[min].meaning);    
                strcpy(words[min].meaning, words[i].meaning);
                strcpy(words[i].meaning, temp2);
                
                strcpy(temp, words[min].words);    // 바꿀 때 임시로 temp에 저장한다.
                strcpy(words[min].words, words[i].words);
                strcpy(words[i].words, temp);
            }
        }
    
    for (int i=0; i<nwords; i++) {
        printf("%s    %s\n",words[i].words,words[i].meaning);
    }

    FILE * Wfile = fopen("sorted_dict.txt","w+");
	
	if(file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		for (int i = 0; i < nwords; i++)
        {
            fprintf(Wfile,"%s\t%s\n",words[i].words,words[i].meaning);
        }
        
		fclose(Wfile);
	}
    fclose(file);
    return 0;
}
