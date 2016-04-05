//
// Created by Bran on 4/4/16.
//
//插入排序

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Common.h"

void InsertSort(SqList *L) {

    for (int i = 2; i < L->length; ++i) {
        if (L->r[i].key < L->r[i - 1].key) {

            //0 位置是作为哨兵的存在, 临时存储区域
            L->r[0] = L->r[i];
            L->r[i] = L->r[i - 1];
            int j;
            for (j = i - 2; L->r[0].key < L->r[j].key; --j) {
                L->r[j + 1] = L->r[j];
            }
            L->r[j + 1] = L->r[0];
        }
    }
}

void BInsertSort(SqList *L) {
    /*
     * 折半插入排序
     */

}

void ShellInsert(SqList *L, int dk){
    // 对每次step之后的子序列再重新直接插入排序
    int i =0;
    for(i=dk+1;i<L->length;++i){
        if(L->r[i].key < L->r[i-dk].key) {
            L->r[0] = L->r[i];

            int j = 0;
            // 每个元素与自己内部的数据直接插入排序
            for(j=i-dk;j>0&&L->r[0].key<L->r[j].key;j-=dk)
                //找到合适的插入位置,一次向后挪动元素知道找到合适的地点
                L->r[j+dk] = L->r[j];
            L->r[j+dk] = L->r[0];
        }
    }
}


