//
// There are N network nodes, labelled 1 to N.
//
// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
//
// Now, we send a signal from a certain node K.  How long will it take for all nodes to receive the signal?  If it is impossible, return -1.
//
//
// Note:
//
// N will be in the range [1, 100].
// K will be in the range [1, N].
// The length of times will be in the range [1, 6000].
// All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
//
//


class Solution 
{
public:
    /*
        最重要的就是理解题意，题目的意思是：当信号到达了一个结点时，在下一刻可以同时转发给该结点相邻的所有结点，求传送到每一个结点的最终时间。这样，问题就变成了求解从结点 K 到所有结点的单源最短路问题，然后，从中选择最长的一条路所用的时间即为答案。因此本题使用 Dijkstra 算法进行求解。需要注意的是每次从所有的路径中选择最短路径的结点出来后，要将该结点设置为已访问，避免再重复访问。
       测试用例 [[2,1,1],[2,3,1],[3,4,1],[1,5,9],[2,5,100]]
        5
        2
       dijkstra应该算是BFS算法，原理很简单，每次挑选最长的可以走的路
    */
    vector<int> dijkstra(vector<vector<pair<int,int>>>& g, int src)
    {
        int n = g.size();
        vector<int> ret(n, -1);//结点是否使用的标记，记录的是距离
        //用 std::greater<T> 将导致最小元素作为 top() 出现。
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;//元素是{距离，id-1}
        q.push({0,src});
        //你可能想不通，但确实如此，每次选择可选路径里离自己所用时间最少的地方
        //如果
        /*
        https://www.cnblogs.com/jason2003/p/7222182.html
            我们模拟一次：
            起点是2，距离0，ret[2]=0,队列放入所有相邻结点{1,1} {1,3} {100,5}
            取出{1,1}
            现在起点是1,距离1，ret[1]=1,队列放入1的相邻结点{9+1,5}
            取出{1,3}
            现在起点是3,距离1，ret[3]=1,队列放入3的相邻结点{2,4}
            取出{2,4}
            现在起点是4,距离2，ret[4]=2,4没有相邻结点
            取出{10,5}
            现在起点是5,距离10，ret[5]=10,5没有相邻结点
            取出{100,5}
            ret[5]!=-1,返回，
            队列空了，退出循环
            寻路结束
        */
        while(!q.empty()){
            auto x = q.top(); q.pop();
            int c = x.first, v = x.second;
            
            if(ret[v] != -1) continue;
            ret[v] = c;
            for(auto p : g[v]) q.push({p.second + c, p.first});
        }

        return ret;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
        vector<vector<pair<int,int>>> g(N);//为每个结点生成一个表
        
        for(int i=0; i<times.size(); i++)
        {
            int u = times[i][0] - 1, v = times[i][1] - 1, c = times[i][2];
            g[u].push_back({v,c});
        }
        
        auto ret = dijkstra(g, K-1);
        int hi = 0;
        for(int i=0; i<N; i++)
        {
            if(ret[i] == -1) return -1;
            hi = max(hi, ret[i]);
        }
        return hi;
    }
};
