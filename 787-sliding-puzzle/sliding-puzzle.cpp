// On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.
//
// A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
//
// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//
// Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
//
// Examples:
//
//
// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.
//
//
//
// Input: board = [[1,2,3],[5,4,0]]
// Output: -1
// Explanation: No number of moves will make the board solved.
//
//
//
// Input: board = [[4,1,2],[5,0,3]]
// Output: 5
// Explanation: 5 is the smallest number of moves that solves the board.
// An example path:
// After move 0: [[4,1,2],[5,0,3]]
// After move 1: [[4,1,2],[0,5,3]]
// After move 2: [[0,1,2],[4,5,3]]
// After move 3: [[1,0,2],[4,5,3]]
// After move 4: [[1,2,0],[4,5,3]]
// After move 5: [[1,2,3],[4,5,0]]
//
//
//
// Input: board = [[3,2,4],[1,5,0]]
// Output: 14
//
//
// Note:
//
//
// 	board will be a 2 x 3 array as described above.
// 	board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //bfs就是暴力解法，
    int slidingPuzzle(vector<vector<int>>& board) {
        string des = "123450";
        string init;
        for(int i = 0;i<board.size();++i)
            for(int j = 0;j<board[0].size();++j) 
                init+=to_string(board[i][j]);
            
        if(init == des) return 0;
        
        queue<string> q;//
        vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        unordered_set<string> mSet;
        mSet.insert(init);//已经演算的棋盘/下一轮需要演算的棋盘
        q.push(init);
        int moves = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0;i<size;++i) {
                auto t = q.front();
                q.pop();
                int pos = t.find('0');

                int rpx = pos/3;
                int rpy = pos%3;
                // 3 dir
                for(auto&v:dir) {
                    int x = rpx+v.first;
                    int y = rpy+v.second;

                    if(x>=0&&x<2&&y>=0&&y<3) {
                        auto r = x*3+y;
                        string n = t;
                        swap(n[pos],n[r]);
                        if(n==des) return ++moves;
                        if(mSet.find(n)==mSet.end()) {//我们避免掉已经演算过的棋盘

                            mSet.insert(n);
                            q.push(n);
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
