//
//  main.c
//  Week10_prob2
//
//  Created by 채정훈 on 11/21/22.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int compare(char *str1, char *str2)
{
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;
    }
    else if(*str1 > *str2)
    {
        return 1;
    }
    else if(*str1 < *str2)
    {
        return -1;
    }
    else
    {
        *str1++;
        *str2++;
        return compare(str1, str2);
    }
}

int main(void)
{
    char word1[100];
    char word2[100];
    char tmp[100];
    scanf("%s",word1);
    scanf("%s",word2);
    
    //printf("%d",compare(word1, word2));
    if (compare(word1, word2) == 1) {//늦으면
        
        strcpy(tmp, word1);
        strcpy(word1, word2);
        strcpy(word2, tmp);
        printf("%s %s",word1,word2);
    }
    else if(compare(word1, word2) == -1)
    {
        
        printf("%s %s",word1,word2);
    }
    else //같으면
    {
        printf("%s %s",word1,word2);
    }
    return 0;
}
