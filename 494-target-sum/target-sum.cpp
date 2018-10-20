//
// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
//
//
// Find out how many ways to assign symbols to make sum of integers equal to target S.  
//
//
// Example 1:
//
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 
//
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
//
// There are 5 ways to assign symbols to make the sum of nums be target 3.
//
//
//
// Note:
//
// The length of the given array is positive and will not exceed 20. 
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina



    //现在流行暴力破解吗？第一眼望去，根本没有技巧可言，就是深度遍历
    /*
    set = {a,b,c,d} 如果 a+b -c-d = S,那么split positive and negative 就有a+b = S + c + d,
就有 a+b+c+d = S + 2(c + d), if total = a+b+c+d, then c+d = (total - S)/2 where total - S should be even, then we just need to find the number of subsets with target sum = (total - S) / 2.
*/
    
class Solution {
public:
    int subsetSum(vector<int>& nums, int s) {
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        for (int num : nums) 
            for (int i =s; i >= num; i--)
                dp[i] += dp[i - num];
        return dp[s];
    }

    int findTargetSumWays(vector<int>& nums, int s) 
    {
        int sum = 0;
        for (int n : nums)
            sum += n;
        return sum < s || (s + sum) % 2 > 0 ? 0 : subsetSum(nums, -(s - sum) / 2);
    }
};
    
    
    /*
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        if(nums.size()==0) return S==0;
        return helper(nums,0,nums.size(),0,S);      
    }
    
    //pos:0-nums.size()-1
    int helper(vector<int>& nums,int pos,int end,int now,int target)
    {
        //todo
        if(pos==end)
        {
            if(now==target) 
                return 1;  
            else return 0;
        }
        int result=0;
        result+=helper(nums,pos+1,end,now+nums[pos],target)+helper(nums,pos+1,end,now-nums[pos],target);
        return result;       
    }*/
