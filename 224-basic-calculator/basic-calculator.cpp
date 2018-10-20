// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
//
// Example 1:
//
//
// Input: "1 + 1"
// Output: 2
//
//
// Example 2:
//
//
// Input: " 2-1 + 2 "
// Output: 3
//
// Example 3:
//
//
// Input: "(1+(4+5+2)-3)+(6+8)"
// Output: 23
// Note:
//
//
// 	You may assume that the given expression is always valid.
// 	Do not use the eval built-in library function.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //只要不出现幂，我们都可以通过栈来做
    //优先级(,*,/,+,-
    //遇到低优先级的，我们一直出栈到出现更低的，括号例外
    //模拟一下 ,ok
    //stack in 
    //out 23
    int calculate(string s) 
    {
        s.push_back('#');
        stack<int> nums;
        stack<char> ops;
        for(int i=0;i!=s.size();++i)
        {
            if(isdigit(s[i]))
            {
                string str;
                str.push_back(s[i]);
                while(i+1<s.size()&&isdigit(s[i+1]))
                {
                    str.push_back(s[i+1]);
                    i++;
                }
                nums.push(stoi(str));
                
            }
            else if(s[i]!=' ')//不是空格
            {
                if(s[i]=='(') ops.push(s[i]);
                else if(s[i]==')')
                {
                    if(ops.top()=='(') 
                    {
                        ops.pop();
                        continue;
                    }
                    while(ops.top()!='(') 
                    {
                       int right=nums.top(); nums.pop();                       
                       int left=nums.top();nums.pop();
                       char op=ops.top();ops.pop();
                        if(op=='+') left=left+right;
                        if(op=='-') left=left-right;
                        nums.push(left);
                    }
                        ops.pop();

                }
                else if(s[i]=='+'||s[i]=='-')//+ -
                {
                    //一直计算到没有操作符都比当前低为止。因为没有乘除，所以
                    while(!ops.empty()&&(ops.top()=='+'||ops.top()=='-')) 
                    {
                       int right=nums.top(); nums.pop();                       
                       int left=nums.top();nums.pop();
                       char op=ops.top();ops.pop();
                        if(op=='+') left=left+right;
                        if(op=='-') left=left-right;
                        nums.push(left);
                    }
                    ops.push(s[i]);
                }
                else if(s[i]=='#')
                {
                    if(ops.empty()) return nums.top();
                       int right=nums.top(); nums.pop();                       
                       int left=nums.top();nums.pop();
                       char op=ops.top();ops.pop();
                        if(op=='+') left=left+right;
                        if(op=='-') left=left-right;
                        nums.push(left); 
                }
                
            }           
        }
        return nums.top();
        
    }
};
