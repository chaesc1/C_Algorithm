#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top = -1;

int IsEmpty()
{
    if (top < 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull()
{
    if (top >= MAX_STACK_SIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int value)
{
    if(IsFull())
    {
        printf("Stack is Full");
    }
    else
    {
        stack[++top] = value;
    }
}

int pop() {
	if (top <= -1) {

		printf("Stack Empty\n");

		return 0;

	}
    return stack[top--];
}

int main(void)
{
    char str[100];//수식입력
    char ch;

    scanf("%s",str);
    int len = strlen(str);
    int i=0;
    //printf("%s\n%d",str,len);
    int in=1;
    char tmp;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            printf("%d",in);
            push(in++);//왼쪽 괄호 만나면 스택에 삽입
        }
        if (str[i] == ')')
        {
            printf("%d",pop());//오른쪽 괄호 만나면 스택에서 pop
        }
        i++;
    }
    
    return 0;
}