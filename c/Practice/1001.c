/*
 * =====================================================================================
 *
 *       Filename:  1001.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/2013 06:43:58 PM
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


int mult(const char* para1, const char* para2, char* reault)
{

}
int quare(const char* rpara, const char* npara, char* result)
{
    //判断是否是小数
    char *source = rpara; //TODO 这里裁剪一下元数值
    char *tmp = NULL;
    char tmp1[1024] = {0};
    int len1 = 0;
    if((tmp = strchr(source, '.')) != NULL)
    {
       //计算小数点后几位数
       len1 = (source+strlen(source)-1) - tmp;  
       //转换成整数
       strncpy(tmp1, source, tmp-source);
       strncpy(tmp1+strlen(tmp1), tmp+1, len1);
       printf("%d %s\n", len1, tmp1);
       //乘以N次
    }
    //换算小数点
    //返回正确的结果
    return 0;
}

 
int main(void)
{
    int n;
    long double f;
    unsigned long i=1;
    //scanf("%Lf %d", &f, &n);

    char f1[1024] = {0};
    char n1[1024] = {0};
    char result[1024] = {0};
    scanf("%s %s", f1, n1);
    quare(f1, n1, result);
    printf("%s %s \n", f1, n1);

}

