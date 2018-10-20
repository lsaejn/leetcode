//
// In this problem, a tree is an undirected graph that is connected and has no cycles.
//
// The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added.  The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
//
// The resulting graph is given as a 2D-array of edges.  Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.
//
// Return an edge that can be removed so that the resulting graph is a tree of N nodes.  If there are multiple answers, return the answer that occurs last in the given 2D-array.  The answer edge [u, v] should be in the same format, with u < v.
// Example 1:
//
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given undirected graph will be like this:
//   1
//  / \
// 2 - 3
//
//
// Example 2:
//
// Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
// Output: [1,4]
// Explanation: The given undirected graph will be like this:
// 5 - 1 - 2
//     |   |
//     4 - 3
//
//
// Note:
// The size of the input 2D-array will be between 3 and 1000.
// Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
//
//
//
//
//
// Update (2017-09-26):
// We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.
//


class Solution {
public:
    /*
    其实这道题最好的解法使用Union Find来做，首先我们建立一个长度为(n+1)的数组root，由于这道题并没有明确的说明n是多少，只是说了输入的二位数组的长度不超过1000，那么n绝对不会超过2000，我们加1的原因是由于结点值是从1开始的，而数组是从0开始的，我们懒得转换了，就多加一位得了。我们将这个数组都初始化为-1，有些人喜欢初始化为i，都可以。开始表示每个结点都是一个单独的组，所谓的Union Find就是要让结点之间建立关联，比如若root[1] = 2，就表示结点1和结点2是相连的，root[2] = 3表示结点2和结点3是相连的，如果我们此时新加一条边[1, 3]的话，我们通过root[1]得到2，再通过root[2]得到3，说明结点1有另一条路径能到结点3，这样就说明环是存在的；如果没有这条路径，那么我们要将结点1和结点3关联起来，让root[1] = 3即可
    */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(2001, -1);
        for (auto edge : edges) {
            int x = find(root, edge[0]), y = find(root, edge[1]);
            if (x == y) return edge;
            root[x] = y;
        }
        return {};
    }
    int find(vector<int>& root, int i) {
        while (root[i] != -1) {
            i = root[i];
        }
        return i;
    }
};
