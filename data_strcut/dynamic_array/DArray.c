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

#include "DArray.h"

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

    return ((thiz->size+need) <= thiz->alloc_size)?0:1;
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
    thiz->data[cursor] = new_data;
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
        void **data = (void **)realloc(thiz->data, sizeof(void *)*alloc_size);
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
    if(index && index > thiz->size)
        return 1;
    int cursor = index;
    //调整顺序 index 符合用户习惯从1开始 i== thiz->size-1时候就是最后一个了,size是数量不是位置
    for(int i=cursor;i < thiz->size;i++)
    {
        thiz->data[i-1] = thiz->data[i];
    }
    //调整大小
    thiz->size--;
    //判断是否需要释放空间操作
    darry_shrink(thiz);
    return 0;
}

//TODO data_destroy作用
DArray* darray_create(DataDestroyFunc data_destroy, void* ctx)
{
    DArray* darray = NULL;
    darray = (DArray *)malloc(sizeof(DArray)); 
    memset(darray, 0, sizeof(DArray));
    if(darray && !darray_expand(darray, 1));
    {
        darray->size = 1;
        darray->alloc_size = 1;
        darray->data[0] = ctx;
        return darray;
    }
    return NULL;
}

int darray_append(DArray* thiz, void* data)
{
    assert(thiz != NULL);
    if(darray_expand(thiz,1) != 0)
    {
        return -1;
    }

    thiz->data[thiz->size] = data;
    thiz->size++;
    return 0;
}

int darray_prepend(DArray* thiz, void* data)
{
    assert(thiz != NULL);
    if(darray_expand(thiz,1) != 0)
    {
        return -1;
    }

    int index;
    for(index = thiz->size; index>0; index--)
    {
        thiz->data[index] = thiz->data[index-1];
    }
    thiz->data[0] = data;
    thiz->size++;
    return 0;
}

size_t darray_length(DArray* thiz)
{
    assert(thiz!=NULL);
    return thiz->size;
}

int darray_get_by_index(DArray* thiz, size_t index, void** data)
{
    assert(thiz != NULL);
    if(index > thiz->size)  
        return -1;

    printf("%x %x\n", data, *data);
    *data = thiz->data[index-1];
    printf("\n");
    return 0;
}

int darray_set_by_index(DArray* thiz, size_t index, void* data)
{
    //FIXME 是不是设置完成后释放掉数据的操作也在这里处理，那么初始化的释放函数就用在了这里
    assert(thiz!=NULL);
    
    //如果大小超过数组只使用最后一个
    printf("%x\n", data);
    if(index > thiz->size && !darray_expand(thiz,1))
    {
        thiz->data[thiz->size] = data;
        thiz->size++;
    }else {
        thiz->data[index] = data;
    }

    return 0;
}

int darray_find(DArray* thiz, DataComparaFunc cmp_func, void* data)
{
    assert(thiz != NULL);
    int index = 0;
    for(index; index < thiz->size; index++)
    {
        if(cmp_func(thiz->data[index], data) == 0)
        {
            return index;
        }
    }

    return -1;
}

int darray_foreach(DArray* thiz, DataVisitFunc visit_func)
{
    assert(thiz!=NULL);
    int index = 0;
    for(index; index < thiz->size; index++ )
    {
        visit_func(thiz->data[index]);
    }
    return 0;
}

void darray_destroy(DArray* thiz)
{
    assert(thiz != NULL);

    free(thiz->data);

    thiz->data = NULL;
    thiz->size = 0;
    thiz->alloc_size = 0;
}
