/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include<vector>

using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i = 0;
        int j = 0;
        int l1 = nums1.size();
        int l2 = nums2.size();
        while (i < l1 || j < l2){
            if (i>=l1){
                nums.push_back(nums2[j]);
                j++;
                continue;
            }
            if (j>=l2){
                nums.push_back(nums1[i]);
                i++;
                continue;
            }
            if (nums1[i]<=nums2[j]){
                nums.push_back(nums1[i]);
                i++;
                continue;
            }
            if (nums2[j]<=nums1[i]){
                nums.push_back(nums2[j]);
                j++;
                continue;
            }
        }
        int lenght = nums.size();
        int mid = lenght/2;
        int mod = lenght%2;

        if (mod==0){
            double result = (double)(nums1[mid-1]+nums[mid])/2;
            return result;
        }else{
            return (double)nums[mid];
        }
    }
};
// @lc code=end

