//  Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
// Example:
//
// nums = [1, 2, 3]
// target = 4
//
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
//
// Note that different sequences are counted as different combinations.
//
// Therefore the output is 7.
//
//
//
// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers? 
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases." />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //使用dfs超时。
    //我们这么想，target=1,dp[1]=1
    //target=2,dp[2]=dp[2-1]+dp[2-2]+dp[2-3]=2,
    //target=3.dp[3]=dp[3-1]+dp[3-2]+dp[3-3]=4,
    //target=4,dp[4]=dp[4-1]+dp[4-2]+dp[4-3]=7,
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int result  = 0;
        vector<int> dp(target+1,0);
        //dp.reserve(target+1);
        dp[0] = 1;
        for(int i = 1; i < target + 1; i++)
        {
            for (int num : nums)
            {
                if(i >= num)//i:target
                {
                    dp[i] = dp[i] + dp[i - num];
                }
                else
                {
                    break;
                }
            }
        }
        return dp[target];
    }
};
