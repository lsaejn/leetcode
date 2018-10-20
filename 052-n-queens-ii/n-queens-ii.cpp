// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.
//
// Example:
//
//
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int totalNQueens(int n) 
    {
        return queen(0,0,0,0,0,n);       
    }
    //l,r,d是左右竖线的控制范围
    int queen(int answer, int deep, int l, int d,int r,int n) //这个answer用法不是我常用的。传入再传出。不雅。
    {
        if (deep == n)  return answer + 1;//deep当前深度==皇后数，超出棋盘            
        for (int i = 0; i < n; ++i)//再当前deep依次放入皇后
        {           
            if (((1 << i) & l) || ((1 << i)&d) || ((1 << i)&r)) continue;
            answer = queen(answer,deep+1,(l<<1)|(1<<(i + 1)), d|(1<<i),(r>>1)|(1 <<( i - 1)),n);	
        }
        return answer;
    }
};
