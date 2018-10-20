// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: "3+2*2"
// Output: 7
//
//
// Example 2:
//
//
// Input: " 3/2 "
// Output: 1
//
// Example 3:
//
//
// Input: " 3+5 / 2 "
// Output: 5
//
//
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
    //我们在上一次的基础上添加功能。只要不出现幂级数，这套代码都是可以的。
    //根据题意，不会出现8/3*3=8
    unordered_map<char,int> priors={{'(',0},{'+',1},{'-',1},{'*',3},{'/',3},{')',4},{'#',0}};
    int getPrior(char c)
    {
        return priors[c];
    }
    void calcuOnce()
    {
        int right=nums.top(); nums.pop();                       
        int left=nums.top();nums.pop();
        char op=ops.top();ops.pop(); 
        if(op=='+') left=left+right;
        if(op=='-') left=left-right;
        if(op=='*') left=left*right;
        if(op=='/') left=left/right;
        nums.push(left);
    }
    
    void flush(char op)
    {
        auto prior=getPrior(op);
        while(!ops.empty()&&getPrior(ops.top())>=prior)
        {
            calcuOnce();
        }
        ops.push(op);
    }

    int calculate(string s)
    {
        s.push_back('#');//'#'是结尾
        for(int i=0;i!=s.size();++i)//表达式处理是一边处理一边读取，我们只能写大量的if-else
        {
            if(isdigit(s[i]))//数字，继续读取，知道
            {
                string str;
                str.push_back(s[i]);
                while(i+1<s.size()&&isdigit(s[i+1]))//如果下一个是数字，添加，再增加索引
                {
                    str.push_back(s[i+1]);
                    i++;
                }
                nums.push(stoi(str));               
            }
            else if(s[i]!=' ')//不是空格
            {
                flush(s[i]);   
            }           
        }
        return nums.top(); 
    }
private:                          
    stack<int> nums;//数字栈
    stack<char> ops;//符号栈
};
