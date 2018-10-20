// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//
// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
//
// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
//
// Note:
//
// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.
//
//
// Example:
//
// Given the following 5x5 matrix:
//
//   Pacific ~   ~   ~   ~   ~ 
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic
//
// Return:
//
// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
//
//


class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        vector<vector<int>> rearchP(matrix.size(), vector<int>(matrix[0].size(), 0));//初始为0
        vector<vector<int>> rearchA(matrix.size(), vector<int>(matrix[0].size(), 0));

        //两个循环从四个边开始往内部推理
        for (int i = 0; i < matrix.size(); ++i) 
        {
            dfs(matrix, i, 0, rearchP);
            dfs(matrix, i, matrix[0].size() - 1, rearchA);
        }

        for (int i = 0; i < matrix[0].size(); ++i) {
            dfs(matrix, 0, i, rearchP);
            dfs(matrix, matrix.size() - 1, i, rearchA);
        }

        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                if (rearchA[i][j] && rearchP[i][j])
                    res.push_back({i, j});

        return res;
    }

    void dfs(const vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &reach) {
        if (reach[r][c] == 1)
            return;
        reach[r][c] = 1;

        for (auto d : direction) {
            int newR = r + d.first, newC = c + d.second;
            if (newR < 0 || newR >= matrix.size() || newC < 0 || newC >= matrix[0].size() ||
                    matrix[r][c] > matrix[newR][newC])//目标格子不可以流倒当前格子
                continue;
            dfs(matrix, r + d.first, c + d.second, reach);
        }
    }

private:
    vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
