/*
 * =====================================================================================
 *
 *       Filename:  static_2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/17/2011 03:04:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhang Ran (), orangezhr@gmail.com
 *        Company:  sunniwell
 *
 * =====================================================================================
 */

#include <stdio.h>

extern int j;

//extern int* helloworld();

int main(void)
{

    int *i =  helloworld();
    printf("static 2 %d,%d\n",j, *i);
    (*i)++;
    printf("static 2 %d,%d\n",j, *i);
    return 0;
}
