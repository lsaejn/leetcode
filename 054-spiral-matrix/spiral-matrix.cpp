// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    /*
    1234
    5678
    9876
    5432    
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //似乎没有规律，对于一个矩阵，记录它的起点,0,0,构成一个m*n,先输出第一行，再输出最后一列的n-2个，再输出最后一行，再输出第一列的n-2个
        //然后修改起点为1,1,m,n为m-2,n-2
        if(matrix.size()==0) return {};
        vector<int> result;
        spiralOrder(matrix,result,0,0,matrix.size(),matrix[0].size());
        return result;
    }
    
    void spiralOrder(vector<vector<int>>& matrix,vector<int>& result,int x,int y,int m,int n) 
    {
		if (m<=0 || n<=0) return;
        if (m == 1 || n == 1)
		{
			for (int i = 0; i != m; ++i)
				for (int j = 0; j != n; ++j)
					result.push_back(matrix[x + i][y + j]);
			return;
		}
		for (int i = 0; i<n; ++i)
			result.push_back(matrix[x + 0][y + i]);
		for (int i = 1; i<m - 1; ++i)
			result.push_back(matrix[x + i][y + n - 1]);
		for (int i = n - 1; i >= 0; --i)
			result.push_back(matrix[x + m - 1][y + i]);
		for (int i = m - 2; i > 0; --i)
			result.push_back(matrix[x + i][y + 0]);
		m -= 2;
		n -= 2;
		spiralOrder(matrix, result, x + 1, y + 1, m, n);
    }
    
    
    
};   
    
