// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
// Example:
//
//
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
//


class Solution {
public:
    //只是问数量，并没有让求出来哦！
    //这个让你推导卡兰塔数列
    //http://www.cnblogs.com/grandyang/p/4299608.html
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) 
            for (int j = 0; j < i; ++j)
                dp[i] += dp[j] * dp[i - j - 1];
        
        return dp[n]; 
    }
};
