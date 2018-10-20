// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
//
// Find the maximum coins you can collect by bursting the balloons wisely.
//
// Note:
//
//
// 	You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// 	0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
//
//
// Example:
//
//
// Input: [3,1,5,8]
// Output: 167 
// Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
//
//


//dp[i][j] = max(dp[i][j], nums[i - 1]*nums[k]*nums[j + 1] + dp[i][k - 1] + dp[k + 1][j])  
//这个公式很明显，但是怎么开始递推缺很恼人
class Solution {
public:
int maxCoins(vector<int>& iNums) {
    int nums[iNums.size() + 2];
    int n = 1;
    for (int x : iNums) 
        if (x > 0) 
            nums[n++] = x;
    nums[0] = nums[n++] = 1;


    int dp[n][n] = {};
    for (int k = 2; k < n; ++k)
        for (int left_ = 0; left_ < n - k; ++left_)
        {
            int right_ = left_ + k;
            for (int i = left_ + 1; i < right_; ++i)
                dp[left_][right_] = max(dp[left_][right_],nums[left_] * nums[i] * nums[right_] + dp[left_][i] + dp[i][right_]);
        }

    return dp[0][n - 1];
}
};
