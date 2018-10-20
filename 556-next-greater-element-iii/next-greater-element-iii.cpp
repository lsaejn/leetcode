// Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.
//
// Example 1:
//
//
// Input: 12
// Output: 21
//
//
//  
//
// Example 2:
//
//
// Input: 21
// Output: -1
//
//
//  
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int nextGreaterElement(int n) {
               string str = to_string(n);
        next_permutation(str.begin(), str.end());
        long long res = stoll(str);
        return (res > INT_MAX || res <= n) ? -1 : res; 
    }
};
