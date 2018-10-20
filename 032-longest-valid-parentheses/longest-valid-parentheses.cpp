// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
//
// Example 2:
//
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//
//


class Solution {
public:
    //用栈把无效的括号筛选出来，括号的距离就是有效字符串长度
    int longestValidParentheses(string s) {
        int max = 0,num = s.size();
        if(num==0||num==1)return 0;
        stack<int> sta;
        sta.push(-1);
        for(int i = 0;i<num;i++)
        {
            if(sta.size()==0)
            {
                sta.push(i);
                continue;
            }
            if(s[i] == ')' && s[sta.top()] == '(') 
                sta.pop();
            else 
                sta.push(i);
        }
        int right = num;
        while(!sta.empty())//栈的两个元素之间的长度就是合法的字符串长度，找到最大值
        {
            int len = right-sta.top()-1;
            if(len>1)
                max = max>len?max:len;
            right = sta.top();
            sta.pop();
        }
        return max;
    }
};
