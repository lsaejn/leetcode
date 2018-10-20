// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
// Example 1:
//
//
// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
//
// Example 2:
//
//
// Input: coins = [2], amount = 3
// Output: -1
//
//
// Note:
// You may assume that you have an infinite number of each kind of coin.
//


class Solution {
public:
    //这道题不巧见过，本质是个数学题
    //求解ax+by+cz=11时，x+y+z的最小值
    //显然c<=11/5, b<=5,a<=11.然后我们暴力破解之！
    //但是这里的题目其实有个问题，就是硬币的数量不确定。所以这个方法只是用来优化的手段之一
    /*
    dp[i]表示钱数为i时的最小硬币数的找零，递推式为：
    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    其中coins[j]为第j个硬币，而i - coins[j]为钱数i减去其中一个硬币的值，剩余的钱数在dp数组中找到值，然后加1和当前dp数组中的值做比较，取较小的那个更新dp数组。先来看迭代的写法如下所示
*/
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) 
            for (int j = 0; j < coins.size(); ++j) 
                if (coins[j] <= i) 
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                
            
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
