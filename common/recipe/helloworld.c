/*
 * =====================================================================================
 *
 *       Filename:  helloworld.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/20/2013 05:52:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>

void main(argc, argv)
    int argc;
    char** argv;
{
    //printf("Hello World %d %ld %ld\n", 0%4, 1UL<<22, 1UL);
    int i = 0x7fffffff;
    printf("%d\n", i);
    printf("%d\n", i/100/(24*60*60));
    return ;
}

