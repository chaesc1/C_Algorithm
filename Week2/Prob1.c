#include <stdio.h>
#include <string.h>
#define MAX_LEN 20

int is_dup(char word[],int size,char ch)//문자열 word안에 ch가 있으면 1,없으면 0
{
    for (int i = 0; i < size; i++)
    {
        if (word[i] == ch)
        {
            return 1;
        } 
    }
    return 0;
}

int main(void)
{
    int step,i,length_1,length_2;

    char str[MAX_LEN],str2[MAX_LEN],temp;
    char shortedWord[MAX_LEN] = "";
    char shortedWord2[MAX_LEN] = "";
    scanf("%s",str);
    scanf("%s",str2);

    length_1= strlen(str);
    length_2 = strlen(str2);

    for (step = 0; step < length_1-1; step++)
    {
        for ( i = 0; i < length_1-1-step; i++)
        {
            if (str[i] > str[i+1])
            {
                 temp = str[i];
                 str[i] = str[i+1];
                 str[i+1] = temp;
            }
        }
    }//문자열 정렬.

    for (step = 0; step < length_2-1; step++)
    {
        for ( i = 0; i < length_2-1-step; i++)
        {
            if (str2[i] > str2[i+1])
            {
                 temp = str2[i];
                 str2[i] = str2[i+1];
                 str2[i+1] = temp;
            }
        }
    }//문자열 정렬.
    //printf("%s\n",str);
    //printf("%s",str2);
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; str[i]!='\0'; i++)
    {
        if (is_dup(shortedWord,MAX_LEN,str[i]) == 0)
        {
            shortedWord[cnt++] = str[i];
        }
    }
    
    for (int i = 0; str2[i] != '\0'; i++)
    {
        if (is_dup(shortedWord2,MAX_LEN,str2[i]) == 0)
        {
            shortedWord2[cnt2++] = str2[i];
        }
    }
    
    //printf("%s\n",shortedWord);
    //printf("%s",shortedWord2); //순수한 단어들만 뽑아내는 과정

    if(strcmp(shortedWord,shortedWord2) == 0)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    
    return 0;
}