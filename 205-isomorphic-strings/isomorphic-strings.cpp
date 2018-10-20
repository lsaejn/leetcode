// Given two strings s and t, determine if they are isomorphic.
//
// Two strings are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
// Example 1:
//
//
// Input: s = "egg", t = "add"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "foo", t = "bar"
// Output: false
//
// Example 3:
//
//
// Input: s = "paper", t = "title"
// Output: true
//
// Note:
// You may assume both s and t have the same length.
//


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //第一直觉是可以一次遍历
        //直接用哈希表，然后依次遍历第一个字符串（同时字符串2），寻找最后一个和自己匹配的字符，或者都不存在，或者都存在
        map<char,int> col1;
        map<char,int> col2;
        for(int i=0;i!=s.size();++i)
        {
            auto iter1=col1.find(s[i]);
            auto iter2=col2.find(t[i]);
         


 
            
            if((iter1==col1.end()&&iter2==col2.end()))
            {
                col1[s[i]]=i;
                col2[t[i]]=i;
                continue;              
            }
            else if((iter1!=col1.end()&&iter2!=col2.end()))
            {
                if(iter1->second==iter2->second)
                {
                    col1[s[i]]=i;
                    col2[t[i]]=i;
                    continue; 
                    //goto doContinue;
                }   
            }
            return false;
 
        }
        return true;
    }
};
