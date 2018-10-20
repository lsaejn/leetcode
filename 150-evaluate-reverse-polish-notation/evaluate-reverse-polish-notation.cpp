// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
// Note:
//
//
// 	Division between two integers should truncate toward zero.
// 	The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
//
//
// Example 1:
//
//
// Input: ["2", "1", "+", "3", "*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
//
//
// Example 2:
//
//
// Input: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
//
//
// Example 3:
//
//
// Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
// Output: 22
// Explanation: 
//   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
//
//


class Solution {
public:
    //类似于表达式求值的逆运算。
    //这一次，
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i!=tokens.size();++i)
        {
            if((tokens[i]=="+")||(tokens[i]=="-")||(tokens[i]=="*")||(tokens[i]=="/"))
            {
                int right=s.top();
                s.pop();
                int left=s.top();
                s.pop();
                if(tokens[i]=="+") right=left+right;
                if(tokens[i]=="-") right=left-right;
                if(tokens[i]=="*") right=left*right;
                if(tokens[i]=="/") right=left/right;
                s.push(right);                   
            }
            else
                s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};
