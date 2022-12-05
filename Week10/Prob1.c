#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*bool is_palindrome(char *word,int len)
{
    bool is_palin = true;
    for (int i = 0; i < len / 2; i++)
        {
            if (word[i] != word[len - 1 - i])
            {
                // 회문이 아님
                is_palin = false;
                break;
            }
        }
    return is_palin;
}
*/
bool is_palindrome(char word[],int first,int last)
{
    bool is_palin = true;
    if (first >= last) {//회문이면.
        is_palin = true;
    }
    else
    {
        if (word[first] != word[last]) {
            is_palin = false;
        }
        is_palindrome(word,first+1,last-1);
    }
    return is_palin;
}

int main(void)
{
    char word[100];
    
    scanf("%s",word);
    
    int length = strlen(word);
    if (!is_palindrome(word, 0,length-1)) {//회문이 아니면
        printf("NO");
    }
    else
    {
        printf("Yes");
    }
    
    return 0;
}
