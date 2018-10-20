// We have a two dimensional matrix A where each value is 0 or 1.
//
// A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.
//
// After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
//
// Return the highest possible score.
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
// Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation:
// Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 20
// 	1 <= A[0].length <= 20
// 	A[i][j] is 0 or 1.
//
//


class Solution {
public:
    //将第一列元素全部按行翻转成1之后，
    int matrixScore(vector<vector<int>>& A)
    {
        int n = A.size(), m = A[0].size();
        for(int i=0;i<n;i++)
            if(A[i][0] == 0)
                for(int j=0;j<m;j++) 
                    A[i][j] = 1 - A[i][j];
        
        int ans = 0;
        for(int j=0;j<m;j++)
        {
            int p = m - j - 1;
            int ocnt = 0, zcnt = 0;//统计1和0的个数，决定是否翻转
            for(int i=0;i<n;i++)
                if(A[i][j] == 1) ocnt++;
                else zcnt++;
            ans += max(ocnt, zcnt) * (1 << p);
        }
        return ans;
    }
};
