// Given an m * n matrix M initialized with all 0's and several update operations.
// Operations are represented by a 2D array, and each operation is represented by an array with two positive integers a and b, which means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b. 
// You need to count and return the number of maximum integers in the matrix after performing all the operations.
//
// Example 1:
//
// Input: 
// m = 3, n = 3
// operations = [[2,2],[3,3]]
// Output: 4
// Explanation: 
// Initially, M = 
// [[0, 0, 0],
//  [0, 0, 0],
//  [0, 0, 0]]
//
// After performing [2,2], M = 
// [[1, 1, 0],
//  [1, 1, 0],
//  [0, 0, 0]]
//
// After performing [3,3], M = 
// [[2, 2, 1],
//  [2, 2, 1],
//  [1, 1, 1]]
//
// So the maximum integer in M is 2, and there are four of it in M. So return 4.
//
//
//
// Note:
//
// The range of m and n is [1,40000].
// The range of a is [1,m], and the range of b is [1,n].
// The range of operations size won't exceed 10,000.
//
//


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        //你可以写出矩阵。也可以用一行数组代表结果矩阵。
        //关键是怎么把操作数转换成下标
        //m*n [0],[1]....[m*n-1]
        //2*2 -> for(i in range 2)for(j in range 2) pos=i*m+j->0,1,3,4
        //3*3.......................................pos=0,1,2,3,4,5
        //
        //大操作数无效，比方说执行依次[2,2]，以后的任何大于[2,2]的操作都无法弥补回来，所以我们只要记录受影响的范围
        //用轰炸机来形容这个题最合适不过
        for (auto op : ops) {
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};
