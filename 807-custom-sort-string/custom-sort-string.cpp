// S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
//
// S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.
//
// Return any permutation of T (as a string) that satisfies this property.
//
//
// Example :
// Input: 
// S = "cba"
// T = "abcd"
// Output: "cbad"
// Explanation: 
// "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
// Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
//
//
//  
//
// Note:
//
//
// 	S has length at most 26, and no character is repeated in S.
// 	T has length at most 200.
// 	S and T consist of lowercase letters only.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //为S里的字母制定优先级
    //统计T内的字符，计算字母个数，然后重排即可
    string customSortString(string S, string T)
    {
        unordered_map<char,int> col;
        for(int i=0;i!=S.size();++i)
            col[S[i]]=i;
        unordered_map<char,int> chars;
        sort(T.begin(),T.end(),[&col](char a,char b){
            return col[a]<col[b];
        });
        return T; 
    }
};
