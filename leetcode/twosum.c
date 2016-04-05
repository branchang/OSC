/*
 * =====================================================================================
 *
 *       Filename:  twosum.c
 *
 *    Description:  1
 *
 *        Version:  1.0
 *        Created:  09/29/2015 18:04:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bran
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

/* *
 * * Note: The returned array must be malloced, assume caller calls free().
 * */ 

int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int *temp = NULL;
    for(i=0; i<numsSize;i++){
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target){
                goto FIND;
            }
        }
    }
FIND:
    temp = (int *)malloc(2*sizeof(int));
    temp[0] = i+1;
    temp[1] = j+1;
    return temp;
}


void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;  
            if(i < j) 
                s[i++] = s[j];

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;  
            if(i < j) 
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);
    }
}


int* twoSum2(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int *temp = NULL;
    for(i=0; i<numsSize;i++){
        int ll = target - nums[i];
        
    }
FIND:
    temp = (int *)malloc(2*sizeof(int));
    temp[0] = i+1;
    temp[1] = j+1;
    return temp;
}

int main(void){
    int num[4] = {4,3,2,1};
    int * temp = twoSum(num, sizeof(num)/sizeof(int), 6);
    printf("%d %d \n", temp[0], temp[1]);
    free(temp);

    return -1;
}
