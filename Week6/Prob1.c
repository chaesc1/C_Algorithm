#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Word
{
    char* words;
    int count;
}Word;

struct node
{
    char *word;
    int count;
    struct  node *next;
};
typedef struct node Node;
Node *head = NULL;

void PrintList(Node *head)
{
    Node *curr = head;
    while (curr != NULL) {
        printf("%s : %d\n",curr->word,curr->count);
        curr = curr -> next;
    }
}
Node * createNode(char*item,int count)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    
    temp->next = NULL;
    temp->word = item;
    temp->count = count;
    
    return temp;
}
void add_first(char *item,int count)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp -> word = item;
    temp -> count = count;
    temp -> next = head;
}

void addNode(Node **head, char* item,int count){
    // 전달받은 값을 저장하는 새로운 노드를 생성한다.
    Node *newNode = createNode(item,count);
    // 헤드에 아무것도 없을 경우    // 즉, 현재 노드가 하나도 없을 경우
    if(*head == NULL){
        // 헤드에 생성한 노드를 연결
        *head = newNode;
    }
    else{
        Node *temp = *head;
        //마지막 노드를 찾는 루프
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        // 마지막 노드일 경우 새로 생성한 노드 연결
        temp->next = newNode;
    }
}
void Remove_node(Node **phead,int num)
{
    Node *curr, *prev = NULL;
    curr = *phead;
    while (curr != NULL) {
        if (curr -> count <= num) {
            
            if (prev == NULL) {
                *phead = curr -> next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    \
}
void sortedInsert( Node** head,  Node* newNode)
{
    Node dummy;
    Node* current = &dummy;
    char * temp = NULL;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->count > newNode->count) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}
void insertSort(Node** head)
{
    Node* result = NULL;     // 여기에 답을 작성합니다.
    Node* current = *head;   // 원래 목록을 반복합니다.
    Node* next;
 
    while (current != NULL)
    {
        // 변경하기 전에 다음 포인터를 확인합니다.
        next = current->next;
 
        sortedInsert(&result, current);
        current = next;
    }
 
    *head = result;
}
int main(void)
{
    //Word words[20000];
    FILE* file = fopen("/Users/chaejunghun/Desktop/3-2학기 과정/dataStructure/Week6/harry.txt","r");
    

    char * word[200000];
    int counter[200000] = {0};
    char tmp[200000];
    int nwords = 0;

    while (fscanf(file,"%s ",tmp)!=EOF)
    {
        bool duplicated = false;
        for (int i=0; i<nwords; i++) {
            if (strcmp(tmp, word[i]) == 0) {
                duplicated = true;
                counter[i]++;
                break;
            }
        }
        if (!duplicated) {
            //중복된 단어가 아니라면
            int j = nwords-1;
            while (j>=0 && strcmp(tmp, word[j])<0) {
                word[j+1] = word[j];
                counter[j+1] = counter[j];
                j--;
            }
            word[j+1] = strdup(tmp);
            counter[j+1] = 1;
            nwords++;
        }
    }//정렬후 노드에 삽입하는 알고리즘이 간단함.
    
    Node *p = head;
    
    for (int i = 0; i < nwords; i++)
    {
        addNode(&p, word[i], counter[i]);//노드 추가.
    }
    PrintList(p);
    printf("%d\n",nwords); //1번 정답.
    printf("----------------\n");
    //2번 시작
    int count_under=0;
    for (int i = 0; i < nwords; i++)
    {
        if (counter[i]>10) {
            count_under++;
        }
        Remove_node(&p, 10);//10이하인 노드 삭제.
    }
    PrintList(p);
    printf("%d\n",count_under);
    
    printf("-------3번----------\n");
    insertSort(&p);
    PrintList(p);
    
    fclose(file);
    return 0;
}
