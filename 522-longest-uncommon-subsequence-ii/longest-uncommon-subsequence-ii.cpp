//
// Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
//
//
//
// A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
//
//
//
// The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
//
//
// Example 1:
//
// Input: "aba", "cdc", "eae"
// Output: 3
//
//
//
// Note:
//
// All the given strings' lengths will not exceed 10.
// The length of the given list will be in the range of [2, 50].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


//如果字符串不是其他任何字符串的子序列，它就是最长的
// s1 = aebece S2 = abc, false
//s1=abc s2=ahbhcj true
//判断s2是不是S1的子串
bool isSubStringOf(string &s1, string &s2){
    //return s1 == s2 ? false : (s2.size()>s1.size()? true:false);
    int i = 0, j = 0;
    while (i < s1.size())
    {
        while (j < s2.size() && s1[i] != s2[j])
            j++;
        if (j == s2.size())
            return false;
        i++;
        j++;
    }
    return true;
}

//1.如果这个字符串长度最长，且是唯一，那么它就是最长子序列。所以按长度排序是必要的
//2.如果1不满足，说明有很多次长的字符串，我们只需要看它是不是长度比他更长的字符串的子序列即可。
class Solution {
public:
    int findLUSlength(vector<string>& strs)
    {
        unordered_map<string, int> mp;
        for (const auto& str : strs) mp[str]++;        
        vector<pair<string, int>> vec;
        for (const auto& m : mp) vec.push_back(m);
        sort(vec.begin(), vec.end(), [](pair<string,int> &a, pair<string,int> &b) {
            return a.first.size() > b.first.size();});
        for (int i = 0; i < vec.size(); i++) 
        {
            if (1 == vec[i].second)//如果出现重复字符串，那么本字符串全部失效 
            {
                int j = 0;
                for (; j < i; j++)
                    if (isSubStringOf(vec[i].first, vec[j].first))//因为我们从最长开始找，abcabc，
                        break;                       
                if (j == i)//不是任何字符串的子串，那么本字符串就是最长
                    return vec[i].first.size();        
            }
        }
        
        return -1;
    }
};
