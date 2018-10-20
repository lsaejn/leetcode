//
// Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
//
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
// An empty string is also valid.
//
//
//
// Example 1:
//
// Input: "()"
// Output: True
//
//
//
// Example 2:
//
// Input: "(*)"
// Output: True
//
//
//
// Example 3:
//
// Input: "(*))"
// Output: True
//
//
//
// Note:
//
// The string size will be in the range [1, 100].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool checkValidString(string s) 
    {
       //使用两个stack，分别存放左括号和星号的位置，遍历字符串，当遇到星号时，压入星号栈star，当遇到左括号时，压入左括号栈left，当遇到右括号时，此时如果left和star均为空时，直接返回false；如果left不为空，则pop一个左括号来抵消当前的右括号；否则从star中取出一个星号当作左括号来抵消右括号。
        //验证一下(*))  ***()) ((*)*)*  *(*(()**)*))*)*))
        //然后是左括号数量大于右括号数量
        
        stack<int> left, star;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*') star.push(i);
            else if (s[i] == '(') left.push(i);
            else 
            {
                if (left.empty() && star.empty())//右括号没有找到左括号和* 
                    return false;
                if (!left.empty())
                    left.pop();
                else star.pop();
            }
        }
        while (!left.empty() && !star.empty())
        {
            if (left.top() > star.top())//*号不足以配对左括号
                return false;
            left.pop(); star.pop();
        }
        return left.empty();
    }
};
