// There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.
//
// Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
//
//
// Example 1:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
// Explanation: 
// The graph looks like this:
//
//
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
//
//
// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
// Explanation: 
// The graph looks like this:
//
//
// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
//
// Note:
//
//
// 	The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// 	The size of flights will be in range [0, n * (n - 1) / 2].
// 	The format of each flight will be (src, dst, price).
// 	The price of each flight will be in the range [1, 10000].
// 	k is in the range of [0, n - 1].
// 	There will not be any duplicated flights or self cycles.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


//DFS是Dijkstra算法
//BFS思路是维护一个起点到当前点的花费信息。比如0为起点，如果0是终点，更新答案，否则把0的相邻结点1,2,3放入，计算0到1/2的花费，
//然后依次下去。这样，比如1-2-3到比0-3花费更小，花费信息也会得到更新。
//dp的思路就是BFS的简化。维护一个dp[i][j]

class Solution {
public:
    //这个完全是Dijkstra
    int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int K) {
       unordered_map<int, vector<pair<int,int>>> col;//起点,<终点,花费>
       for (const auto& flight : flights)
            col[flight[0]].emplace_back(flight[1], flight[2]);        
        int ans = INT_MAX;
        vector<bool> visited(n,false);
        dfs(s, d, K + 1, 0, visited, ans, col);//
        return ans == INT_MAX ? - 1 : ans;
    }
    
    //k是还可以行走的次数，0次中转意味着k=1
    void dfs(int s, int d, int k, int cost, vector<bool>& visited, int& ans, unordered_map<int, vector<pair<int,int>>>& col ) {
        if (s == d) { ans = cost; return; }
        if (k == 0) return; 
        visited[s]=1;
        for (const auto& x : col[s]) {
          if (visited[x.first]==0){
              if (cost + x.second > ans) continue; // IMPORTANT!!! prunning 
     
              dfs(x.first, d, k - 1, cost + x.second, visited, ans, col); 
             
          }
        }
         visited[s] = 0;
  }
};
