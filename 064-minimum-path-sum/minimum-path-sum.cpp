// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
//
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //典型的最短路径算法，1->1 1->3 1->3->1->1->1
        //问题在于这是道简单算法题，而我们用图算法来解，这样好吗？
        //我们用动态规划来做
        //dp[i][j]记录走到此点最小的花费
        //我们试一试，
        /*
        dp00=1 dp01=4 dp02=5
        dp10=2 dp11=7 dp12=6 
        dp20=6 dp21=8 dp22=7
        */
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if(i==0&&j==0) dp[i][j]=grid[i][j];
                else if(i==0) dp[i][j]=grid[i][j] + dp[i][j - 1];
                else if(j==0) dp[i][j]=grid[i][j] + dp[i-1][j];
                else    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
        
    }
};
