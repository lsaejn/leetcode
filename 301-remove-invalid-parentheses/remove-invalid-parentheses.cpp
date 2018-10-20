// Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//
// Note: The input string may contain letters other than the parentheses ( and ).
//
// Example 1:
//
//
// Input: "()())()"
// Output: ["()()()", "(())()"]
//
//
// Example 2:
//
//
// Input: "(a)())()"
// Output: ["(a)()()", "(a())()"]
//
//
// Example 3:
//
//
// Input: ")("
// Output: [""]
//
//


class Solution{
public:
    //虽然通过，但有个地方需要改进，从右向左扫描的时候，需要一个end，避免重复。类似于begin
    //re_set是我们的中间字符，可以避免重复查找。
    //一个更好的办法是，指定查找的字符，通过reverse，将两个循环合成1个
	vector<string> removeInvalidParentheses(string s) {
		//先把左边的)和右边的(处理掉
		int i = 0, j = s.size() - 1;
		for (; i != s.size() && s[i] == ')'; ++i);
		for (; j >= 0 && s[j] == '('; --j);
		s = s.substr(i, j - i + 1);
		vector<string> re;
        set<string> re_set;
		helper(s, re, 0,re_set);
		return re;

	}
	//我们需要自己保证pos之前都是匹配的
	//即，对于向右扫描，)不能超过(。对于向左扫描，类似。
	void helper(string &s, vector<string>& re, int begin,set<string>& re_set)
	{
		unordered_map<char, set<int>> pos;//我们保存右括号出现的位置
		for (int i = 0; i != s.size(); ++i)
			if (s[i] == ')' || s[i] == '(') pos[s[i]].insert(i);
		int count_left = 0;
		int count_right = 0;
		for (int i = begin; i != s.size(); ++i)//重新统计是为了让逻辑清晰
		{
			if (s[i] == ')')
			{
				count_right++;
				if (count_right>count_left)//一遇到超标就删
				{
					auto pt = pos;
					for (auto elem : pos[s[i]])
						if (elem <= i)
						{
							string t = s;
							t.erase(elem, 1);
							auto iter = re_set.insert(t);
							if (iter.second == false) continue;
							pt[s[i]].erase(elem);
							helper(t, re, i,re_set);
							pt[s[i]].insert(elem);
						}
					return;
				}
			}
			else if (s[i] == '(') count_left++;
		}
		count_left = 0;
		count_right = 0;
		for (int i = s.size() - 1; i >= 0; --i)//重新统计是为了让逻辑清晰
		{
			if (s[i] == ')') count_right++;
			else if (s[i] == '(')
			{
				count_left++;
				if (count_right<count_left)//一遇到超标就删
				{
					auto pt = pos;
					for (auto elem : pos[s[i]])
						if (elem >= i)
						{
							string t = s;
							t.erase(elem, 1);
							auto iter = re_set.insert(t);
							if (iter.second == false) continue;
							pt[s[i]].erase(elem);
							helper(t, re, i,re_set);
							pt[s[i]].insert(elem);
						}
					break;
				}
			}
		}
		if (count_left == count_right)  re.push_back(s);
	}
};
