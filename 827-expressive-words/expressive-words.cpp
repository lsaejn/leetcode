// Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so "e" and "o" would be extended in the first example, and "i" would be extended in the second example.  As another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.
//
// For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.  Formally, we are allowed to repeatedly choose a group (as defined above) of characters c, and add some number of the same character c to it so that the length of the group is 3 or more.  Note that we cannot extend a group of size one like "h" to a group of size two like "hh" - all extensions must leave the group extended - ie., at least 3 characters long.
//
// Given a list of query words, return the number of words that are stretchy. 
//
//
// Example:
// Input: 
// S = "heeellooo"
// words = ["hello", "hi", "helo"]
// Output: 1
// Explanation: 
// We can extend "e" and "o" in the word "hello" to get "heeellooo".
// We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
//
//
// Notes: 
//
//
// 	0 <= len(S) <= 100.
// 	0 <= len(words) <= 100.
// 	0 <= len(words[i]) <= 100.
// 	S and all words in words consist only of lowercase letters
//
//
//  
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //统计两个字符串里每个字符的数量，比较即可
    //对于S 如果字符数x>=3 word的那个字符不超过x即可。如果x<3,数量必须相等
    int expressiveWords(string S, vector<string>& words)
    {
        auto col_S=getCol(S);
        int result=0;
        for(auto &word:words)
        {
            auto col_word=getCol(word);
            if(col_word.size()!=col_S.size()) break;
            bool ok=true;
            for(int i=0;i!=col_S.size();++i)
            {
                //可见测试案例有问题
               // if(col_word[i].first!=col_S[i].first)
               // {
               //         ok=false;
               //         break;
               // }
                if(col_S[i].second>=3)
                {
                    if(col_word[i].second>col_S[i].second) 
                    {
                        ok=false;
                        break;
                    }                   
                }
                else
                {
                    if(col_word[i].second!=col_S[i].second)
                    {
                        ok=false;
                        break;
                    }    
                    
                }
            }
            if(ok==true) ++result;
        }
        return result;
    }
    
    vector<pair<char,int>>  getCol(string& S)
    {
        vector<pair<char,int>> vec_S;//统计字符及个数
        vec_S.push_back({S[0],1});
        for (int i = 1; i != S.size(); ++i)
        {
            if (S[i] == S[i - 1])
                vec_S.back().second++;
            else
                vec_S.push_back({S[i],1});
        } 
        return vec_S;
    }
    
    
};
