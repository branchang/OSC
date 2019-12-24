// doubly link list

#include<stdio.h>
#include<stdlib.h>

typedef struct NodeTag Node;
typedef struct LinkedListTag LinkedList;

struct NodeTag{
    void* data;
    Node* next;
    Node* prev;
};

struct LinkedListTag{
    Node* head;
    Node* tail;
    Node* cur;
    int size;
};

// 创建一个链表，成功返回该链表的指针，否则返回 NULL
LinkedList* create(){
    LinkedList* l = (LinkedList* )malloc(sizeof(LinkedList));
    if (!l){
        return NULL;
    }
    l->head = NULL;
    l->tail = NULL;
    l->cur = NULL;
    l->size = 0;
    return l;
}


int add_back(LinkedList* l, void* data){
    Node* n  = (Node*)malloc(sizeof(Node));

    if(!n)
        return -1;
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    if(l->tail){
        l->tail->next = n;
        n->prev = l->tail;
    }else{
        l->head = n;
    }

    return ++l->size; // 返回链表size
}

// 将元素添加到链表前端，成功返回非0，否则返回0
int add_front(LinkedList* l, void* data){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n) return 0;
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    if(l->head){
        n->next = l->head;
        l->head->prev = n;
        l->head = n;
    }else{
        l->head = n;
    }
    l->tail = n;
    return ++l->size;
}

 // 将元素从末端移除并返回该元素，如果链表为空则返回NULL
 void* remove_back(LinkedList* l){
     Node* temp;
     void* data;
     if(!l->size) return NULL;

     temp = l->tail;
     data = temp->data;
     if (l->head == l->tail){
         l->head = NULL;
         l->tail = NULL;
         l->cur = NULL;
     }else{
         l->tail = l->tail->prev;
         l->tail->next = NULL;
     }
     free(temp);
     --l->size;
     return data;
 }

 void* remove_front(LinkedList* l){
     Node* temp;
     void* data;
     if(!l->size)
        return NULL;
    temp = l->head;
    data = l->head->data;

    if(l->head==l->tail)
    {
        l->head = NULL;
        l->tail = NULL;
        l->cur = NULL;
    }else{
        l->head = l->head->next;
        l->head->prev = NULL;
    }
    --l->size;
    free(temp);
    return data;
}

int is_empty(LinkedList* l)
{
    return l->size == 0;
}

int size(LinkedList* l)
{
    return l->size;
}

void begin(LinkedList* l)
{
    l->cur = l->head;
}

void end(LinkedList* l)
{
    l->cur = l->tail;
}

// 清空链元素
void clear(LinkedList* l)
{
    while(remove_back(l));
}
// 销毁
void destory(LinkedList* l)
{
    clear(l);
    free(l);
}

// 正向打印

void traverse(LinkedList* l)
{

}
// 反向
void rtraverse(LinkedList* l)
{

}
