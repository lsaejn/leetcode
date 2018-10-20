// In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.
//
// Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.
//
// Which nodes are eventually safe?  Return them as an array in sorted order.
//
// The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.
//
//
// Example:
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Here is a diagram of the above graph.
//
//
//
//
//
// Note:
//
//
// 	graph will have length at most 10000.
// 	The number of edges in the graph will not exceed 32000.
// 	Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
using vvi = vector<vector<int>>;
using usi = unordered_set<int>;
    
usi cycle_nodes;
usi safe_nodes;
    
bool dfs (const vvi& g, int i, usi visited_nodes) 
{    
	if (safe_nodes.find (i)  != safe_nodes.end ())  return true;  // we know safe already
	if (cycle_nodes.find (i) != cycle_nodes.end ()) return false; // we know in cycle already
        
	if (visited_nodes.find (i) != visited_nodes.end ()) {         // we have determined node is in cycle
		cycle_nodes.insert (i);
		return false;
	}

	visited_nodes.insert (i); // keep track of nodes we've visited already

	for (int node : g[i]) {
		if (!dfs (g, node, visited_nodes)) {
			cycle_nodes.insert (i); // if child is in cycle, parent must be too
			return false;
		}
	}

	safe_nodes.insert (i); // we know node is safe now
        
	return true;
}
    //graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    /*
    思路是这样:对于一个结点，首先看它是不是在安全区，不在则看它是不是在循环区，还不在，
    说明尚不确定，接着看它是不是已遍历，是则放入循环区。
    否则
    将其放入已遍历区。然后检查它的连通结点。
    
    我们来一次：
    循环遍历所有结点，
    dfs0
    
    0放入已遍历里{0}，开始dfs子节点
    1放入已遍历{0,1},
    2放入已遍历{0,1,2}
    5.......{0,1,2,5}
    5的子节点全部安全，所以5放入安全列表里
    2的子节点检查完毕，2放入安全
    3放入已遍历{0,1,2,3,5}
    3的的子节点里发现0，0已遍历，放到循环列表
    3结点检查完返回，把1放入循环列表，继续返回，0也是循环
    
    dfs1 直接返回
    dfs2已有结果
    dfs3 已有结点
    dfs4 返回true 
    dfs5 已有结果
    dfs6 已有结果
    
    
    */
vector<int> eventualSafeNodes(vvi& graph) 
{
	vector<int> ans;
	usi visited_nodes;
        
	for (int i = 0; i < graph.size (); i++) 
    {
		if (dfs(graph, i, visited_nodes)) 
            ans.push_back (i);
	}
        
	return ans;
}
};
