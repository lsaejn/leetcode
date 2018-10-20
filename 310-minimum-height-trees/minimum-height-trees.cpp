// For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
//
// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
//
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
//
// Example 1 :
//
//
// Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
//
//         0
//         |
//         1
//        / \
//       2   3 
//
// Output: [1]
//
//
// Example 2 :
//
//
// Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
//
//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5 
//
// Output: [3, 4]
//
// Note:
//
//
// 	According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
// 	The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
//
//


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
    {
        if (n == 1) return {0};
        unordered_map<int, set<int>> col;
        for (int i = 0; i != edges.size(); ++i)
        {
            set<int>& yy = col[edges[i].first];
            col[edges[i].first].insert(edges[i].second);
            col[edges[i].second].insert(edges[i].first);
        }
        while (col.size()>2)
        {
            vector<int> toDelete;
            for (auto iter = col.begin(); iter != col.end(); ++iter)
            {
                if (iter->second.size() == 1)
                {
                    toDelete.push_back(iter->first);
                }
            }
            for (auto elem : toDelete)
            {
                col.erase(elem);
                for (auto iter = col.begin(); iter != col.end(); iter++)
                {
                    if (iter->second.find(elem) != iter->second.end())
                        iter->second.erase(elem);
                }
            }
        }
        vector<int> result;
        for (auto elem : col)
        {
            result.push_back(elem.first);
        }
        return result;
    }
};
