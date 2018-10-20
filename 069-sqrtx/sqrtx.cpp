// Implement int sqrt(int x).
//
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
//
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
// Example 1:
//
//
// Input: 4
// Output: 2
//
//
// Example 2:
//
//
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int mySqrt(int x) {
        //对半肯定不是最快的，但是题目也要求，那就凑合写了
        if(x==0) return 0;
        if(x==1) return 1;
        long num=x;
        long long begin=0;
        long long end=x;
        while(begin<end){
            long long mid=(end+begin)/2;//这里越界，弄了半天
            if(mid*mid==x) return mid;
            if(mid*mid>x)
            {
                end=mid;
            }
            else
            {
                begin=mid;
            } 
            if(begin+1==end)
                return begin;
        }
        return begin;
        
    }
};
