// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
//
//  
//
// Example 1:
//
//
// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.
//
//
// Example 2:
//
//
// Input: "aba"
// Output: False
//
//
// Example 3:
//
//
// Input: "abcabcabcabc"
// Output: True
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
//
//


class Solution {
public:
    bool repeatedSubstringPattern(string str) {

        //aa abab abcabc ababab abcabcabc abcde abcde abcde
        int n = str.size();//12
        for (int i = n / 2; i >= 1; --i) 
        {
            if (n % i == 0) //2,3,4,6，取6
            {
                int c = n / i;//重复2次
                string t = "";
                for (int j = 0; j < c; ++j)
                {
                    t += str.substr(0, i); //拼接两次[0,6)
                }
                if (t == str) 
                    return true;
            }
        }
        return false;
        
    }
};
