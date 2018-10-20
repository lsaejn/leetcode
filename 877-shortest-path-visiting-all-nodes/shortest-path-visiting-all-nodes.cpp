// An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.
//
// graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.
//
// Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
//
//  
//
//
//
//
// Example 1:
//
//
// Input: [[1,2,3],[0],[0],[0]]
// Output: 4
// Explanation: One possible path is [1,0,2,0,3]
//
// Example 2:
//
//
// Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
// Output: 4
// Explanation: One possible path is [0,1,4,2,3]
//
//
//  
//
// Note:
//
//
// 	1 <= graph.length <= 12
// 	0 <= graph[i].length < graph.length
//


class Solution {
public:
    //没有任何技巧，就是dfs，但这道题有个难点，就是结点可以重复走
    //纯dfs肯定不行的。原作者的意思是，从当前可选结点里，选择访问次数最少那个。wow，妙极！
    //In each dfs function call, visit all the nodes which has the least visit times.
    int shortestPathLength(vector<vector<int>>& graph) {
        result = INT_MAX;
        vector<int> cur;//当前路径
        vector<int> visited(graph.size(), 0);//每个结点的访问次数
        int count = 0;//访问过的节点数
        for (int i = 0; i < graph.size(); i++) //dfs
        {
            cur.push_back(i);
            visited[i]++;
            count++;
            dfs(graph, cur, visited, count);
            count--;
            visited[i]--;
            cur.pop_back();
        }
        return result - 1;
    }

private:
    int result;
    
    void dfs(vector<vector<int>>& graph, vector<int>& cur, vector<int>& visited, int count) {
        if (result == graph.size()) 
            return;
        if (count == graph.size()) {
            result = min(result, int(cur.size()));
            return;
        }
        if (cur.size() >= result) return;
        int pos = cur.back();
        
        int minv = INT_MAX;
        for (auto n : graph[pos]) 
            minv = min(minv, visited[n]);
        for (auto n : graph[pos]) {
            if (visited[n] == minv) {
                cur.push_back(n);
                if (!visited[n]) count++;
                visited[n]++;
                dfs(graph, cur, visited, count);
                visited[n]--;
                if (!visited[n]) count--;
                cur.pop_back();                
            }
        }
    }
};
