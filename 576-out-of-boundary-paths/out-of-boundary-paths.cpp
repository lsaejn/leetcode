// There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
//
// Example 1:
//
// Input:m = 2, n = 2, N = 2, i = 0, j = 0
// Output: 6
// Explanation:
//
//
//
//
// Example 2:
//
// Input:m = 1, n = 3, N = 3, i = 0, j = 1
// Output: 12
// Explanation:
//
//
//
//
// Note:
//
// Once you move the ball out of boundary, you cannot move it back.
// The length and height of the grid is in range [1,50].
// N is in range [0,50].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //DFS可能会越界
    //1步走出去的是边缘，<2步走出去的是边缘加上它旁边的格子,<3步的走出去的是之前的格子加上之前格子的旁边的格子
    //The number of paths for N moves is the sum of paths for N - 1 moves from the adjacent cells. If an adjacent cell is out of the border, the number of paths is 1.
    //假设当前格子最多N次可以出去，那么它周边的格子只需要N-1步就能走出。如果周边的格子在边缘外部，那么就只要1步就能走出去
    //明白了吗？以1*3那个为例，
    /*一步走出去有2种，3-2-3，怎么计算呢？向四周走一步，越界即加，1。
      两步走出去，因为在上下两个方向一步就走出去了，所以只有2种，要加上周边两个格子1步走出去的数量2+3+3=8.5-8-5
      3步走出去，要加上周边两个格子2步走出去的数量2+5+5. 11 12 11
      OK，公式出来dp[n][x][y]=dp[n-1][x-1][y]+dp[n-1][x+1][y]+dp[n-1][x][y+1]+dp[n-1][x][y+1],注意如果格子越界的情况
      越界就是初始值，是这么思考的，我们更新dp[n][x][y]如果出现mi-1<0，那么令其值为1，，就像第一步求的那样
    */
int findPaths(int m, int n, int N, int i, int j)
{
  uint dp[51][50][50] = {};
    //dp是第dp[Ni][mi][ni]是坐标mi,ni在第Ni步能走出去的路径数量
  for (auto Ni = 1; Ni <= N; ++Ni)
    for (auto mi = 0; mi < m; ++mi)
      for (auto ni = 0; ni < n; ++ni)
        dp[Ni][mi][ni] = ((mi == 0 ? 1 : dp[Ni - 1][mi - 1][ni]) + (mi == m - 1? 1 : dp[Ni - 1][mi + 1][ni])
            + (ni == 0 ? 1 : dp[Ni - 1][mi][ni - 1]) + (ni == n - 1 ? 1 : dp[Ni - 1][mi][ni + 1]))% 1000000007;
  return dp[N][i][j];
}
};
