// Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively. 
//
// Substrings that occur multiple times are counted the number of times they occur.
//
// Example 1:
//
// Input: "00110011"
// Output: 6
// Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
// Notice that some of these substrings repeat and are counted the number of times they occur.
// Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
//
//
//
// Example 2:
//
// Input: "10101"
// Output: 4
// Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
//
//
//
// Note:
// s.length will be between 1 and 50,000.
// s will only consist of "0" or "1" characters.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int countBinarySubstrings(string s)
    {
        //00110011
        //我们用cur保存当前bit位值的个数，用pre表示前一个bit位值得个数。
        //当pre>cur时，结果加1，表示一个类似00011得情况发生了
        //如果发生bit位反转，切换pre，cur=1，再继续判断。事实上发生bit反转，必然结果+1
        int res = 0, pre = 0, cur = 1, n = s.size();
        for (int i = 1; i < n; ++i) 
        {
            if (s[i] == s[i - 1]) 
                ++cur;
            else
            {
                pre = cur;
                cur = 1;
            }
            if (pre >= cur) 
                ++res;
        }
        return res;
    }
};
