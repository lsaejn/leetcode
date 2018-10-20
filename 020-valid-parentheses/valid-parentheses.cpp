// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// An input string is valid if:
//
//
// 	Open brackets must be closed by the same type of brackets.
// 	Open brackets must be closed in the correct order.
//
//
// Note that an empty string is also considered valid.
//
// Example 1:
//
//
// Input: "()"
// Output: true
//
//
// Example 2:
//
//
// Input: "()[]{}"
// Output: true
//
//
// Example 3:
//
//
// Input: "(]"
// Output: false
//
//
// Example 4:
//
//
// Input: "([)]"
// Output: false
//
//
// Example 5:
//
//
// Input: "{[]}"
// Output: true
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isPair(char c1,char c2){
        if((c1=='('&&c2==')')||(c1=='['&&c2==']')||(c1=='{'&&c2=='}'))
            return true;
        swap(c1,c2);
        if((c1=='('&&c2==')')||(c1=='['&&c2==']')||(c1=='{'&&c2=='}'))
            return true;
        return false;
    }
    
    bool isValid(string s) {//用栈最直观，顺序容器都可以
        stack<char> stack1;
        for(int i=0;i!=s.size();++i)
        {
            char c=s[i];
            if(c=='('||c=='['||c=='{')
                stack1.push(c);
            else{
                if(stack1.empty()) return false;
                if(isPair(c,stack1.top()))
                    stack1.pop();
                else
                    stack1.push(c);
            }
        }
        if(!stack1.empty()) return false;
        return true;
    }

};
