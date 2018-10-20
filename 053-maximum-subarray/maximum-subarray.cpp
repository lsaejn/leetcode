// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
//
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //明显的动态规划,因为是连续的，所以这个子序列：1.取前面和后面的元素则和变小，
        //比如，如果4，左边的dp(取该元素)是依次[-2，1,-2，4,3,5,6,1,5][]
        if(nums.empty()) return 0;
        vector<int> vec;
        vec.push_back(nums[0]);
        for(int i=1;i!=nums.size();++i)
        {
            if(vec.back()<0)
                vec.push_back(nums[i]);
            else
                vec.push_back(nums[i]+vec.back());            
        }
        int max=INT32_MIN;
        for(int i=0;i!=vec.size();++i)
        {
            if (vec[i]>max)
                max=vec[i];
        }
        return max;
    }
};
