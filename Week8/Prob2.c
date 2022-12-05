#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char Item;
typedef struct stack_type *Stack;

#define INIT_CAPACITY 100



struct stack_type{
	char* stackname;
    char *data[100];
    int size;
    int top;
};


static void terminate(const char* message)
{
    printf("%s\n",message);
    exit(1);
}
Stack create(char *stackName){
    
    Stack s = (Stack)malloc(sizeof(struct stack_type));
    s->stackname = stackName;
    s->top = -1;

    return s;
}

void make_empty(Stack s)//비우는것
{
    s->top=-1;
}
bool is_empty(Stack s)
{
    return s->top ==-1;
}
bool is_full(Stack s)
{
    return s->top==s->size-1;
}

void push(Stack s,char* item)
{
	//strcmp(s->stackname,)
    if(is_full(s))
    {
        reallocate(s);
    }
    s->data[++(s->top)]=item;
}
void pop(Stack s)
{
    if(is_empty(s))
        terminate("Error in popL stack is empty");
    printf("%s\n",s->data[s->top]);
    s->top--;
}

void list(Stack s)
{
    while (!is_empty(s))
    {
        printf("%s\n",s->data[s->top]);
        s->top--;
    }
    
}



int main(void)
{
	Stack stacks[10];
    int n = 0;
    char *name;
	char prompt[100];
    char *command,*item;
    while (1)
    {
        printf("$ ");

        fgets(prompt,sizeof(prompt),stdin);

        if(prompt[strlen(prompt) - 1] == '\n')
            prompt[strlen(prompt) - 1] = '\0';

        command = strtok(prompt," ");
        if (strcmp(command,"create") == 0)
        {
			name = strtok(NULL, " ");
            stacks[n] = create(strdup(name));
            n++;
        }
        else if (strcmp(command,"push") == 0)
        {
			name = strtok(NULL, " ");
            item = strtok(NULL," ");
            for (int i = 0; i < n; i++)
            {
                if (strcmp(name,stacks[i]->stackname) == 0)
                {
                    push(stacks[i],strdup(item));
                }   
            }
        }
        else if (strcmp(command,"pop") == 0)
        {
			name = strtok(NULL, " ");
            for (int i = 0; i < n; i++)
            {
                if (strcmp(name,stacks[i]->stackname) == 0)
                {
                    pop(stacks[i]);
                }   
            }
        }
        else if (strcmp(command,"list") == 0)
        {
			name = strtok(NULL, " ");
            for (int i = 0; i < n; i++)
            {
                if (strcmp(name,stacks[i]->stackname) == 0)
                {
                    list(stacks[i]);
                }   
            }
        }
        else if(strcmp(command,"exit") == 0)
        {
            break;
        }
    }

    return 0;
}