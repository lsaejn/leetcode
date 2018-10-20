// Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
//
//
// Example :
// Input: 
// S = "abcde"
// words = ["a", "bb", "acd", "ace"]
// Output: 3
// Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
//
//
// Note:
//
//
// 	All words in words and S will only consists of lowercase letters.
// 	The length of S will be in the range of [1, 50000].
// 	The length of words will be in the range of [1, 5000].
// 	The length of words[i] will be in the range of [1, 50].
//


class Solution {
public:
    //我去，暴力查找直接通过了。。。。
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char,vector<int>> index;
        int result=0;
        for(int i=0;i!=S.size();++i)
            index[S[i]].push_back(i);
        for(auto &word:words)
        {
            int begin=-1;
            int i=0;
            for(;i!=word.size();++i)
            {
                //对每个字符都查找index，要求它大于之前那个字符的index
                if(index.count(word[i])&&index[word[i]].back()>begin)//存在这个字符,
                {
                    auto iter = upper_bound(index[word[i]].begin(), index[word[i]].end(), begin);
                    if (iter == index[word[i]].end())
                        break;
                    int newpos = *iter;// distance(index[word[i]].begin(), iter);
                    begin = newpos;            
                }                    
                else break;               
            }
            if(i==word.size())
                result++;                   
        }
        return result;
    }
};
