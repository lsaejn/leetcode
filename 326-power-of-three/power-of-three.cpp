// Given an integer, write a function to determine if it is a power of three.
//
// Example 1:
//
//
// Input: 27
// Output: true
//
//
// Example 2:
//
//
// Input: 0
// Output: false
//
// Example 3:
//
//
// Input: 9
// Output: true
//
// Example 4:
//
//
// Input: 45
// Output: false
//
// Follow up:
// Could you do it without using any loop / recursion?
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isPowerOfThree(int n) {
    //是不是3的幂，不断除以3即
    //a - int(a) == 0,函数库里的log是查表
    return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
               
    }
};
