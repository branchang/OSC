//
// Created by Bran on 4/5/16.
//

#include "Common.h"

void print_SqList(SqList *L) {
    int j = 0;
    for (j; j < MAXSIZE; j++) {
        printf("%d:%d\n", j, L->r[j].key);
    }

}

SqList *create_sqlist(SqList *L){
    memset((void *) L, 0, sizeof(SqList));
    int i = 0;
    srand(time(0));
    for (i; i < MAXSIZE; i++) {
        L->r[i].key = rand() % 100;
        L->length++;
    }

    return L;
}


void test_insert() {
    SqList L;
    memset((void *) &L, 0, sizeof(SqList));
    int i = 1;
    srand(time(0));
    for (i; i < MAXSIZE; i++) {
        L.r[i].key = rand() % 100;
        L.length++;
    }
    L.length++;

    print_SqList(&L);
//    InsertSort(&L);
    //for shell
    int gap =0;
    for(gap=L.length/2;gap>0;gap/=2){
        printf("gap:%d\n", gap);
        ShellInsert(&L, gap);
        print_SqList(&L);
    }
    //end shell
    printf("\n\n");
//    print_SqList(&L);
}
void test_Quick() {
    SqList L;
    create_sqlist(&L);
    print_SqList(&L);
    printf("%d\n", L.length);
    QSort(&L,1,L.length-1);
    print_SqList(&L);
}


void test_simple() {
    SqList L;
    create_sqlist(&L);
    print_SqList(&L);
    SimpleSelectSort(&L);
    print_SqList(&L);
}
