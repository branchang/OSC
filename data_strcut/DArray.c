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
        void *data = realloc(thiz->data, sizeof(void *)*alloc_size);
        if(data != NULL)
        {
            thiz->data = data;
            thiz->alloc_size = alloc_size;
        }
    }

    return ((thiz->size+need) <= thiz->alloc_size)?1:0;
}
