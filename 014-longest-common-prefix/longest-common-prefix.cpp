// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
//
// Input: ["flower","flow","flight"]
// Output: "fl"
//
//
// Example 2:
//
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
//
// Note:
//
// All given inputs are in lowercase letters a-z.
//


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//没看懂题目，这个和算法有什么关系？
        //可以先找到最小的字符串？
        if(strs.empty()) return "";
        for(int i=0;i<strs[0].size();++i)
            for(int j=1;j<strs.size();++j)               
                if(strs[j][i]!=strs[0][i])   return strs[0].substr(0,i);         
        return strs[0];       
    }
};
