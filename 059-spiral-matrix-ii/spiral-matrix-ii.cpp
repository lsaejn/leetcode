// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
// Example:
//
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        if(n==0) return {};
        vector<vector<int>> matrix(n,vector<int>(n));
        spiralOrder(matrix,0,0,matrix.size(),matrix[0].size(),1);//不错，我们嚣张到名字都不改
        return matrix;
        
    }
    
    
    void spiralOrder(vector<vector<int>>& matrix,int x,int y,int n,int m,int num) //从长宽为n的矩阵的x,y坐标开始放置长宽为m的部分
    {
		if (m<=0 || n<=0) return;
        if (m == 1 || n == 1)
		{
			for (int i = 0; i != m; ++i)
				for (int j = 0; j != n; ++j)
					matrix[x + i][y + j]=num++;
			return;
		}
		for (int i = 0; i<n; ++i)
			matrix[x + 0][y + i]=num++;
		for (int i = 1; i<m - 1; ++i)
			matrix[x + i][y + n - 1]=num++;
		for (int i = n - 1; i >= 0; --i)
			matrix[x + m - 1][y + i]=num++;
		for (int i = m - 2; i > 0; --i)
			matrix[x + i][y + 0]=num++;
		m -= 2;
		n -= 2;
		spiralOrder(matrix,x + 1, y + 1, m, n,num);
    }
};
