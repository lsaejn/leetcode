// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public://遍历，不断得到i位置上的最长子串
	int lengthOfLongestSubstring(string s)
	{
		if (s.empty()) return 0;
		int begin = 0;
		int max = 1;
		int count = 1;
		for (int i = 1; i != s.size(); ++i)
		{
			//string t(1, s[i]);
			auto pos = s.find(s[i], begin);
			if ( pos>=i)
			{
				count++;
				if (count>max)
					max = count;
			}
			else
			{
				begin=pos+1;
				count=i-begin+1;
			}
		}
		return max;
	}
};
