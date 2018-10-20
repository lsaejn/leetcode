// On a N * N grid, we place some 1 * 1 * 1 cubes.
//
// Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
//
// Return the total surface area of the resulting shapes.
//
//  
//
//
//
//
//
//
//
//
//
//
//
// Example 1:
//
//
// Input: [[2]]
// Output: 10
//
//
//
// Example 2:
//
//
// Input: [[1,2],[3,4]]
// Output: 34
//
//
//
// Example 3:
//
//
// Input: [[1,0],[0,2]]
// Output: 16
//
//
//
// Example 4:
//
//
// Input: [[1,1,1],[1,0,1],[1,1,1]]
// Output: 32
//
//
//
// Example 5:
//
//
// Input: [[2,2,2],[2,1,2],[2,2,2]]
// Output: 46
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 50
// 	0 <= grid[i][j] <= 50
//
//
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //找重合面，每个格子只找自己左边和上边的，然后我们从上到下，从左到右扫描即可
    int surfaceArea(vector<vector<int>>& grid) {
        int result=0;
        int n=grid.size();
        for(int i=0;i!=n;++i)
        {
            for(int j=0;j!=n;++j)
            {
                if (grid[i][j])
                    result += grid[i][j] * 4 + 2;
                if (i) 
                    result-= min(grid[i][j], grid[i-1][j]) * 2;
                if (j) 
                    result-= min(grid[i][j], grid[i][j-1]) * 2 ;
            }
        }
        return result;
    }
};
