// Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
//
//
// You receive a valid board, made of only battleships or empty slots.
// Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
// At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
//
//
// Example:
// X..X
// ...X
// ...X
//
// In the above board there are 2 battleships.
//
// Invalid Example:
// ...X
// XXXX
// ...X
//
// This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
//
// Follow up:Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?


class Solution {
public:
    //递归扫描并打标签即可。
    //但是题目要求居然是O(1)?所以dfs似乎不行
    //但是居然有下面的思路，就是找起点，既然舰船不相连，那么我们把最左和最上放的x认为是舰船头部
    //要求，该点是x,且上和左为.
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) 
            return 0;
        int res = 0, m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) 
            {
                if (board[i][j] == '.' || (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) continue;
                ++res;
            }
        }
        return res;
    }
};
