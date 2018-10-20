// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
//
// Each person may dislike some other people, and they should not go into the same group. 
//
// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
//
// Return true if and only if it is possible to split everyone into two groups in this way.
//
//  
//
//
//
//
//
//
//
//
//
// Example 1:
//
//
// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
//
//
//
// Example 2:
//
//
// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
//
//
//
// Example 3:
//
//
// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 2000
// 	0 <= dislikes.length <= 10000
// 	1 <= dislikes[i][j] <= N
// 	dislikes[i][0] < dislikes[i][1]
// 	There does not exist i != j for which dislikes[i] == dislikes[j].
//
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool possibleBipartition(int N, std::vector<std::vector<int>>& dislikes)
    {
        if (dislikes.size() == 0) return true;
        std::unordered_map<int, std::unordered_set<int>> graph;

        for (const auto& link : dislikes) //{1,{2,3}},{2,{1,4}},{3,{1}},{4,{2}}
        {
            graph[link[0]].insert(link[1]);
            graph[link[1]].insert(link[0]);
        }

        std::stack<std::pair<int, int>> dfs_stack;//second是组号

        std::unordered_set<int> visited;
        std::array<std::unordered_set<int>, 2> groups;

        dfs_stack.push({dislikes[0][0], 0});//嗯？{1,0}

        while (!dfs_stack.empty())
        {
            auto current = dfs_stack.top();
            dfs_stack.pop();          
            visited.insert(current.first);
            groups[current.second].insert(current.first);
            
            for (int node : graph[current.first]) //尝试将dislike结点放入另一组
            {
                if (groups[current.second].count(node) > 0) //本组出现讨厌的人
                    return false;
                if (visited.count(node) == 0) 
                    dfs_stack.push({node, (current.second + 1) % 2});              
            }
        }

        return true;        
    }
};

