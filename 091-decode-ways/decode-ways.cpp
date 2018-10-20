// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//
//
// Example 2:
//
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
        //动态规划的解法非常巧妙
    int numDecodings(string s)
    {
    if (s.empty() || (s.size() > 1 && s[0] == '0')) return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) 
        {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                dp[i] += dp[i - 2];
        }
        return dp.back();
        /*超时超时超时超时超时超时超时超时超时超时超时超时超时超时超时超时超时超时超时超时超时
        if(s.empty()) return 0;
        int result=0;
        bool bad=false;
        result=helpMe(s,0,bad);        
        return result;
        */
        
    }
    //0,00-99->00->26;27->99
    
    int helpMe(string& s,int pos,bool& bad)//从s的第pos个位置开始选择。
    {
        if(pos==s.size()) return 1;
        string temp=s.substr(pos,2);
        auto x=stoi(temp);
        if(temp.size()==1)
        {
            if(temp[0]=='0')//0
                return 0;
            else return 1;//1-9
        }
        if(temp[0]=='0') return 0;
        
        if(x>=1&&x<=26)//1-26,不包括10，20，都有两种
        {
            if(x==20||x==10)
                return helpMe(s,pos+2,bad); 
            else
                return helpMe(s,pos+1,bad)+helpMe(s,pos+2,bad);
        }
        else
        {
          if(x%10==0)
              return 0;
            else
                return helpMe(s,pos+1,bad);                
        }            
    }
};
