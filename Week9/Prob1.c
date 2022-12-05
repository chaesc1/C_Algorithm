#include <stdio.h>
#include <stdlib.h> //rand()함수 라이브러리
#include <stdbool.h>

#define MAX 100
#define PATH 0
#define COMP 1
#define VISITED 2
#define BACKTRACKED 3 //다시 되돌아 나온길.

int maze[MAX][MAX];
int n;
//int T;//미로의 T*T
typedef struct stack_type *Stack;

typedef struct pos{
    int x,y;
}Position;

int offset[8][2] ={
    {-1,0},//서0
    {-1,-1},//남서1
    {0,-1},//남2
    {1,-1},//동남3
    {1,0},//동4
    {1,1},//북동5
    {0,1},//북6
    {-1,1}//북서7
};

Position move_to(Position pos,int dir)
{
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];
    return next;
}
typedef Position Item;
struct stack_type{
    Item data[MAX];
    int top;
};


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
void push(Stack s, Item item)
{
    s->top++;
    s->data[s->top] = item;
}
Item pop(Stack s)
{
    s->top--;
    return s->data[s->top+1];
}
Item peek(Stack s)
{
    if(is_empty(s))
        printf("Error in peek: stack is empty");
    return s->data[s->top];
}

bool movable(Position cur, int dir){
    /*배열 안에 있고 1 ==> movable*/
    Position next = move_to(cur, dir); // 다음 좌표
    if (((next.x >= 0 && next.x <  n) && (next.y >= 0 && next.y < n )) && (maze[next.x][next.y] == 1)){
        return true;
    }
    else
        return false;
}

int main(void)
{
    Stack s = create();
    Position cur;
    cur.x = 0;
    cur.y = 0;
    
    FILE * file = fopen("./input.txt","r");
    
    int sum;
    int N;//case 개수
    int count = 1;
    fscanf(file,"%d",&N);
    for (int i = 0; i < N; i++)
    {
        fscanf(file,"%d\n",&n);
        count= 1;
        //printf("%d\n",n);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                fscanf(file,"%d\n",&maze[j][k]);
                while (true) {
                    maze[cur.x][cur.y] = VISITED;//방문으로 표시
                    //printf("%d,%d\n",cur.x,cur.y);
                    bool forwarded = false;
                    for (int dir = 0; dir < 8; dir++) {
                        if (movable(cur,dir)) {
                            push(s, cur);
                            count++;
                            cur = move_to(cur, dir);
                            forwarded = true;
                            break;
                        }
                    }
                    if (!forwarded) {
                        maze[cur.x][cur.y] = BACKTRACKED;
        
                        if (is_empty(s))
                        {
                            break;
                        }
                        
                        //마지막 위치를 현재위치로.
                        cur = pop(s);//pop
                        printf("%3d",count);
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}
