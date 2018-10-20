// Given a balanced parentheses string S, compute the score of the string based on the following rule:
//
//
// 	() has score 1
// 	AB has score A + B, where A and B are balanced parentheses strings.
// 	(A) has score 2 * A, where A is a balanced parentheses string.
//
//
//  
//
//
// Example 1:
//
//
// Input: "()"
// Output: 1
//
//
//
// Example 2:
//
//
// Input: "(())"
// Output: 2
//
//
//
// Example 3:
//
//
// Input: "()()"
// Output: 2
//
//
//
// Example 4:
//
//
// Input: "(()(()))"
// Output: 6
//
//
//  
//
// Note:
//
//
// 	S is a balanced parentheses string, containing only ( and ).
// 	2 <= S.length <= 50
//
//
//
//
//


class Solution {
public://将括号转化成整数栈，左括号直接入栈，右括号则查看栈里是不是左括号，是就push1,这样，栈就是数字和括号的混合
    int scoreOfParentheses(string S) {
        int sum=0;
        stack<int> K;
        for(int i=0;i<S.length();i++)
        {
            switch(S[i])
            {
                case '(':
                    K.push(S[i]);
                    break;
                case ')':
                    if(K.top()=='(')
                    {
                        K.pop();
                        K.push(1);
                    }
                    else
                    {
                        int a=0;
                        while(K.top()!='('&&!K.empty())
                        {
                            a+=K.top();
                            K.pop();           
                        }
                        if(K.top()=='(')
                        {
                            int b=2*a;
                            K.pop();
                            K.push(b);
                        }
                        else
                            K.push(a);
                    }
                    break;
            }
        }
        while(!K.empty())
	    {
		    sum+=K.top();
		    K.pop();
	    }
        return sum;
    }
};
