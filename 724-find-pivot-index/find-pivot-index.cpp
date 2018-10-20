// Given an array of integers nums, write a method that returns the "pivot" index of this array.
//
// We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
//
// If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
//
//
// Example 1:
//
// Input: 
// nums = [1, 7, 3, 6, 5, 6]
// Output: 3
// Explanation: 
// The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
// Also, 3 is the first index where this occurs.
//
//
//
// Example 2:
//
// Input: 
// nums = [1, 2, 3]
// Output: -1
// Explanation: 
// There is no index that satisfies the conditions in the problem statement.
//
//
//
// Note:
// The length of nums will be in the range [0, 10000].
// Each element nums[i] will be an integer in the range [-1000, 1000].
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //要求找到第一个符合这个要求的index：左边的和==右边的和
    //我们让sum_left=0,sum_right=sum_of_array
    //然后依次遍历元素，让它在pos=[1,size-1]前进，每次sum_left+nums[i-1],sum_right-=nums[i-1]
    int pivotIndex(vector<int>& nums) 
    {
        //1233
          int sum = accumulate(nums.begin(), nums.end(), 0);
        int curSum = 0;//遍历到本元素时，不包括本元素的和，也就是i左边的和
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (sum - nums[i] == 2 * curSum) 
                return i;
            curSum += nums[i];
        }
        return -1; 
    }
};
