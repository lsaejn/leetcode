// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//
// Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
//
//  
//
// Example 1:
//
//
// Input: [[4,3,8,4],
//         [9,5,1,9],
//         [2,7,6,2]]
// Output: 1
// Explanation: 
// The following subgrid is a 3 x 3 magic square:
// 438
// 951
// 276
//
// while this one is not:
// 384
// 519
// 762
//
// In total, there is only one magic square inside the given grid.
//
//
// Note:
//
//
// 	1 <= grid.length <= 10
// 	1 <= grid[0].length <= 10
// 	0 <= grid[i][j] <= 15
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool check(vector<vector<int>>& a, int u, int v) {
        //cout << u << " " << v << endl;
        set<int> B;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                B.insert(a[i + u][j + v]);
            }
        }
        if (B.size() != 9 && *B.begin() != 1 || *B.rbegin() != 9) return false;
        set<int> A;
        for (int i = 0; i < 3; ++i) {
            int sum = 0;
            for (int j = 0; j < 3; ++j) {
                sum += a[u + i][v + j];
            }
            A.insert(sum);
        }
        for (int j = 0; j < 3; ++j) {
            int sum = 0;
            for (int i = 0; i < 3; ++i) {
                sum += a[i + u][j + v];
            }
            A.insert(sum);
        }
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum += a[i + u][i + v];
        }
        A.insert(sum);
        sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum += a[u + 2 - i][v + i];
        }
        A.insert(sum);
        return A.size() == 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int ret = 0;
        for (int i = 0; i + 3 <= n; ++i) {
            for (int j = 0; j + 3 <= m; ++j) {
                if (check(a, i, j)) ++ret;
            }
        }
        return ret;
    }
};
