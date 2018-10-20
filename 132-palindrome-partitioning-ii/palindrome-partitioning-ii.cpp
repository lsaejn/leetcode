// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// Example:
//
//
// Input: "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这个和dfs没什么本质区别，但是优化的之处在于
    //依赖于ispal快速找到索引i可以匹配的最长的回文。对于"aaabaa"，第一次匹配最长并不是好事
    //所以我们还是要检索所有可以匹配的索引。
	int minCut(string s) {
        cout<<s.size()<<endl;
		queue<int> node;
		node.push(0);
		int cuts = 0;
        int end=s.size()-1;
		//bfs
		vector<bool> visited(s.size(), false);
		while (true)
        {
			queue<int> tmp;
			while (!node.empty())
            {
				int cur = node.front();
				node.pop();
				for (int i = end; i >= cur; i--)
                {
					if (visited[i]==false&&ispal(s, cur, i))
                    {
						if (i == s.size() - 1)
							return cuts;
						tmp.push(i+1);
                        //break;
					}
				}
				visited[cur] = true;//这个变量看着没有用，但是如果出现abcdefghijk
                //cout<<cur<<" "<<endl;
			}
			cuts++;
			node = tmp;
		}
	}

	bool ispal(string& s, int pre, int post){
		while (pre < post){
			if (s[pre++] != s[post--])
				return false;
		}
		return true;
	}
};
