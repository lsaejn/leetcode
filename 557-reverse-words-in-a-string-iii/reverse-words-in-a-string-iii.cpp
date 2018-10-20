// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
// Example 1:
//
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
//
//
//
// Note:
// In the string, each word is separated by single space and there will not be any extra space in the string.
//


class Solution {
public:
    string reverseWords(string s) {
        //查找空格，找到则反转
        auto begin=s.begin();
        //不需要trim
        auto end=find(begin,s.end(),' ');
        while(end!=s.end())
        {
            reverse(begin,end);
            
            begin=end+1;
            end=find(begin,s.end(),' ');
        }
        reverse(begin,s.end());
        cout<<s<<endl;
        return s;
    }
};
