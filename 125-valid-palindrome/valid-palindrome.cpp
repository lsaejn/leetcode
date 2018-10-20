// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//


class Solution {
public:
    bool isPalindrome(string s) 
    {
        //首先取空格，然后首尾遍历，直到begin>=end
        int begin=0;
        int end=s.size()-1;
        while(begin<end)
        {
            if(std::isalnum(s[begin])&&std::isalnum(s[end]))
               {
                   if(someAlpha(s[begin],s[end]))
                      begin++,end--;
                    else
                     return false;
               }
            else
            {
                if(!std::isalnum(s[begin])) begin++;
                if(!std::isalnum(s[end])) --end;
            }           
        }
        return true;
        
    }
    //辅助函数
    bool someAlpha(char a,char b)
    {
        if(a>='A'&&a<='Z')//a是大写
            a=tolower(a);
                if(b>='A'&&b<='Z')//a是大写
            b=tolower(b);
        return a==b;       
    }
};
