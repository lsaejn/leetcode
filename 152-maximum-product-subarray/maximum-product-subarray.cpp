// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
// Example 1:
//
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
//
// Example 2:
//
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //试试动态规划
    //[2,3,-2,2,-20,3,4]对于求最大和有用，但是。

    //[2,3,-2,2,-3,2]，
    //2,6,-2,  2 ,72,144
    //2,3,-12,-24,-6,-12
    int maxProduct(vector<int>& nums) 
    {
        int res = nums[0], mx = res, mn = res;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > 0) 
            {
                mx = max(mx * nums[i], nums[i]);
                mn = min(mn * nums[i], nums[i]);
            } 
            else 
            {
                int t = mx;
                mx = max(mn * nums[i], nums[i]);
                mn = min(t * nums[i], nums[i]);
                
            }
            res = max(res, mx);
        }
        return res;
    }
};
