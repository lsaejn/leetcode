// On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).
//
// Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.
//
// You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?
//
// Example 1:
//
//
// Input: [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
//
// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.
//
//
// Example 2:
//
//
// Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation:
//  0  1  2  3  4
// 24 23 22 21  5
// 12 13 14 15 16
// 11 17 18 19 20
// 10  9  8  7  6
//
// The final route is marked in bold.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
//
//
// Note:
//
//
// 	2 <= N <= 50.
// 	grid[i][j] is a permutation of [0, ..., N*N - 1].
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina



//瞬间移动无限距离，显然，BFS。帮我们解决了
//两个问题，
/*
    我们改一下例子，变成
[0, 1, 2, 3, 4],
[7, 23,22,21,5],
[12,16,18,19,17],
[11,13,14,15,20],
[10,9, 8, 24, 6]
   我们很快到达了5，然后等待16开放，然而在这个过程里，7先开放了。，然后等待12开放
   然后题目又变成了grid[i][j][k].我TMD的烦死这种题了.然后我发现了这个！！！优先队列！！！太神了！太神了！！！一听就明白了，不是吗。。
   不过论难度，这道题比不上多个钥匙匹配的那个。
*/
class Solution {
public:

    struct T {
        int t, x, y;
        T(int a, int b, int c) : t (a), x (b), y (c){}
        bool operator< (const T &d) const {return t > d.t;}
    };

    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size (), res = 0;
        priority_queue<T> pq;
        pq.push(T(grid[0][0], 0, 0));
        vector<vector<int>> seen(N, vector<int>(N, 0));
        seen[0][0] = 1;
        static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

        while (true)
        {
            auto p = pq.top ();
            pq.pop ();
            res = max(res, p.t);
            if (p.x == N - 1 && p.y == N - 1) return res;
            for (auto& d : dir) 
            {
                int i = p.x + d[0], j = p.y + d[1];
                if (i >= 0 && i < N && j >= 0 && j < N && !seen[i][j])
                {
                    seen[i][j] = 1;
                    pq.push (T(grid[i][j], i, j));
                }
            }
        }
        return grid.size()-1;
    }
};
