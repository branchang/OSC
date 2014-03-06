/*
 * =====================================================================================
 *
 *       Filename:  dlist.c
 *
 *    Description:  开始双向循环列表，后修去掉循环功能
 *                  回调函数的上下文，最好使用指针来传递参数，而不是使用全局变量
 *
 *        Version:  1.0
 *        Created:  10/19/2013 11:42:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <dlist.h>

DList* dlist_create()
{
    DList* list = (DList *)malloc(sizeof(DList));

    list->head_node = NULL;
    list->end_node = NULL;
    list->length = 0;

    return list;
}

int dlist_delete(DList* list, int index)
{
    int i = 0;
    int total = dlist_length(); 
    if(index>total)
        return -1;
    if(index == total)
    {
        //删除最后一个
        DListNode* tmp = list->end_node;
        tmp->prev->next = NULL;
        list->end_node = tmp->prev;
        list->destroy_node(tmp);
        return 0;
    }

    if(index == 1)
    {
        //删除第一个
        DListNode* tmp = list->head_node;
        tmp->next->prev = NULL;
        list->head_node = tmp->next;
        list->destroy_node(tmp);
        return 0;
    }

    DListNode *node = list->head_node;
    for(i;i<index-1;i++)
    {
        node = node->next;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    list->destroy_node(node);

    return 0;
}

int dlist_find(DList* list, DataComparaFunc cmp_func, void* data)
{
    int i = 0;
    
    DListNode* node = list->head_node;
    for(i; i<list->length; i++)
    {
        if(!com_func(data, node->node_data))
            return i;
        node = node->next;
    }

    return 0;
}

int dlist_insert(DList *list, void *data)
{
    DListNode new_node = malloc(sizeof(DListNode));
    //TODO 指针的指针
    new_node->node_data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(list->length == 0)
    {
        list->head_node = new_node;
        list->end_node = new_node;
    }else{
        DListNode* last_node = list->end_node;
        last_node->next = new_node;
        new_node->prev = last_node;
        list->end_node = new_node;
    }

    list->length++;

    return 0;
}

int dlist_get_by_index(DList* list, size_t index, void** data)
{
    int i = 0;
    if(index<=0 && index>list->length)
    {
        return -1;
    }
    
    DListNode* node = list->head_node;
    for(i; i<index-1; i++)
    {
       node = node->next; 
    }

    *data = node->node_data;
    return i;
}

int dlist_set_by_index(DList* list, size_t index, void* data)
{
    int i = 0;
    if(index<=0 && index>list->length)
    {
        return -1;
    }

    DListNode* node = list->head_node;
    for(i; i<index-1; i++)
    {
       node = node->next; 
    }

    node->node_data = data;
    return i;
}

size_t dlist_length(DList* list)
{
    return list->length;
}

void dlist_foreach(DList* list, DataVisitFunc visit_func, void* ctx)
{
    int ret = -1;
    DListNode* node = list->head_node;
    
    //判断ret，可以根据回调函数作出调正
    while(node && !ret)
    {
        ret = visit_func(ctx, node->node_data);
        node = node->next;
    }
    return ret;
}

void dlist_destroy(DList* list)
{
    free(list);
    list = NULL;
}

