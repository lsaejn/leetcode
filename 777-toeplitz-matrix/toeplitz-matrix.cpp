// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
//
// Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
//  
//
// Example 1:
//
//
// Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
// Output: True
// Explanation:
// 1234
// 5123
// 9512
//
// In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
//
//
// Example 2:
//
//
// Input: matrix = [[1,2],[2,2]]
// Output: False
// Explanation:
// The diagonal "[1, 2]" has different elements.
//
//
// Note:
//
//
// 	matrix will be a 2D array of integers.
// 	matrix will have a number of rows and columns in range [1, 20].
// 	matrix[i][j] will be integers in range [0, 99].
//
//
//  " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
         int m = matrix.size() ;
         int n = matrix[0].size() ;
         for(int i = 0 ; i < m-1 ; i++)
             for(int j = 0 ; j < n-1 ; j++)
             {
                 if (matrix[i][j] != matrix[i+1][j+1])
                     return false ;
             }
         
         return true ;
    }
};
