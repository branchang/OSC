/*
 * =====================================================================================
 *
 *       Filename:  test_main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2013 11:51:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "DArray.h"

typedef struct _Data{
    char name[32];
    int age;
    char address[322];
}person_data;

int data_destroy(void* data)
{
    free(data);
    return 0;
}
int printf_data(void* in_data)
{
    person_data* pdata = (person_data*)in_data;
    printf("name:%s age:%d address:%s \n", pdata->name, pdata->age, pdata->address);
    return 0;
}

int cmp_func(void* para1, void* para2)
{
    return strcmp(((person_data *)para1)->name, ((person_data *)para2)->name);
}

int main(int argc, void* argv)
{
    person_data* pdata = NULL;
    pdata = (person_data *)malloc(sizeof(person_data));
    strncpy(pdata->name, "BranZhang", strlen("BranZhang"));
    pdata->age = 32;
    strncpy(pdata->address, "HaiDian,BEIJING,CHINA",strlen("HaiDian,BEIJING,CHINA"));
    DArray* parray = darray_create(data_destroy, (void *)pdata);

    int i;
    for(i=0; i<10;i++)
    {
        pdata = (person_data *)malloc(sizeof(person_data));
        memset(pdata, 0, sizeof(person_data));
        sprintf(pdata->name, "Bran[%d]", i);
        pdata->age = (i+1)*8;
        sprintf(pdata->address, "street NO.%d HaiDian,BEIJING,CHINA",i+1);
        darray_append(parray, (void *)pdata);
        pdata = NULL;
    }

    darray_foreach(parray, printf_data);
    darray_delete(parray, darray_length(parray));
    printf("\n");
    darray_foreach(parray, printf_data);

    void *ppdata = NULL;
    printf("%x %x\n", &ppdata, ppdata);
    darray_get_by_index(parray, 10, &ppdata);
    printf("\n");
    printf_data(ppdata);



    printf("\n");
    pdata = (person_data *)malloc(sizeof(person_data));
    memset(pdata, 0, sizeof(person_data));
    strncpy(pdata->name, "Orange", strlen("Orange"));
    pdata->age = 44;
    strncpy(pdata->address, "HaiDian,BEIJING,CHINA",strlen("HaiDian,BEIJING,CHINA"));
    printf("%x\n",pdata);
    darray_set_by_index(parray, 7, pdata);
    darray_foreach(parray, printf_data);

    printf("\n");
    printf("find %d \n", darray_find(parray, cmp_func, pdata));

    strncpy(pdata->name, "first Orange", strlen("first Orange"));
    darray_prepend(parray, pdata);
    darray_foreach(parray, printf_data);
    printf("\n");

    darray_destroy(parray);

    return 0;
}
