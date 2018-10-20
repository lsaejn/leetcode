// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
//
// Example 1:
//
//
//
// Input: 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.
//
//
// Example 2:
//
//
// Input: 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
//
// Note: You may assume that n is not less than 2 and not larger than 58.
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //动态规划,10可以变成1-9,2-8,3-7,4-6,5-5。9，可以选择拆或不拆
    int integerBreak(int n) 
    {
        vector<int> dp(n+1,0);
        for(int i=2;i!=dp.size();++i)//i
        {
            int max_re=0;
            for(int j=1;j<=i;++j)
            {
                int temp=j*max(dp[i-j],i-j);
                max_re=max_re>temp?max_re:temp;
            }
            dp[i]=max_re;
        }
        return dp[n];
        
    }
};
