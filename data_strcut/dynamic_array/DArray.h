/*
 * =====================================================================================
 *
 *       Filename:  DArray.h
 *
 *    Description:  动态数组头文件 
 *
 *        Version:  1.0
 *        Created:  09/01/2013 09:40:11 PM
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
#include <assert.h>

struct _DArray;
typedef struct _DArray DArray;

typedef int DataVisitFunc(void* data); 
typedef int DataComparaFunc(void* para1, void* para2); 
typedef int DataDestroyFunc(void* data);

DArray* darray_create(DataDestroyFunc data_destroy, void* ctx);

int darray_insert(DArray* thiz, void* data,size_t index);
int darray_prepend(DArray* thiz, void* data);
int darray_append(DArray* thiz, void* data);
int darray_delete(DArray* thiz, size_t index);
int darray_get_by_index(DArray* thiz, size_t index, void** data);
int darray_set_by_index(DArray* thiz, size_t index, void* data);
size_t darray_length(DArray* thiz);
int darray_find(DArray* thiz, DataComparaFunc cmp_func, void* data);
int darray_foreach(DArray* thiz, DataVisitFunc visit_func);
void darray_destroy(DArray* thiz);

struct _DArray{
    void** data; 
    int size;
    int alloc_size;
};
