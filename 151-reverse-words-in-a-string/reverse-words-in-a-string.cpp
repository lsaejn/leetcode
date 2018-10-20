//
// Given an input string, reverse the string word by word.
//
//
//
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
//
//
//
// Update (2015-02-12):
// For C programmers: Try to solve it in-place in O(1) space.
//
//
// click to show clarification.
//
// Clarification:
//
//
//
// What constitutes a word?
// A sequence of non-space characters constitutes a word.
// Could the input string contain leading or trailing spaces?
// Yes. However, your reversed string should not contain leading or trailing spaces.
// How about multiple spaces between two words?
// Reduce them to a single space in the reversed string.
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    void reverseWords(string &s)
    {
        istringstream is(s);
        string tmp;
        s.clear();
        is >> tmp;
        s=tmp;
        while(is >> tmp) 
            s = tmp + " " + s;
    }
};
