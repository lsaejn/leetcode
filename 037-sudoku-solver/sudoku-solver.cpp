// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
//
// 	Each of the digits 1-9 must occur exactly once in each row.
// 	Each of the digits 1-9 must occur exactly once in each column.
// 	Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//
//
// Empty cells are indicated by the character '.'.
//
//
// A sudoku puzzle...
//
//
// ...and its solution numbers marked in red.
//
// Note:
//
//
// 	The given board contain only digits 1-9 and the character '.'.
// 	You may assume that the given Sudoku puzzle will have a single unique solution.
// 	The given board size is always 9x9.
//
//


class Solution{
public:
	using boolVec = vector<vector<bool>>;
	void solveSudoku(vector<vector<char>>& board)
	{
		int m = board.size(), n = board[0].size();
		vector<vector<bool> > rowFlag(m, vector<bool>(n, false));//ffffffff以8个bit代表每个数字在m行有没有出现，默认是没有
		vector<vector<bool> > colFlag(m, vector<bool>(n, false));//ffffffff
		vector<vector<bool> > cellFlag(m, vector<bool>(n, false));//
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] >= '1' && board[i][j] <= '9')
				{
					int c = board[i][j] - '1';//为什么要减一呢？因为我们用索引0-8保存数字1-9标识
					rowFlag[i][c] = true;
					colFlag[j][c] = true;
					cellFlag[3 * (i / 3) + j / 3][c] = true;
				}
			}
		}
		solveSudoku(board, { 0,0 }, rowFlag, colFlag, cellFlag);
		int i = 3;
	}

	bool solveSudoku(vector<vector<char>>& board, pair<int, int> pos, boolVec& rowFlag, boolVec& colFlag, boolVec& cellFlag)
	{
		if (pos.first == -1) return true;

		auto blank = getNextblank(board, pos, '.');
		if (blank.first == -1) return true;
		auto to_insert = getValidChar(board, blank, rowFlag, colFlag, cellFlag);
		if (to_insert.empty()) return false;
		for (int i = 0; i != to_insert.size(); ++i)
		{
			if (to_insert[i] == false) continue;
			board[blank.first][blank.second] =i+1+'0' ;
			rowFlag[blank.first][i] = true;
			colFlag[blank.second][i] = true;
			cellFlag[3 * (blank.first / 3) + blank.second / 3][i] = true;
			if (solveSudoku(board, blank, rowFlag, colFlag, cellFlag))
			{
				cout << "succefss" << endl;
				return true;
			}
			board[blank.first][blank.second] = '.';
			rowFlag[blank.first][i] = false;
			colFlag[blank.second][i] = false;
			cellFlag[3 * (blank.first / 3) + blank.second / 3][i] = false;
		}
		return false;
	}

	pair<int, int> getNextblank(vector<vector<char>>& board, pair<int, int> pos, char c)
	{

		for (int i = pos.first; i != board.size(); ++i)
			for (int j = 0; j != board[0].size(); ++j)
				if (board[i][j] == c)
					return { i,j };
		return { -1,-1 };

	}
	//返回可插入的字符列表
	//using boolVec = vector<vector<bool>>;
	vector<bool> getValidChar(vector<vector<char>>& board, pair<int, int> pos, boolVec& rowFlag, boolVec& colFlag, boolVec& cellFlag)
	{
		int m = board.size(), n = board[0].size();
		int row = pos.first; int col = pos.second;
		auto chars1 = rowFlag[row];
		auto chars2 = colFlag[col];
		auto chars3 = cellFlag[3 * (row / 3) + col / 3];
		vector<bool> result(chars1.size(), false);
		for (int i = 0; i != chars1.size(); ++i)
		{
			if (!chars1[i] && !chars2[i] && !chars3[i])
				result[i] = true;
			else
				result[i] = false;
		}
		return result;
	}
};
