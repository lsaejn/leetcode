//
// Equations are given in the format A / B = k, where  A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
//
// The input is:  vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return  vector<double>.
//
//
// According to the example above:
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
//
//
//
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这个题是体力活
    //其实是图的问题a->c?
    //把a的相邻结点放到队列，遍历这些结点，并把这些结点的相邻结点放到队列，注意要做个标记，如此即可
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> col;
        for(int i=0;i!=equations.size();++i)
        {
            col[equations[i].first].emplace(equations[i].second, values[i]);
            col[equations[i].first].emplace(equations[i].first, 1.0);
            col[equations[i].second].emplace(equations[i].first, 1.0 / values[i]);
            col[equations[i].second].emplace(equations[i].second, 1.0);
        }
        vector<double> re;
        for(auto& querie:queries)                   
            re.push_back(calcEquation(querie,col));
        return re;
    }
    
    double calcEquation(pair<string, string>& query,unordered_map<string, unordered_map<string, double>>& col)
    {
       if (!col.count(query.first) || !col.count(query.second)) //分子分母出现无记录字母
           return(-1.0);
       else 
       {
            queue<pair<string, double>> q;//广度遍历自己的直连结点
            unordered_set<string> used{query.first};//把自己放到已遍历列表
            bool find = false;
            q.push({query.first, 1.0});//把自己放入队列，开始循环
            while (!q.empty() && !find) 
            {
                queue<pair<string, double>> next;
                while (!q.empty() && !find) //注意哦，这里遍历的是已经有结果的且未入列过的
                {
                    pair<string, double> t = q.front(); //没有取引用
                    q.pop();
                    if (t.first == query.second) //找到就直接返回
                    {
                        find = true;
                        return t.second;
                    }
                    //else:
                    for (auto a : col[t.first]) 
                    {
                        if (!used.count(a.first))
                        {
                            a.second *= t.second;
                            next.push(a);
                            used.insert(a.first);
                        }
                    }                  
                }
                    q = next;               
            }
                if (!find) return (-1.0);
       }
    }
};
