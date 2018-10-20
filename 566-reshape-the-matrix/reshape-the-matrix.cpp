// In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
//
//
//
// You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
//
//  The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
//
//
//
// If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
//
//
// Example 1:
//
// Input: 
// nums = 
// [[1,2],
//  [3,4]]
// r = 1, c = 4
// Output: 
// [[1,2,3,4]]
// Explanation:The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
//
//
//
// Example 2:
//
// Input: 
// nums = 
// [[1,2],
//  [3,4]]
// r = 2, c = 4
// Output: 
// [[1,2],
//  [3,4]]
// Explanation:There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
//
//
//
// Note:
//
// The height and width of the given matrix is in range [1, 100].
// The given r and c are all positive.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //虽然用过python，但我也没弄明白，为甚么1*4就可以转换成2*2
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int old_r=nums.size();
        int old_c=nums[0].size();
        vector<vector<int>> result(r);
        if(old_r*old_c!=r*c) return nums;
       
        else
        {
            int i=0;
            int j=0;
            for(auto row:nums)
                for(auto num:row)
                {
                    //res[i / c][i % c] = nums[i / n][i % n];
                    result[i].push_back(num);
                    j++;
                    if(j==c)
                    {
                        j=0;
                        ++i;
                    }
                }
        }        
        return result;
    }
};
