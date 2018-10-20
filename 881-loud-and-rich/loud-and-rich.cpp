// In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels of quietness.
//
// For convenience, we'll call the person with label x, simply "person x".
//
// We'll say that richer[i] = [x, y] if person x definitely has more money than person y.  Note that richer may only be a subset of valid observations.
//
// Also, we'll say quiet[x] = q if person x has quietness q.
//
// Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]), among all people who definitely have equal to or more money than person x.
//
//  
//
//
// Example 1:
//
//
// Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
// Output: [5,5,2,5,4,5,6,7]
// Explanation: 
// answer[0] = 5.
// Person 5 has more money than 3, which has more money than 1, which has more money than 0.
// The only person who is quieter (has lower quiet[x]) is person 7, but
// it isn't clear if they have more money than person 0.
//
// answer[7] = 7.
// Among all people that definitely have equal to or more money than person 7
// (which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x])
// is person 7.
//
// The other answers can be filled out with similar reasoning.
//
//
//
// Note:
//
//
// 	1 <= quiet.length = N <= 500
// 	0 <= quiet[i] < N, all quiet[i] are different.
// 	0 <= richer.length <= N * (N-1) / 2
// 	0 <= richer[i][j] < N
// 	richer[i][0] != richer[i][1]
// 	richer[i]'s are all different.
// 	The observations in richer are all logically consistent.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
	vector<int>* quiet;
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		this->quiet = &quiet;
		unordered_map<int, set<int>> col;
		map<int, int> result;
		for (auto elem : quiet)
		{
			col[elem];
			result[elem] = -1;
		}
		for (auto& elem : richer)
			col[elem[1]].insert(elem[0]);
		vector<int> re;
		for (auto& elem : col)
		{
			int i =dfs(elem.first, col, result);
			result[elem.first]=i;
		}
		re.resize(quiet.size());
		for (auto &elem : result)
			re[elem.first] = elem.second;
		return re;
	}

	int dfs(int index, unordered_map<int, set<int>>& col, map<int, int>& result)
	{
		if (result[index] != -1) 
            return result[index];
		if (col[index].size() == 0)
		{
			result[index] = index;
			return index;
		}
		int re = index;
		for (auto elem : col[index])
		{
			if (result[elem] != -1)
				re = (*quiet)[re]<(*quiet)[result[elem]] ? re : result[elem];
			else
            {
                int s=dfs(elem, col, result);
				re= (*quiet)[re]<(*quiet)[s] ? re : s;	
            }
		}
		result[index] = re;
		return re;
	}
};
