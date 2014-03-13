/*
 * =====================================================================================
 *
 *       Filename:  static_1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/17/2011 02:54:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

static int i = 4;
int j = 3;

static void hello(void)
{
    printf("helloworld!\n");
}

int* helloworld(void)
{
    printf("helloworld_2\n");
    return &i;
}

