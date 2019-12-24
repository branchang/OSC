
#include<stdio.h>
#include<stdlib.h>

#define ElementType  int

struct HeapStruct{
    ElementType *Element;
    int Size;
    int Capacity;
};

MaxHeap CreateHeap(){
    MaxHeap h = malloc(sizeof(HeapStruct));
    h->Element=malloc((MaxSize+1)*sizeof(ElementType))
    h->Size=0;
    h->Capacity=Maxsize;
    h->Elenment[0]=MaxData;
    return h;
}

ElementType DeleteMaxHeap(MaxHeap H){
    int child,parent;
    ElementType temp,MaxItem;
    if(IsEmpty(H)){
        printf("堆空");
    }

    MaxItem=H->Element[1];
    temp=H->Element[H->Size--];
    for(parent=1;parent*2>Size;parent=child){
        child=parent*2;
        if(child!=H->size&&H->Element[child+1]>H->Element[child]){
            child++;
        }
        if(H->Element[child]>temp) H->Element[parent]=H->Element[child];
        else break;
    }
    H->Element[parent]=temp;
}

void Insert(ElementType Item,MaxHeap H){
    int i;
    if(IsFull(H)){
        printf("堆已满");
        return;
    }
    i=++H->Size;
    for(;Item>H->Element[i/2];i=i/2)
    H->Element[Size]=H->Element[Size/2];
    H->Element[Size]=Item;
}



/* By Vamei 
   Use an big array to implement heap
   DECLARE: int heap[MAXSIZE] in calling function
   heap[0] : total nodes in the heap
   for a node i, its children are i*2 and i*2+1 (if exists)
   its parent is i/2  */

void insert(int new, int heap[]) 
{
    int childIdx, parentIdx;
    heap[0] = heap[0] + 1;
    heap[heap[0]] = new;
    
    /* recover heap property */
    percolate_up(heap);
}

static void percolate_up(int heap[]) {
    int lightIdx, parentIdx;
    lightIdx  = heap[0];
    parentIdx = lightIdx/2;
    /* lightIdx is root? && swap? */
    while((parentIdx > 0) && (heap[lightIdx] < heap[parentIdx])) {
        /* swap */
        swap(heap + lightIdx, heap + parentIdx); 
        lightIdx  = parentIdx;
        parentIdx = lightIdx/2;
    }
}


int delete_min(int heap[]) 
{
    int min;
    if (heap[0] < 1) {
        /* delete element from an empty heap */
        printf("Error: delete_min from an empty heap.");
        exit(1);
    }

    /* delete root 
       move the last leaf to the root */
    min = heap[1];
    swap(heap + 1, heap + heap[0]);
    heap[0] -= 1;

    /* recover heap property */
    percolate_down(heap);
 
    return min;
}

static void percolate_down(int heap[]) {
    int heavyIdx;
    int childIdx1, childIdx2, minIdx;
    int sign; /* state variable, 1: swap; 0: no swap */

    heavyIdx = 1;
    do {
        sign     = 0;
        childIdx1 = heavyIdx*2;
        childIdx2 = childIdx1 + 1;
        if (childIdx1 > heap[0]) {
            /* both children are null */
            break; 
        }
        else if (childIdx2 > heap[0]) {
            /* right children is null */
            minIdx = childIdx1;
        }
        else {
            minIdx = (heap[childIdx1] < heap[childIdx2]) ?
                          childIdx1 : childIdx2;
        }

        if (heap[heavyIdx] > heap[minIdx]) {
            /* swap with child */
            swap(heap + heavyIdx, heap + minIdx);
            heavyIdx = minIdx;
            sign = 1;
        }
    } while(sign == 1);
}



//堆调整，构建大顶堆，arr[]是待调整的数组，i是待调整的数组
//元素的位置，length是数组的长度
void HeapAdjust(int arr[], int i, int length)
{
	int Child;
	int temp;
	for(;2 * i + 1 < length; i = Child)
	{
		//子节点的位置 = 2 * (parent(父结点)) + 1
		Child = 2 * i + 1;
		//得到子结点中较大的结点
		if(Child < length - 1 && arr[Child + 1] > arr[Child])
				++Child;
		//如果较大的子结点大于父结点那么把较大的子结点往上移动
		//替换它的父结点
		if(arr[i] < arr[Child])
		{
			temp = arr[i];
			arr[i] = arr[Child];
			arr[Child] = temp;
		}
		else
		    break;
	}
}