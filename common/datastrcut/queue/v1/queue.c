/*
 * =====================================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/20/2013 12:34:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

Queue* queue_create(DataDestroyFunc data_destroy, void* ctx)
{
    Queue* que = (Queue*)malloc(sizeof(Queue));
    if(que != NULL)
    {
        que->dlist = list_create(data_destroy, ctx);
        if(!que->dlist)
        {
            free(que);
            que = NULL;
        }
    }

    return que;
}
//获取队列头的元素
int queue_head(Queue* thiz, void **data)
{
    return dlist_get_by_index(thiz->dlist, 1, data);
}

int queue_push(Queue* thiz, void* data)
{
    return dlist_insert(thiz->dlist, data);
}

int queue_pop(Queue* thiz)
{
    return dlist_delete(thiz->dlist, 1)
}

int queue_length(Queue* thiz)
{
    return thiz->length;
}

int queue_foreach(Queue* thiz, DataVisitFunc visit, void* ctx)
{
    return dlist_foreach(thiz->dlist, visit, ctx);
}

int queue_destroy(Queue* thiz)
{
    dlist_destroy(thiz->dlist);
    this->dlist = NULL;
}

