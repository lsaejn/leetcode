// Let's play the minesweeper game (Wikipedia, online game)! 
//
// You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.
//
// Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules: 
//
//
//
// If a mine ('M') is revealed, then the game is over - change it to 'X'.
// If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
// If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
// Return the board when no more squares will be revealed.
//
//
//
// Example 1:
//
// Input: 
//
// [['E', 'E', 'E', 'E', 'E'],
//  ['E', 'E', 'M', 'E', 'E'],
//  ['E', 'E', 'E', 'E', 'E'],
//  ['E', 'E', 'E', 'E', 'E']]
//
// Click : [3,0]
//
// Output: 
//
// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'M', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]
//
// Explanation:
//
//
//
//
// Example 2:
//
// Input: 
//
// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'M', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]
//
// Click : [1,2]
//
// Output: 
//
// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'X', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]
//
// Explanation:
//
//
//
//
//
//
// Note:
//
// The range of the input matrix's height and width is [1,50].
// The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
// The input board won't be a stage when game is over (some mines have been revealed).
// For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<pair<int,int>> direct={{-1,-1},{-1,0,},{-1,1},{0,-1},{0,0,},{0,1},{1,-1},{1,0,},{1,1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        if (board.empty() || board[0].empty()) return {};       
        int m = board.size(), n = board[0].size();
        int row = click[0], col = click[1], cnt = 0;
        if (board[row][col] == 'M')
            board[row][col] = 'X';
        else 
        {
                for(auto &elem:direct)
                {
                    int x = row + elem.first, y = col + elem.second;
                    if (x < 0 || x >= m || y < 0 || y >= n) 
                        continue;
                    if (board[x][y] == 'M') ++cnt;
                }

            if (cnt > 0)
                board[row][col] = cnt + '0';
            else 
            {
                board[row][col] = 'B';
                for(auto &elem:direct)
                {
                    int x = row + elem.first, y = col + elem.second;
                    if (x < 0 || x >= m || y < 0 || y >= n) 
                        continue;
                    if (board[x][y] == 'E') 
                    {
                            vector<int> nextPos{x, y};
                            updateBoard(board, nextPos);
                    }
                    
                }
            }
        }
        return board; 
    }
};
