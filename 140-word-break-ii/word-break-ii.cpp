// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
//
// Note:
//
//
// 	The same word in the dictionary may be reused multiple times in the segmentation.
// 	You may assume the dictionary does not contain duplicate words.
//
//
// Example 1:
//
//
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
//
//
// Example 2:
//
//
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
//
//
// Example 3:
//
//
// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
	unordered_set<string> col;
	//应该是dfs无疑。但这道题一直tmd超时，卡在测试用例aaaaaaaaaaaaaa,[a,aa,aaa,aaaa,aaaaaa....]
    //办法是保存中间结果。
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_map<string, vector<string>> hash;
		for (auto &elem : wordDict)
			col.insert(std::move(elem));
		string str_result;
		return dfs(s, hash);
	}

    //
	vector<string> dfs(string src, unordered_map<string, vector<string>>& hash)
	{
		if (hash.find(src) != hash.end())
			return hash[src];
		if (src.size() == 0)
			return {""};//dog最后会找到空字符串，这是答案之一，我们需要返回一个空字符串，而不是空容器
		vector<string> s;
		string tmp;
		for (int i = 0; i != src.size(); ++i)
		{
			tmp += src[i];
			if (col.find(tmp) != col.end())
			{
				auto after = dfs(src.substr(i + 1), hash);//如果没有匹配的，那么返回一个空的容器
				for (auto &elem : after)
				{
					if (!elem.empty())
					{
						elem = tmp + " " + elem;
						s.push_back(elem);
					}
					else
						s.push_back(tmp);
				}
			}
		}
		hash.insert({ src,s });
		return s;//无匹配则返回空容器
	}
};
