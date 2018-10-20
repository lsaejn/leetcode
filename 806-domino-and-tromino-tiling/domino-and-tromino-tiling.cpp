// We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.
//
//
// XX  <- domino
//
// XX  <- "L" tromino
// X
//
//
// Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.
//
// (In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)
//
//
//
// Example:
// Input: 3
// Output: 5
// Explanation: 
// The five different ways are listed below, different letters indicates different tiles:
// XYZ XXZ XYY XXY XYY
// XYZ YYZ XZZ XYY XXY
//
// Note:
//
//
// 	N  will be in range [1, 1000].
//
//
//  " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
private: static const int MOD = 1000000007;
 public:   
int numTilings(int N) {
    int p3 = -1, p2 = 0, p1 = 1;
        
    for (int n = 1; n <= N; n++) 
    {
        int cur = (int)((p1 * 2L + p3) % MOD);
        p3 = p2;
        p2 = p1;
        p1 = cur;
    }
        
    return p1;
}
};
