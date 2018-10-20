// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
// Example:
//
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]
//
// Answer: 16
// Explanation: The perimeter is the 16 yellow stripes in the image below:
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        for(int row=0;row!=grid.size();++row)
            for(int col=0;col!=grid[row].size();++col)
            {
                if(grid[row][col]==0) continue;//此grid为0
                if(col-1<0||(col-1>=0&&grid[row][col-1]==0)) count++;
                if(col+1==grid[row].size()||(col+1<grid[row].size()&&grid[row][col+1]==0)) 
                    count++;
                if(row+1==grid.size()||(row+1<grid.size()&&grid[row+1][col]==0))                           count++;
                if(row-1<0||(row-1>=0&&grid[row-1][col]==0)) count++;
                //cout<<row<<" "<<col<<" "<<count<<endl;
            }
        return count;
    }
};
