// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
// Note:
//
//
// 	The same word in the dictionary may be reused multiple times in the segmentation.
// 	You may assume the dictionary does not contain duplicate words.
//
//
// Example 1:
//
//
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
//
//
// Example 2:
//
//
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.
//
//
// Example 3:
//
//
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
//
//


class Solution {
public:
    //为了让查找更快，我们将字典放入哈希表
    //深度遍历发生了超时
    //使用动态规划可以提高效率。如果位置1是可以达到的，我们只需要判断1到2是不是有字典。
    //有则可以达到。
    bool wordBreak(string s, vector<string>& wordDict)    
    {
        /*
        unorder_set<string> dict;
        for(auto &elem:wordDict)
            dict.insert(std::move(elem));
        int len = s.size();
        vector<bool> res(len + 1, false);
        res[0] = true;
        for (int i = 0; i < len + 1; ++i) 
        {
            for (int j = 0; j < i; ++j)
            {
                if (res[j] && dict.find(s.substr(j, i-j)) != dict.end()) 
                {
                    res[i] = true;
                    break;
                }
            }
        }
        return res[len];
        */
        unordered_set<string> dict;
        for(auto &elem:wordDict)
            dict.insert(std::move(elem));
        int len = s.size();
        vector<bool> res(len + 1, false);//res[i]代表i之前都是可达的。res[0]-[len]
        res[0] = true;
        for(int i=0;i!=len;++i)
        {
            if(res[i]==false) continue;
            for(auto &elem:dict)
            {//0123
                if(i==s.find(elem,i))
                    res[i+elem.size()]=true;
            }
        }
        return res[len];
    }
};
