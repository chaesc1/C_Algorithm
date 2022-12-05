#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>

char isCheck(char words,int index)//문자와 index를 가져와.
{
    int count = 0;
    char temp;

    temp = words;
    if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
    {//모음이면
        count = 0;
    }
    else
    {

    }
    
    return words;
}
int main(void)
{
    char  words[100],checkchar = 0;
    int count = 0;
    int index = 0;
    scanf("%s",words);
    char temp = '\0';

    while (1)
    {
        isCheck(words[index],index);
        printf("%c", isCheck(words[index],index));
        index++;
        if(words[index] == '\0')
            break;
    }
    
    
    return 0;
}