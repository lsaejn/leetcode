// An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are given.
//
// The ith edge connects nodes edges[i][0] and edges[i][1] together.
//
// Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.
//
// Example 1:
//
//
// Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation: 
// Here is a diagram of the given tree:
//   0
//  / \
// 1   2
//    /|\
//   3 4 5
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
//
//
// Note: 1 <= N <= 10000
//


class Solution {
public:
    //BFS超时了，这是显然的。
    //那么知道1和0的距离，并不会让0到2，3，4的距离变得马上有用。我们还得知道1是不是3，4，5的祖先
    //这是社区解决方案，难度还是很大的。我是这么理解的。假设对于root结点全部提供一次长度,那么子节点还要给子父亲提供一次长度
    //比如例子，子节点数是5，那么3，4，5还要为2提供一次长度，所以是8
    //如果3下面还有6,7,8呢？显然，6,7,8为3提供一次长度，为2提供一次长度，为0提供一次长度，就是9,
    //现在就可以得出规律了，res[root]=res[i]+count[i]
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<unordered_set<int>> tree(N);//i和i相连结点
        vector<int> res(N, 0);//子节点到根的的距离之和
        vector<int> count(N, 0);//子节点个数
        if (N == 1) return res;
        for (auto e : edges)
        {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        unordered_set<int> seen1, seen2;
        dfs(0, seen1, tree, res, count);
        dfs2(0, seen2, tree, res, count, N);
        return res;

    }

    void dfs(int root, unordered_set<int>& seen, vector<unordered_set<int>>& tree, vector<int>& res, vector<int>& count) {
        seen.insert(root);
        for (auto i : tree[root])
            if (seen.count(i) == 0) 
            {
                dfs(i, seen, tree, res, count);
                count[root] += count[i];
                res[root] += res[i] + count[i];
            }
        count[root] += 1;
    }
//https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C++JavaPython-Pre-order-and-Post-order-DFS-O(N)
//When we move our root from parent to its child i, count[i] points get 1 closer to root, n - count[i] nodes get 1 futhur to root.
    void dfs2(int root, unordered_set<int>& seen, vector<unordered_set<int>>& tree, vector<int>& res, vector<int>& count, int N) {
        seen.insert(root);
        for (auto i : tree[root])
            if (seen.count(i) == 0) {
                res[i] = res[root] - count[i] + N - count[i];
                dfs2(i, seen, tree, res, count, N);
            };
    }
};
