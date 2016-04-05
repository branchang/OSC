//
// Created by Bran on 4/4/16.
//

#ifndef SORTING_COMMON_H
#define SORTING_COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAXSIZE 20
typedef int KeyType;
typedef void * InfoType;
typedef struct {
    KeyType key;
    InfoType otherinfo;
}RedType;

typedef struct {
    RedType r[MAXSIZE+1];
    int length;
}SqList;


void QSort(SqList *L, int low, int high);
void ShellInsert(SqList *L, int dk);
void InsertSort(SqList *L);
void SimpleSelectSort(SqList *L);

void test_insert();
void test_Quick();
void test_simple();

#endif //SORTING_COMMON_H
