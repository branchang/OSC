//
// Created by Bran on 4/5/16.
//

#include "Common.h"

int SelectMinKey(SqList *L, int index){
    int min = index;
    int i = index +1;
    for(i;i<L->length;i++){
        if(L->r[i].key < L->r[min].key){
            // 从index之后找出最小的一个 返回位置结果
            min = i;
        }
    }
    return min;
}

void SimpleSelectSort(SqList *L){
    /*
     * 简单选择排序算法
     */
    int i = 0;
    for(;i<L->length;i++){
        int j = SelectMinKey(L, i);
        if(i!=j)
        {
            RedType temp = L->r[i];
            L->r[i] = L->r[j];
            L->r[j] = temp;
        }
    }
}