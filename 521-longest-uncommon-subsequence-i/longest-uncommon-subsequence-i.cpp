//
// Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings.
// The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
//
//
//
// A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
//
//
//
// The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
//
//
// Example 1:
//
// Input: "aba", "cdc"
// Output: 3
// Explanation: The longest uncommon subsequence is "aba" (or "cdc"), because "aba" is a subsequence of "aba", but not a subsequence of any other strings in the group of two strings. 
//
//
//
// Note:
//
// Both strings' lengths will not exceed 100.
// Only letters from a ~ z will appear in input strings. 
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //abc abc abdccc dccccca
    int findLUSlength(string a, string b) {
        //依次用a构建子串取匹配b，让我们试一试
/*
        if(a.size()<b.size()) swap(a,b);
        int max=-1;
        for(int i=1;i<=a.size();++i)
        {
            string sub=a.substr(0,i);
            if(b.find(sub)==string::npos)
                max=sub.size();
            else
                continue;               
        }
return std::max(-1,max);
*/
        //这道题是在耍人
        //any string is a subsequence of itself 
 return a == b ? -1 : max(a.size(), b.size());       
    }
};
