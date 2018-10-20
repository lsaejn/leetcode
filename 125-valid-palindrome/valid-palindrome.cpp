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
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


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
