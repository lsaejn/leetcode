//
// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image. 
//
//
// Example:
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output:  [1,2,4,7,5,3,6,8,9]
// Explanation:
//
//
//
//
// Note:
//
// The total number of elements of the given matrix will not exceed 10,000.
//
//


class Solution {
public:
    //这种体力活我已经不想做了。
    //我们从0,0开始，记录方向，向上，探测越界，右行，
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) 
            return {};
        int m = matrix.size(), n = matrix[0].size(), r = 0, c = 0, k = 0;
        vector<int> res(m * n);
        vector<vector<int>> dirs{{-1,1}, {1,-1}};//方向控制
        for (int i = 0; i < m * n; ++i) 
        {
            res[i] = matrix[r][c];
            r += dirs[k][0];
            c += dirs[k][1];
            if (r >= m) {r = m - 1; c += 2; k = 1 - k;}//边界要回走两格
            if (c >= n) {c = n - 1; r += 2; k = 1 - k;}
            if (r < 0) {r = 0; k = 1 - k;}
            if (c < 0) {c = 0; k = 1 - k;}
        }
        return res;
    }
};
