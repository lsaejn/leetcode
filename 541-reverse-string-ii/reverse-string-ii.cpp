//
// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
//
//
// Example:
//
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
//
//
//
// Restrictions: 
//
//  The string consists of lower English letters only.
//  Length of the given string and k will in the range [1, 10000]
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string reverseStr(string s, int k) 
    {
        int n = s.size(), cnt = n / k;
        for (int i = 0; i <= cnt; ++i)
        {
            if (i % 2 == 0)
            {
                if (i * k + k < n) reverse(s.begin() + i * k, s.begin() + i * k + k);
                else  reverse(s.begin() + i * k, s.end());
            }
        }
        return s;
    }
};
