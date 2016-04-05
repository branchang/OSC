//
// Created by Bran on 4/4/16.
//

#include "Common.h"

int Partition(SqList *L, int low, int high){
    L->r[0] = L->r[low];
    KeyType pivotkey = L->r[low].key;

    while (low < high){
        while (low<high && L->r[high].key>=pivotkey)
            --high;
        L->r[low] = L->r[high];

        while (low<high && L->r[low].key<=pivotkey)
            ++low;
        L->r[high] = L->r[low];
    }
    L->r[low] = L->r[0];
    return low;
}

void QSort(SqList *L, int low, int high){

    if (low<high){
        int pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc-1);
        QSort(L, pivotloc+1, high);
    }
}