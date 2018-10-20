// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
// Example:
//
//
// Input:  [1,2,3,4]
// Output: [24,12,8,6]
//
//
// Note: Please solve it without division and in O(n).
//
// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //1,2,3,4,0,5,6-----(1,2,6,24,0,0,0)+(0,0,0,0,30,6)
    vector<int> productExceptSelf(vector<int>& nums) {
        //我们准备两个dp，一个dp[i]表示i之前的乘积
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);
        left[0]=1;
        right[nums.size()-1]=1;
        for(int i=1;i!=nums.size();++i)
        {
            left[i]=left[i-1]*nums[i-1];//left{1,1} 
            right[nums.size()-1-i]=right[nums.size()-i]*nums[nums.size()-i];//{0,1}
        }
        for(int i=0;i!=nums.size();++i)
        {
            nums[i]=left[i]*right[i];
        }
        return nums;
    }
};
