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

int main(int argc, void* argv)
{
    person_data* pdata = NULL;
    pdata = (person_data *)malloc(sizeof(person_data));
    strncpy(pdata->name, "BranZhang", strlen("BranZhang"));
    pdata->age = 32;
    strncpy(pdata->address, "HaiDian,BEIJING,CHINA",strlen("HaiDian,BEIJING,CHINA"));
    DArray* parray = darray_create(data_destroy, (void *)pdata);

    darray_foreach(parray, printf_data);

    return 0;
}
