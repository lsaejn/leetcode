// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //明显的基于深度的递归
    //看了一下网上的答案，居然惊人一致，可见这种问题没有什么更好的方法
    bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0) return false;
		int rows = board.size();
		int cols = board[0].size();
		vector<vector<bool>> mark(rows, vector<bool>(cols, false));
		for (int i = 0; i != rows; ++i)
			for (int j = 0; j != cols; ++j)
				if (getWords(board, rows, cols, word, i, j,0, mark))
					return true;
		return false;
        
    }
    
    //为了避免循环，我们恐怕还要用一个数组记录是否曾经遍历
    bool getWords(vector<vector<char>>& board,int rows,int cols, string& word,int x,int y,int pos,vector<vector<bool>>& mark)
    {
        if(pos==word.size()) return true;
        if(x==rows||x==-1||y==cols||y==-1) return false;//坐标无效
        if(board[x][y]!=word[pos]||mark[x][y]==true) return false;
        int left_x=x-1;
        mark[x][y]=true;
        if(getWords(board,rows,cols,word,left_x,y,pos+1,mark)) return true;
        int right_x=x+1;
        if(getWords(board,rows,cols,word,right_x,y,pos+1,mark)) return true;
        int top_y=y-1;
        if(getWords(board,rows,cols,word,x,top_y,pos+1,mark)) return true;
        int bot_y=y+1;
        if(getWords(board,rows,cols,word,x,bot_y,pos+1,mark)) return true;
        mark[x][y]=false;
        return false;
    }
};
