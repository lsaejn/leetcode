// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
// Example 1:
//
//
// Input: [5,7]
// Output: 4
//
//
// Example 2:
//
//
// Input: [0,1]
// Output: 0
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //我们知道不断地进行x=x&x-1得到的是x里1的个数
    //假设x中有8个1，那么问题就变成了，我们愿意执行8次位与，还是直接拿到结果，得到8，然后跳过8个数。
    //我们注意到，如果出现2**n，结果为0，比如8&7，结果是0，所以这些数必定在2**n-1和2**n之间,左开右闭//也就说说在m+1~n之间不可以出现2的次方
    int rangeBitwiseAnd(int m, int n)
    {
        if(m==n) return m;
        if(pow(2,(int)log2(n))==n) return 0;
        int left=log2(m+1);
        int right=log2(n);
        if(right-left>0) 
            return 0;
        int result=m;
        for(long long j=m+1;j<=n;j++)
        {
            result=result&j;
        }
        
        return result;
    }
};
