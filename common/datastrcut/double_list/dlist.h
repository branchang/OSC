/*
 * =====================================================================================
 *
 *       Filename:  dlist.h
 *
 *    Description:  双向链表的头文件
 *
 *        Version:  1.0
 *        Created:  10/19/2013 11:34:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int DataVisitFunc(void* ctx, void* data); 
typedef int DataComparaFunc(void* para1, void* para2); 
typedef int DataDestroyFunc(void* data);

typedef struct _DListNode{
    struct _DListNode *prev;
    struct _DListNode *next;
    void* node_data;
}DListNode;

typedef struct _DList{
    DListNode *head_node;
    DListNode *end_node;
    int length;
}DList;


DList* dlist_create(DataDestroyFunc data_destroy, void* ctx);

int dlist_insert(DList* list, void *data);
int dlist_prepend(DList* list, void *data);
int dlist_delete(DList* list, int index);
int dlist_find(DList* list, DataComparaFunc cmp_func, void* data);
int dlist_get_by_index(DList* list, size_t index, void** data);
int dlist_set_by_index(DList* list, size_t index, void* data);
void dlist_foreach(DList* list, DataVisitFunc visit_func);
size_t dlist_length(DList* list);
void dlist_destroy(DList* list);
