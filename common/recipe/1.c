/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2011 06:02:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int hello()
{
    printf("hi orange\n");
    return 0;
}

int main(void)
{
    int y = hello();
    int z;
    if (y > 0)
        z = y;
    else
        z = -y;
    z;

    return 0;
}

