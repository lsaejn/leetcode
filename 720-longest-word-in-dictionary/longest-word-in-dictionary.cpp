// Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words.  If there is more than one possible answer, return the longest word with the smallest lexicographical order.  If there is no answer, return the empty string.
//
// Example 1:
//
// Input: 
// words = ["w","wo","wor","worl", "world"]
// Output: "world"
// Explanation: 
// The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
//
//
//
// Example 2:
//
// Input: 
// words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// Output: "apple"
// Explanation: 
// Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
//
//
//
// Note:
// All the strings in the input will only contain lowercase letters.
// The length of words will be in the range [1, 1000].
// The length of words[i] will be in the range [1, 30].
//


class Solution {
public:
    string longestWord(vector<string>& words) {
        //是什么思路呢？首先，只有30个单词，我们完全可以遍历
        //先按长度排序，然后遍历，看自己是不是别人的子串，若不是，再向后
        //来试试 "banana","apple""apply" "appl","app", , "ap", ,  "a",
        //这里有个要求，比如apple,appl,app,ap,a都需要存在,这正是第一个程序效率不佳的原因
        /*
        sort(words.begin(),words.end(),[](string& s1,string& s2){
            return s1.size()>s2.size()||s1.size()==s2.size()&&s1<s2;
        });

        unordered_set<string> col;
        for(int i=0;i!=words.size();++i)
        {
            col.insert(words[i]);
        }
        for(int i=0;i!=words.size();++i)
        {     
            cout<<"to find   "<<words[i]<<endl;
            for(int j=words.size()-1;j>=0;--j)
            {
                string subStr=words[i].substr(0,j);
                cout<<"finded   "<<subStr<<endl;
                if(col.find(subStr)==col.end())//没找到
                {
                    break;
                }   
                
                if(j==1)
                    return words[i];
            }           
        }
        return "";    
        */
        string res = "";
        unordered_set<string> s;
        //"banana","apple""apply" "appl","app", , "ap", ,  "a",
        sort(words.begin(), words.end());
        for (string word : words) 
        {
            if (word.size() == 1 || s.count(word.substr(0, word.size() - 1)))
            {
                res = (word.size() > res.size()) ? word : res;
                s.insert(word);
            }
        }
        return res;
    }
};
