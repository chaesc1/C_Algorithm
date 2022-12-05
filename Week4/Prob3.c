//모든케이스 통과입니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compress(char string[]);

int main(void){
    FILE * file= fopen("/Users/chaejunghun/Desktop/3-2학기 과정/dataStructure/Week4/table.txt","r");
    FILE * output_word = fopen("output.txt", "w+");

    int rows, cols, count = 0;
    char *token;
    char *word_arr[100];
    char buff[200];
    int max_num[4]; //각 열 maxlen 담은 배열 선언.

    fscanf(file, "%d %d\n", &rows, &cols); // \n넣는 이유 => fscanf후 \n이 그대로 남아있어서, 출력에 error 발생 ==> 해결

    while(fgets(buff, sizeof(buff), file)){
        token = strtok(buff, "&");
        word_arr[count++] = strdup(token);
        for (int i = 1; i < cols-1; i++){
            token = strtok(NULL, "&");
            word_arr[count++] = strdup(token);
        }
        token = strtok(NULL, "\n");
        word_arr[count++] = strdup(token);
    }
    
    //문자열 압축 시켰음.
    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if (compress(word_arr[index]) <= 0){
                word_arr[index] = NULL;
            }
            index++;
            
        }
    }

    //각 열의 maxlen을 max_num 배열에 저장
    int maxlen = 0;
    for (int i =0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if ((word_arr[(4*j)+i]) == NULL)
            {
                continue;
            }
            else
            {
                if(maxlen < strlen(word_arr[(4*j)+i]))
                    maxlen = strlen(word_arr[(4*j)+i]);
            }
        }
        max_num[i] = maxlen;
    }
    //형식 맞춰서 배열 진행
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (word_arr[(4*i)+j] == NULL){//공백문자면 열의 최대값 만큼 공백처리
                for (int k = 0; k < max_num[j]; k++){
                    fprintf(output_word,"%s", " ");
                }
            }
            else{
                fprintf(output_word,"%s", word_arr[(4*i)+j]);//문자를 출력후 최대에서 문자길이 뺸만큼 화이트스페이스.
                for (int k = 0; k < max_num[j] - strlen(word_arr[(4*i)+j]); k++){
                    fprintf(output_word,"%s", " ");
                }
            }
            fprintf(output_word,"%s"," ");//마지막 공배
        }
       
        fprintf(output_word,"%s","\n");
    }
    
    
        
    return 0;
}

//압축
int compress(char string[]){
    char temp[100];
    char *token;
    int len = 0;

    token = strtok(string, " ");
    if (token == NULL){
        return 0;
    }
    strcpy(temp, token);
    len += strlen(token);

    while ((token = strtok(NULL, " ")) != NULL){
        temp[len++] = ' '; //' '-> 문자 하나, " " -> character pointer와 같은 문자열.
        temp[len] = '\0';
        strcat(temp, token);
        len += strlen(token);
    }
    strcpy(string, temp);

    return len;
}
