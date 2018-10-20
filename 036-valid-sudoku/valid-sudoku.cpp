// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//
//
// 	Each row must contain the digits 1-9 without repetition.
// 	Each column must contain the digits 1-9 without repetition.
// 	Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//
//
//
// A partially filled sudoku which is valid.
//
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
// Example 1:
//
//
// Input:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: true
//
//
// Example 2:
//
//
// Input:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being 
//     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//
//
// Note:
//
//
// 	A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// 	Only the filled cells need to be validated according to the mentioned rules.
// 	The given board contain only digits 1-9 and the character '.'.
// 	The given board size is always 9x9.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这个题只需要检查有效数度，不要求解，所以我们只在这里做一部分
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        //这个标识非常有用，因为之后我们还要用它来解数独
        vector<vector<bool> > rowFlag(m, vector<bool>(n, false));//ffffffff以8个bit代表每个数字在m行有没有出现，默认是没有
        vector<vector<bool> > colFlag(m, vector<bool>(n, false));//ffffffff
        vector<vector<bool> > cellFlag(m, vector<bool>(n, false));//
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] >= '1' && board[i][j] <= '9') 
                {
                    int c = board[i][j] - '1';
                    if (rowFlag[i][c] || colFlag[j][c] || cellFlag[3 * (i / 3) + j / 3][c]) return false;//如果已行/列/小格出现，无效
                    rowFlag[i][c] = true;
                    colFlag[j][c] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
        
    }
    
    pair<int,int> getNextblank(vector<vector<char>>& board,pair<int,int> pos,char c)
    {
        
        for(int i=pos.first;i!=board.size();++i)
            for(int j=0;j!=board[0].size();++j)
            {
                if(board[i][j]==c&&(i*board[0].size()+j>pos.first*board[0].size()+pos.second))
                    return {i,j};
            }
        return {};
        
    }
    //返回可插入的字符列表
    vector<bool> getValidChar(vector<vector<char>>& board,pair<int,int> pos,vector<vector<bool> > rowFlag,vector<vector<bool> > colFlag,
                             vector<vector<bool> > cellFlag)
    {
        int m = board.size(), n = board[0].size();
        int row=pos.first; int col=pos.second;
        auto chars1=rowFlag[row];
        auto chars2=colFlag[col];
        auto chars3=cellFlag[3 * (row/ 3) + col / 3];
        vector<bool> result(chars1.size(),false);
        for(int i=0;i!=chars1.size();++i)
        {
            if(!chars1[i]&&!chars2[i]&&!chars3[i])
                result[i]=true;  
            else
                result[i]=false;
        }
        return result;        
    }
   
};
