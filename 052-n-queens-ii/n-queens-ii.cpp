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
//


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
