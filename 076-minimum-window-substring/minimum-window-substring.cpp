// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
//
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
//
//
// Note:
//
//
// 	If there is no such window in S that covers all characters in T, return the empty string "".
// 	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//
//


class Solution {
public:
    /*
- 我们最开始先扫描一遍T，把对应的字符及其出现的次数存到哈希表中。
- 然后开始遍历S，遇到T中的字符，就把对应的哈希表中的value减一，直到包含了T中的所有的字符，纪录一个字串并更新最小字串值。
- 将子窗口的左边界向右移，略掉不在T中的字符，如果某个在T中的字符出现的次数大于哈希表中的value，则也可以跳过该字符。
    */   
    string minWindow(string S, string T) 
    {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
        unordered_map<char, int> m;
        for (int i = 0; i < T.size(); ++i) 
            ++m[T[i]];

        for (int right = 0; right < S.size(); ++right) 
        {
            if (m.find(S[right]) != m.end())
            {
                --m[S[right]];
                if (m[S[right]] >= 0) ++count;//找到了t里的一个字符，而这个字符还在查找列表里
                while (count == T.size()) 
                {
                    if (right - left + 1 < minLen) 
                    {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    if (m.find(S[left]) != m.end())
                    {
                        ++m[S[left]];
                        if (m[S[left]] > 0) --count;//满足条件的字符少了一个
                    }
                    ++left;
                }
            }
        }
        return res;
    }

};
