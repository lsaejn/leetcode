//
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
//
//
//
//
// Note: You may assume the string contain only lowercase letters.
//


class Solution {
public:
    int firstUniqChar(string s) {
        //显然用可重复无序map最快
        unordered_map<char, int> m;
        for (char c : s) 
            ++m[c];
        for (int i = 0; i < s.size(); ++i) {//关键在于我们第二次查找的时候是按顺序来查找
            if (m[s[i]] == 1) 
                return i;
        }
        return -1;
    }
        
};
