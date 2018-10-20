//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
/*
再来看那一种方法，这种方法是CareerCup书上给的方法，感觉也是满巧妙的一种方法，这种方法的思想是找左括号，每找到一个左括号，就在其后面加一个完整的括号，最后再在开头加一个()，就形成了所有的情况
()-> ()() (())->(())(),()(()),()()()->
*/
    vector<string> generateParenthesis(int n)
    {
        if(n==0) return {};
        if(n==1) return {"()"};
        vector<string> result{"()"};
        generateParenthesis(result,n-1);
        
        return result;
    }
    
    void generateParenthesis(vector<string>& vec,int n)
    {
        if(n==0) return;
        vector<string> result;
        result.reserve(vec.size()*3);
        for(int i=0;i!=vec.size();++i)
        {
            result.push_back("()"+vec[i]);
            //每个元素，都要找"(",
            for (int j = 0; j < vec[i].size(); ++j)
                if (vec[i][j] == '(') 
                {
                    vec[i].insert(vec[i].begin() + j + 1, '(');
                    vec[i].insert(vec[i].begin() + j + 2, ')');
                    result.push_back(vec[i]);
                    vec[i].erase(vec[i].begin() + j + 1, vec[i].begin() + j + 3);
                }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        vec=result;
        generateParenthesis(vec,n-1);
    }
};
