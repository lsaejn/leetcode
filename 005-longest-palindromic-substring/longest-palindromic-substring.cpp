// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string longestPalindrome(string s) {
			s = Manacher(s);
			string result;
			for (int i = 1; i != s.size(); ++i)
			{
				for (int j = 1; i - j >= 0 && i + j<s.size(); ++j)
				{
					if (s[i + j] == s[i - j])
					{						
						if (2*j+1>result.size()) 
                            result = s.substr(i - j, 2*j+1);
					}
					else break;
				}

			}
			result.erase(remove(result.begin(), result.end(), '#'), result.end());
			return result;       
    }
    
    string Manacher(string& s) {
    // Insert '#'
    string t = "#";
    for (int i = 0; i < s.size(); ++i) 
    {
        t += s[i];
        t += "#";
    }
        return t;
    }
};
