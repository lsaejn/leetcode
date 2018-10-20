// In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the height of any number of buildings, by any amount (the amounts can be different for different buildings). Height 0 is considered to be a building as well. 
//
// At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right, must be the same as the skyline of the original grid. A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance. See the following example.
//
// What is the maximum total sum that the height of the buildings can be increased?
//
//
// Example:
// Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
// Output: 35
// Explanation: 
// The grid is:
// [ [3, 0, 8, 4], 
//   [2, 4, 5, 7],
//   [9, 2, 6, 3],
//   [0, 3, 1, 0] ]
//
// The skyline viewed from top or bottom is: [9, 4, 8, 7]
// The skyline viewed from left or right is: [8, 7, 9, 3]
//
// The grid after increasing the height of buildings without affecting skylines is:
//
// gridNew = [ [8, 4, 8, 7],
//             [7, 4, 7, 7],
//             [9, 4, 8, 7],
//             [3, 3, 3, 3] ]
//
//
//
// Notes: 
//
//
// 	1 < grid.length = grid[0].length <= 50.
// 	All heights grid[i][j] are in the range [0, 100].
// 	All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        //每行每列的最小值，对于ij，取其中较小值即可
		vector<int> row;
		vector<int> col;
		for (int i = 0; i != grid.size(); ++i)
		{
			int max = INT32_MIN;
			for (int j = 0; j != grid[i].size(); ++j)
				max = max>grid[i][j] ? max : grid[i][j];
			row.push_back(max);
		}
		for (int i = 0; i != grid[0].size(); ++i)
		{
			int max = INT32_MIN;
			for (int j = 0; j != grid.size(); ++j)
				max = max>grid[j][i] ? max : grid[j][i];
			col.push_back(max);
		}
		int sum = 0;
		for (int i = 0; i != grid.size(); ++i)
			for (int j = 0; j != grid[i].size(); ++j)
			{
				sum += min(row[i], col[j]) - grid[i][j];
			}
		return sum;
    }
};
