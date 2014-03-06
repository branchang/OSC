/*
 * =====================================================================================
 *
 *       Filename:  backtrace.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/20/2013 04:49:01 PM
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
#include <execinfo.h>

#define MAX_LEVEL 4
static void test2()
{
    int i = 0;
    void* buffer[MAX_LEVEL] = {0};
    int size = backtrace(buffer, MAX_LEVEL);

    for(i=0; i<size; i++)
    {
        printf("call by %p\n", buffer[i]);
    }

    return ;
}

static void test1()
{
    int a=0x11111111;
    int b=0x11111112;

    test2();
    a = b;

    return ;
}

static void test()
{
    int a=0x1000000;
    int b=0x1111112;

    test1();
    a=b;

    return ;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}


