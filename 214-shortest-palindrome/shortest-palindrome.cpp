// Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
//
// Example 1:
//
//
// Input: "aacecaaa"
// Output: "aaacecaaa"
//
//
// Example 2:
//
//
// Input: "abcd"
// Output: "dcbabcd"
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这是纯体力活动。。。kmp实在看不懂
    std::string shortestPalindrome(std::string s) {
		int len = s.length();
		if (len < 2)
			return s;
		// calculate the length of the longest palindromic prefix substring.
		int longest = 1, start, end;
		for (int begin = 0; begin <= len / 2;) {
			start = end = begin;
			while (end < len - 1 && s[end + 1] == s[end])//把前面的重复串跳过
				++end;
			begin = end + 1;
			while (end < len - 1 && start > 0 && s[end + 1] == s[start - 1]) //这里跳过回文串
            {
				++end;
				--start;
			}
			// start == 0 means the palindromic substring is also prefix string.
			if (start == 0 && longest < end - start + 1)//剩下的就是尾巴上的串
				longest = end - start + 1;
		}
		// reverse the remaining substring and adding it in front of s.
		std::string remaining = s.substr(longest, len - longest);//尾巴复制一下
		std::reverse(remaining.begin(), remaining.end());//逆序
		return remaining + s;//放到头部即可
    }
};
