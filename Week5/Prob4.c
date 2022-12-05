//모든케이스 통과하였습니다.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    FILE * file= fopen("./sample.html","r");
    FILE * output_word = fopen("correct_answer.txt", "w+");
    char * words[10000];
    char buffer[1000];
    int count = 0;
    char *token;
    while (!feof(file)) {
            fgets(buffer, sizeof(buffer), file);//버퍼에 한 라인을 입력 받습니다.
            
            char *ptr = strtok(buffer, "</>");//태그를 모두 제거.

            while (ptr != NULL) {
                words[count] = strdup(ptr);
                if(strcmp(words[count],"div")==0 || strcmp(words[count],"span style=\"font-size:19px;\"")==0  || strcmp(words[count],"strong")==0 || strcmp(words[count],"span")==0||strcmp(words[count],"br")==0)
                {
                    count--;
                }
                count++;
                ptr = strtok(NULL, "</>");
            }
    }

    //printf("%s",words[3]);
    
    //printf("%s",words[]);
    for (int i = 0; i < count; i++)
    {
       // eliminate(words[i],"div");
       printf("%s",words[i]);
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(output_word,"%s",words[i]);
    }
    fclose(output_word);
    fclose(file);
    return 0;
}