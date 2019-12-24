#include<stdio.h>
#include<stdlib.h>


#define ElementType int  //存储数据元素的类型
#define MAXSIZE 1024 //存储数据元素的最大个数
#define ERROR -99 //ElementType的特殊值，标志错误

//堆栈的顺序存储结构通常由一个一维数组和一个记录栈顶元素位置的变量组成
// 数组实现
typedef struct {
    ElementType data[MAXSIZE];
    int top;
}Stack;

Stack* init_stack(){
    Stack* stack;
    stack = (Stack *)malloc(sizeof(Stack));
    if(!stack){
        printf("空间不足\n");
        return NULL;
    }
    stack->top = -1;
    return stack;
}

int is_full(Stack* stack){
    if(stack->top == MAXSIZE-1){
        printf("栈已满\n");
        return 1;
    }
    return 0;
}

int is_empty(Stack* stack){
    if(stack->top == -1){
        printf("栈为空\n");
        return 1;
    }
    return 0;
}

// 入栈
void push(Stack* stack, ElementType item){
    if(is_full(stack))
        return;
    stack->data[++stack->top] = item;
}

// 出栈

ElementType pop(Stack* stack){
    if(is_empty(stack))
        return ERROR;
    
    return stack->data[stack->top--];
}

void PrintStack(Stack *stack){
    if(is_empty(stack))
        return;
    int i = stack->top;
    for(i;i>=0;i--){
        printf("%d\n", stack->data[i]);
    }
}

// 链表实现 

typedef struct Node{
    ElementType data;
    struct Node* next;
}LinkStack;

LinkStack* init_linkstack(){
    LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
    if(!stack){
        printf("空间不足\n");
        return NULL;
    }
    stack->next = NULL;
    return stack;
}

int is_lempty(LinkStack* stack){
    return (stack->next == NULL);
}

void lpush(LinkStack* s, ElementType item){
    LinkStack* cell;
    cell = (LinkStack*)malloc(sizeof(LinkStack));
    if(!cell){
        printf("空间不足\n");
        return;
    }

    cell->data = item;
    cell->next = s->next;
    s->next = cell;
}

ElementType lpop(LinkStack *s){
    if(is_lempty(s)){
        printf("空栈\n");
        return NULL;
    }
    LinkStack* cell = s->next; 
    ElementType item = cell->data;
    s->next = cell->next;
    free(cell);
    
    return item;
}


