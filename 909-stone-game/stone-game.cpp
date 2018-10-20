// Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
//
// The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.
//
// Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.
//
// Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
//
//  
//
// Example 1:
//
//
// Input: [5,3,4,5]
// Output: true
// Explanation: 
// Alex starts first, and can only take the first 5 or the last 5.
// Say he takes the first 5, so that the row becomes [3, 4, 5].
// If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
// If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
//
//
//  
//
// Note:
//
//
// 	2 <= piles.length <= 500
// 	piles.length is even.
// 	1 <= piles[i] <= 500
// 	sum(piles) is odd.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;//这种游戏，先手必胜
    }
};