// Given a matrix A, return the transpose of A.
//
// The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
//
//  
//
//
// Example 1:
//
//
// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]
//
//
//
// Example 2:
//
//
// Input: [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 1000
// 	1 <= A[0].length <= 1000
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int xsize=A.size();
        int ysize=A[0].size();
        vector<vector<int>> result;
        vector<int> tmp;
        for(int i=0;i<ysize;i++)
        {            
            for(int j=0;j<xsize;j++)
                tmp.push_back(A[j][i]);
            result.push_back(tmp);
            tmp.clear();
        }
        return result;
    }
};
