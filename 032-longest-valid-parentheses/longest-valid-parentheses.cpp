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
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


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
