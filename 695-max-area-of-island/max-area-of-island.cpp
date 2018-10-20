// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)  You may assume all four edges of the grid are surrounded by water.
//
// Find the maximum area of an island in the given 2D array.
// (If there is no island, the maximum area is 0.)
//
// Example 1:
//
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//
// Given the above grid, return 6.
//
// Note the answer is not 11, because the island must be connected 4-directionally.
//
//
// Example 2:
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
//
//
// Note:
// The length of each dimension in the given grid does not exceed 50.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这是之前图像处理里求联通区域的翻版。
    //这一次，我要用更简洁的算法求出答案。显然我们应该遍历所有元素，为了更有效率，我们应该
    //记录本格节点是不是被访问到。-1
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;//结果
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] != 1) continue;
                int re = 0;//本节点所在区域的最大面积
                maxAreaOfIsland(grid, i, j, count,m,n,re);
            }
        return count;
    }

    using Vec=vector<vector<int>>;
    void maxAreaOfIsland(Vec& grid,int i,int j,int& cnt,int m,int n,int& result)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
        result++;//本节点为1，结果++
        grid[i][j]=-1;//避免循环访问

        maxAreaOfIsland(grid, i + 1, j , cnt,m,n, result);
        maxAreaOfIsland(grid, i - 1, j , cnt,m,n, result);
        maxAreaOfIsland(grid, i , j - 1, cnt,m,n, result);
        maxAreaOfIsland(grid, i , j + 1, cnt,m,n, result); 
        if(result>cnt)//更新最大值
            cnt=result;
    }
};
