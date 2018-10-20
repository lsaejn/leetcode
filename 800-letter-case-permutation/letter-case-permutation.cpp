// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.
//
//
// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
// Input: S = "3z4"
// Output: ["3z4", "3Z4"]
//
// Input: S = "12345"
// Output: ["12345"]
//
//
// Note:
//
//
// 	S will be a string with length at most 12.
// 	S will consist only of letters or digits.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<string> letterCasePermutation(string S) 
    {
        vector<string> result{S};//a1b2->a1b2,A1b2->a1b2 a1B2 A1b2 A1B2
        for(int i=0;i!=S.size();++i)
        {
            if(isalpha(S[i]))
            {
               char target=islower(S[i])?toupper(S[i]):tolower(S[i]);
               int n=result.size();
               for(int j=0;j!=n;++j)
                {
                    string temp=result[j];
                    temp[i]=target;
                    result.push_back(temp);
                }
            }
           
        }
       return result; 
    }
};
