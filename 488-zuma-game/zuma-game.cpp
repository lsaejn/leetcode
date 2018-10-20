// Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.
//
// Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.
//
// Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls, output -1.
//
//
// Examples:
// Input: "WRRBBW", "RB"
// Output: -1
// Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
//
// Input: "WWRRBBWW", "WRBRW"
// Output: 2
// Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty
//
// Input:"G", "GGGGG"
// Output: 2
// Explanation: G -> G[G] -> GG[G] -> empty 
//
// Input: "RBYYBBRRB", "YRBGB"
// Output: 3
// Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 
//
//
//
// Note:
//
// You may assume that the initial row of balls on the table won’t have any 3 or more consecutive balls with the same color.
// The number of balls on the table won't exceed 20, and the string represents these balls is called "board" in the input.
// The number of balls in your hand won't exceed 5, and the string represents these balls is called "hand" in the input.
// Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int findMinStep(string board, string hand)
    {
        int res = INT_MAX;
        unordered_map<char, int> m;
        for (char c : hand) ++m[c];//手里的球
        res = helper(board, m);
        return res == INT_MAX ? -1 : res;
    }
    int helper(string board, unordered_map<char, int>& m) 
    {
        board = removeConsecutive(board);
        if (board.empty()) return 0;
        int cnt = INT_MAX, j = 0;
        for (int i = 0; i <= board.size(); ++i) {
            if (i < board.size() && board[i] == board[j]) continue;
            int need = 3 - (i - j);
            if (m[board[j]] >= need) {
                m[board[j]] -= need;
                int t = helper(board.substr(0, j) + board.substr(i), m);
                if (t != INT_MAX) cnt = min(cnt, t + need);
                m[board[j]] += need;
            }
            j = i;
        }
        return cnt;
    }
    string removeConsecutive(string board) 
    {
        for (int i = 0, j = 0; i <= board.size(); ++i) {
            if (i < board.size() && board[i] == board[j]) continue;
            if (i - j >= 3) return removeConsecutive(board.substr(0, j) + board.substr(i));
            else j = i;
        }
        return board;
    }
};
