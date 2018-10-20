//
// Given a string s and a string t, check if s is subsequence of t.
//
//
//
// You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
//
//
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
//
//
// Example 1:
// s = "abc", t = "ahbgdc"
//
//
// Return true.
//
//
// Example 2:
// s = "axc", t = "ahbgdc"
//
//
// Return false.
//
//
// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


class Solution {
public:
    //这一题其实是另一题的子问题，792.但是我们的算法更适合这题
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> index;
        int result = 0;
        for (int i = 0; i != t.size(); ++i)
            index[t[i]].push_back(i);
        int begin = -1;
        int i = 0;
        for (; i != s.size(); ++i)
        {
                //对每个字符都查找index，要求它大于之前那个字符的index
            if (index.count(s[i]) && index[s[i]].back()>begin)//存在这个字符,
            {
                auto iter = upper_bound(index[s[i]].begin(), index[s[i]].end(), begin);
                if (iter == index[s[i]].end())
                    break;
                int newpos = *iter;// distance(index[word[i]].begin(), iter);
                begin = newpos;            
            }
            else break;
        }
        if (i == s.size())
            return true;
        return false;
    }
};
