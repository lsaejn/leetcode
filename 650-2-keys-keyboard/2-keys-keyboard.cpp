//
// Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step: 
//
// Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
//
//
//
//
// Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'. 
//
//
// Example 1:
//
// Input: 3
// Output: 3
// Explanation:
// Intitally, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.
//
//
//
//
// Note:
//
// The n will be in the range [1, 1000].
//
//


class Solution {
public:
    //第一反应是，可以递归，也可以用动态规划
    //因为dp比较快，我们先怼dp
    //dp[1]=0,dp[2]=2,dp[3]=3;dp[4]=4;dp[5]=5;dp[6]=5
    //dp[n]=min(dp[n/2]+2,dp[n-1])
    int minSteps(int n) {
        vector<int> dp(1 + n, INT32_MAX);
        dp[1] = 0;
        dp[2] = 2;
        help(dp, 2, 1);
        return dp[n];
    }

    void help(vector<int>& dp, int pos, int stride)//2,1
    {
        int new_pos1 = pos + stride;//3
        int new_pos2 = pos * 2;//4
        if (new_pos1<dp.size())//以stride走到new_pos1
        {
            if (dp[pos] + 1 < dp[new_pos1])//比现有值小
            {
                dp[new_pos1] =dp[pos] + 1;
                help(dp, new_pos1, stride);
            }

            //help(dp, new_pos1, stride);
        }
        if (new_pos2<dp.size())//以新方式走到new_pos2
        {
            if (dp[pos] + 2 < dp[new_pos2])
            {
                dp[new_pos2] = dp[pos] + 2;
                help(dp, new_pos2, pos);
            }

            //help(dp, new_pos2, pos);
        }	
    }
};
