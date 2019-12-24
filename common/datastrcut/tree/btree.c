
typedef struct Node
{
    struct Node *pLeft;
    struct Node *pRight;
    int data;
}LNode, *BinTree;

#define MAXQSIEZE 100
typedef BinTree QElemType;
typedef struct {
    QElemType base[MAXQSIZE];
    int front;
    int rear;
}SqQueue;

void InitQueue(SqQueue *Q)
{
    Q->front = Q->rear=0;

}

int EnQueue(SqQueue *Q, QElemType e)
{
    if((Q->rear+1)%MAXQSIZE == Q->front)
        return -1;
    Q->base[Q->rear] = e;
    Q->rear=(Q->rear+1)%MAXQSIEZE;
    return 0;
}

int DeQueue (SqQueue *Q,QElemType *e)
{
	if(Q->front==Q->rear)
		return -1;
	*e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAXQSIZE;
	return 0;
}


int QueueEmpty(SqQueue Q)
{
	if(Q.rear==Q.front)
		return 1;
	else
		return 0;
}

//B 题目
void Traverse(BiTree T)
{
    SqQueue Q;
    BiTree p;

    p=T;
	InitQueue(&Q);
	if(p) EnQueue(&Q,p);
	while(!QueueEmpty(Q))
	{
		DeQueue(&Q,&p);
		printf("%c",p->data);
		if(p->pLeft) EnQueue(&Q,p->pLeft);
		if(p->pRight) EnQueue(&Q,p->pRight);
	}
	printf("\n");
}

//H 题目
int TreeDeep(BinTree T){
    int deep = 0;

    if(T){
        int leftdeep = TreeDeep(T->pLeft);
        int rightdeep = TreeDeep(T->pRight);
        deep = leftdeep>=rightdeep?leftdeep+1:rightdeep+1;
    }
    return deep;
}

//I  题目 插入
LNode insert(LNode root, int x)
{
    LNode p = (LNode)malloc(LEN);
    p->data = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    if(root == NULL){
        root = p;    
    }    
    else if(x < root->data){
        root->pLeft = insert(root->pLeft, x);    
    }
    else{
        root->pRight = insert(root->pRight, x);    
    }
    return root;
}


//D 题目 删除
int delete_BST(LNode p, int x) //返回一个标志，表示是否找到被删元素 
{
    int find = 0;
    LNode q;
    p = BT;
    while(p && !find){  
        if(x == p->data){  
            find = 1;    
        }    
        else if(x < p->data){ 
            q = p;
            p = p->pLeft;    
        }
        else{   
            q = p;
            p = p->pRight;    
        }
    }
    if(p == NULL){   
        printf("没找到\n");
    }
    
    if(p->pLeft == NULL && p->pRight == NULL){   
        if(p == BT){  
            BT = NULL;    
        }
        else if(q->pLeft == p){   
            q->pLeft = NULL;
        }        
        else{
            q->pRight = NULL;    
        }
        free(p);  
    }
    else if(p->pLeft == NULL || p->pRight == NULL){ 
        if(p == BT){  
            if(p->pLeft == NULL){
                BT = p->pRight;    
            }    
            else{
                BT = p->pLeft;    
            }
        }    
        else{
            if(q->pLeft == p && p->pLeft){ 
                q->pLeft = p->pLeft;   
            }    
            else if(q->pLeft == p && p->pRight){
                q->pLeft = p->pRight;    
            }
            else if(q->pRight == p && p->pLeft){
                q->pRight = p->pLeft;    
            }
            else{
                q->pRight = p->pRight;
            }
        }
        free(p);
    }
    else{
        LNode t = p;
        LNode s = p->pLeft;  
        while(s->pRight){  
            t = s;   
            s = s->pRight;    
        }
        p->data = s->data;   
        if(t == p){
            p->pLeft = s->pLeft;    
        }    
        else{
            t->pRight = s->pLeft;    
        }
        free(s); 
    }
    return find;
}