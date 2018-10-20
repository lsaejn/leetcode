// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// Example:
//
//
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //DFS
    //aabbabababccba
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> before;
        helper(s,result,before);
        return result;
        
    }
    
    void helper(string s,vector<vector<string>>& re,vector<string>& before)
    {
        if(s.empty()) 
        {
            re.push_back(before);
        }
        for(int i=1;i<=s.size();++i)
        {
            string temp=s.substr(0,i);
            if(valid(temp))
            {
                before.push_back(temp);
                helper(s.substr(i),re,before); 
                before.pop_back();
            }
        } 
    }
    
    inline bool valid(string& s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
};
