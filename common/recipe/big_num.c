/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  在程序中我需要计算2的100次方，请问怎么保存结果
 *                  方案1使用char数组;方案2使用int64[2]??
 *        Version:  1.0
 *        Created:  06/18/2013 06:13:07 PM
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
#include <stdlib.h>

int main(void)
{
//    printf("%s%3d\n", "A", 1);
    int i = 2;
    int j = 100;
    int m = 0;
    static int key = 0;
    static int inc = 0;
    int n = 0;
    char count[128];
    memset(count, '*', 1024);
    long long int c[2] ={0};
    for(int k = 0; k<j;k++)
    {
        for(m=0;count[m] != '*'||count[0]=='*'; m++)
        {
            int tmp=1;
            if(count[m]!='*')
                tmp = count[m]-48;
            tmp*=2;
            n = tmp%10;
            if(inc == 1)
            {
                count[m] = 48+n+1;
                inc = 0;
            }
            else
                count[m] = 48+n;
            key = tmp/10;
            if(key == 1){
                if(count[m+1] == '*')
                {
                    count[m+1] = 49;
                    break;
                }
                inc = 1;
            }
        }
        //printf("%s \n", count);
    }

    for(i = 128;i>=0;i--)
    {
        if(count[i] != '*')
            printf("%c", count[i]);
    }
    memset(count,0,128);
    printf("\n");
    return 0;
}
