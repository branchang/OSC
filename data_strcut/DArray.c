/*
 * =====================================================================================
 *
 *       Filename:  DArray.c
 *
 *    Description:  动态数组
 *
 *        Version:  1.0
 *        Created:  09/01/2013 09:39:50 PM
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

#define MIN_PRE_ALLOCATE_NR 10
/*数组空间扩展，一次扩展多个元素，扩展为现有元素个数的1.5倍*/
static int darray_expand(DArray* thiz, size_t need)
{
    assert(thiz!=NULL);

    if((thiz->size+need) > thiz->alloc_size)
    {
        int alloc_size = thiz->alloc_size + (thiz->alloc_size >> 1) + MIN_PRE_ALLOCATE_NR;
        //TODO 这里应该如何定义 void**类型数组保存才是正确的
        void *data = realloc(thiz->data, sizeof(void *)*alloc_size);
        if(data != NULL)
        {
            thiz->data = data;
            thiz->alloc_size = alloc_size;
        }
    }

    return ((thiz->size+need) <= thiz->alloc_size)?1:0;
}

int darray_insert(DArray* thiz, void* new_data,size_t index)
{
    
    //找到节点
    int cursor = index<thiz->size?cursor:thiz->size;
    //TODO 这里是否需要每次都进行扩展，为什么要这样子
    if(darray_expand(thiz, 1) != 0)
    {
        return 1;
    }

    //插入数据，向后移动
    for(int i = thiz->size; i>cursor;i--)
    {
        thiz[i] = thiz[i-1];
    }
    thiz->data[cursor] = data;
    //修改状态标记位
    thiz->size++;

    return 1;
}

/*删除元素时候也不是马上释放空间，而是等到空闲空间高于某个数值才释放
  实现的方法为空闲空间大于使用空间，则调整总空间为使用空间的1.5倍*/

static int darry_shrink(DArray* thiz)
{
    int alloc_size; 
    assert(thiz);
    if(thiz->size < (thiz->alloc_size - thiz->size))
    {
        //调整空间大小
        alloc_size = thiz->size + thiz->size>>1;
        void *data = realloc(thiz->data, sizeof(void *)*alloc_size);
        if(data)
        {
            thiz->data = data;
            thiz->alloc_size = alloc_size;
        }
    }
    return 0;
}

int darray_delete(DArray* thiz, size_t index)
{
    //释放空间
    if(index > thiz->size)
        return 1;
    int cursor = index;
    //调整顺序
    for(int i=cursor;i<thiz->size;i++)
    {
        thiz->data[i] = thiz->data[i+1];
   }
    //调整大小
    thiz->size--;
    //判断是否需要释放空间操作
    darry_shrink(thiz);
    return 0;
}

DArray* darray_create(DataDestroyFunc data_destroy, void* ctx)
{
    return NULL;
}
