/*
 * =====================================================================================
 *
 *       Filename:  pthread.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2013 11:04:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <pthread.h>
#include <assert.h>

void* start_routine(void* param)
{
    char* str = (char*)param;
    printf("%s %s\n", __func__, str);
    return NULL;
}

void* start_routine_2(void* param)
{
    int i = *(int *)param;
    printf("%s %d\n", __func__, i);
    return NULL;
}

pthread_t create_test_thread()
{
    pthread_t id = 0;
    char str[] = "it is OK!";
    pthread_create(&id, NULL, start_routine, str);
    //sleep(1);
    return id;
}

#define THREAD_NR 10

pthread_t create_test_thread_2()
{
    void* ret = NULL;
    int i;
    pthread_t id[THREAD_NR];
    for(i=0;i<10;i++)
    {
        pthread_create(&id[i], NULL, start_routine_2, &i);
    }
    for(i=0;i<10;i++)
    {
        pthread_join(id[i], &ret);
    }
    //sleep(1);
    return ;
}

int main(int argc, char* argv[])
{
    void* ret = NULL;
    pthread_t id = create_test_thread_2();
    return 0;
}

