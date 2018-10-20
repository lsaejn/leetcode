// Write a program to check whether a given number is an ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
// Example 1:
//
//
// Input: 6
// Output: true
// Explanation: 6 = 2 × 3
//
// Example 2:
//
//
// Input: 8
// Output: true
// Explanation: 8 = 2 × 2 × 2
//
//
// Example 3:
//
//
// Input: 14
// Output: false 
// Explanation: 14 is not ugly since it includes another prime factor 7.
//
//
// Note:
//
//
// 	1 is typically treated as an ugly number.
// 	Input is within the 32-bit signed integer range: [−231,  231 − 1].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isUgly(int num) {
            while (num >= 2) {
            if (num % 2 == 0) num /= 2;
            else if (num % 3 == 0) num /= 3;
            else if (num % 5 == 0) num /= 5;
            else return false;
        }
        return num == 1;
    }
};
