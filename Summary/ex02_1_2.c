#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check(char s[],char t[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        //check if s[i] belongs to t
    bool exist = false;
        for (int j = 0; j < strlen(t); j++)
        {
            if (s[i] == t[j])
            {
                exist = true;
                break; 
            }
        }
        //같은 문자를 찾아서 나온경우 2중포문을 다 돌고 나온경우 구분 해야해.
        if (!exist)//못찾았으면
        {
            return false;
        }
    }
    
    return true;
}

void bsort(char s[])//문자열 버블소트.
{
    for (int i = strlen(s)-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[j] > s[j+1])
            {
                char tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;
            }
            
        }
        
    }
}

void compressed(char s[])
{
    int idx = 0;//살아남은 놈의 위치.
    for (int i = 0; i < strlen(s); i++)
    {
        if (i == 0 || s[i] != s[i-1]) // survive
        {
            s[idx++] = s[i];
        }
    }
    s[idx] = '\0'; //문자열의 끝을 알려줘.
}
int main(void)
{
    char word1[20],word2[20];
    scanf("%s",word1);
    scanf("%s",word2);

    int flag1[26] = {0};
    int flag2[26] = {0};
    for (int i = 0; i < strlen(word1); i++)
    {
        flag1[word1[i]-'a'] = 1;// a->0,b->1, .... z-> 25

    }
    for (int i = 0; i < strlen(word2); i++)
    {
        flag2[word2[i]-'a'] = 1;// a->0,b->1, .... z-> 25

    }

    for (int i = 0; i < 26; i++)
    {
        if (flag1[i] != flag2[i])
        {
            printf("no");
            return 0;
        }
         
    }
    printf("yes");
    //bsort(word1);
    //bsort(word2);
    //printf("%s\n",word1);
    //compressed(word1);
    //compressed(word2);
    //printf("%s %s\n",word1,word2);
    /*if (strcmp(word1,word2) == 0)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    */
    return 0;
}

