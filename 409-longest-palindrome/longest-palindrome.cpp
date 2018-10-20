// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
// This is case sensitive, for example "Aa" is not considered a palindrome here.
//
// Note:
// Assume the length of given string will not exceed 1,010.
//
//
// Example: 
//
// Input:
// "abccccdd"
//
// Output:
// 7
//
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
//
//


class Solution {
public:
    int longestPalindrome(string s) {
        //找对子即可，剩下1个元素则为对子数+1
        //不剩或着超过一个元素，则返回对子数
        //将s排序，从头到尾遍历，aabbc aaabbcd aabbcdf aabcdeffgghk
        //std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
        sort(s.begin(),s.end());
        char before=s[0];
        int count=0;//pair
        int same_count=0;
        for(int i=0;i!=s.size();++i)
        {
            
            if(s[i]==before)
            {
                ++same_count;
            }
            else
            {
                before=s[i];
                count+=same_count/2;
                same_count=1;
            }  
            if(i==s.size()-1)
            {
               count+=same_count/2; 
            }
        }
        if(s.size()>count*2)
        return count*2+1;
        
        return count*2;
        
    }
};
