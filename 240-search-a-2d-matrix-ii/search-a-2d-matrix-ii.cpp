// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted in ascending from left to right.
// 	Integers in each column are sorted in ascending from top to bottom.
//
//
// Example:
//
// Consider the following matrix:
//
//
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
//
//
// Given target = 5, return true.
//
// Given target = 20, return false.
//


class Solution {
public:
    //似乎没有规律可言，比如17，第一行一眼望去，几乎都可以查找所有列
    //但是对于一个n*n的矩阵，它的最大值在最右下，最小值在最左，
    //可惜给我们的不是方阵
    //我们在最后一行找到该列最大值，一直到找到所在的列，
    /*
        [2,   5,  8, 12, 19],
        [3,   6,  9, 16, 22],
        [10, 13, 14, 17, 24],
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int x = matrix.size() - 1, y = 0;
        while (true) {
            if (matrix[x][y] > target) --x;
            else if (matrix[x][y] < target) ++y;
            else return true;
            if (x < 0 || y >= matrix[0].size()) break;
        }
        return false;
    }
};
