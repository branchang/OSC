/*
 * =====================================================================================
 *
 *       Filename:  crypt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/17/2012 12:28:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char newp[32] = {0};
    char *old = NULL;
    old = crypt("3008","$1$WQRDZSd1$"); 
    printf("%s\n", old);
    return 0;
}

