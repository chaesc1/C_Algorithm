//모든케이스 통과하였습니다.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>


int is_check(char a) //자음이면 1,모음이면 0
{
    int flag = 0;
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
    {
        return flag;
    }
    else
    {
        flag = 1;
        return flag;
    }
}
int main(void)
{   
    char words[100];
    int index = 0;
    
	scanf("%s", words);
    
    int consoCnt[100];//연속된 자음의 개수의 최대값.
    int consonant = 0;//자음개수
    char conso[100];
    for (int i = 0; i < strlen(words); i++)
    {
        for (int j = i; j < strlen(words); j++)
        {
            if (is_check(words[j]) == 0)//모음이면 break
            {
                break;
            }
            if(is_check(words[j]) == 1)//자음이면 더해.
            {
                consonant++;
            }
        }
        consoCnt[i] = consonant;
    }
    
    int max_index = 0, num_sub=0;
    for (int i = 1; i < strlen(words); i++){
        if (consoCnt[i]-consoCnt[i-1] > num_sub){
            num_sub = consoCnt[i]-consoCnt[i-1];
            max_index = i;
        }
    }

    for (int i = max_index; i < max_index + num_sub; i++){
        printf("%c", words[i]);
    }
    return 0;
}