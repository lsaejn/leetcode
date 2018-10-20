// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//


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
