#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INIT_CAPACITY 1000000

typedef int Item;
typedef struct stack_type *Stack;

Stack create();
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s,int i,int count);
int solve(Stack s , Item i);
Item pop(Stack s);
Item peek(Stack s);


struct stack_type{
    Item data[INIT_CAPACITY];
    Item small_num[INIT_CAPACITY];
    int top;
};

static void terminate(const char* message)
{
    printf("%s\n",message);
    exit(1);
}
Stack create()
{
    Stack s = (Stack)malloc(sizeof(struct stack_type));
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

void push(Stack s,int item,int count)
{
    s->top++;
    s->small_num[s->top] = count;
    s->data[s->top]=item;
}
Item pop(Stack s)
{
    if(is_empty(s))
        terminate("Error in popL stack is empty");
    s->top--;
    return s->data[s->top+1];
}
Item peek(Stack s)
{
    if(is_empty(s))
        terminate("Error in peek: stack is empty");
    return s->data[s->top];
}

int main(void)
{
    time_t start = clock();

    Stack s = create();//스택 생성.
    FILE * fp = fopen("./input.txt","r");

    int T = 0;//case 개수
    fscanf(fp,"%d\n",&T); //case개수 읽어와
    int  N; //몇개의 데이터 받아야하냐.
    int result = 0;
    for (int i = 0; i < T; i++)
    {
        result = 0;
        int number; // data 값
        fscanf(fp,"%d\n",&N);
        for (int j = 0; j < N; j++)
        {
            int count = 0;
            fscanf(fp,"%d ",&number);
            
            while (true)
            {
                if (is_empty(s) || peek(s) > number)
                {
                    push(s,number,count);
                    result+=count;
                    break;
                }
                count++;
                count += s->small_num[s->top];
                pop(s);
            }
            result %= 1000000;
        }
        //printf("\n");
        printf("%d\n",result);
        
        make_empty(s);
    }

    time_t end = clock();
    printf("%lf",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
