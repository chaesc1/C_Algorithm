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

int main(void)
{
    char word1[20],word2[20];
    scanf("%s",word1);
    scanf("%s",word2);

    bool result1 = check(word1,word2);
    bool result2 = check(word2,word1);

    if (result1 && result2)
    {
        printf("yes");
    }
    else
    {
        printf("no"); 
    }
    
    return 0;
}

