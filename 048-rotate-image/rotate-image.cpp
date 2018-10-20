// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).
//
// Note:
//
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
//
// Example 1:
//
//
// Given input matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],
//
// rotate the input matrix in-place such that it becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
//
//
// Example 2:
//
//
// Given input matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ], 
//
// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]
//
//


class Solution {
public:
    //我们找到ij的规则
//最后再来看一种方法，这种方法首先对原数组取其转置矩阵，然后把每行的数字翻转可得到结果：
    /*
  [ 5, 2, 13,15],
  [ 1, 4, 3,14],
  [ 9, 8, 6, 12],
  [11,10,7,16]
    
    */
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j) 
                swap(matrix[i][j], matrix[j][i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
