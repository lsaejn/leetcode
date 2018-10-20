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
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


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
