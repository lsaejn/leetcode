// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 
//
// Note:
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).
//
//
// Example 1:
//
// Input:
// 3
//
// Output:
// 3
//
//
//
// Example 2:
//
// Input:
// 11
//
// Output:
// 0
//
// Explanation:
// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int findNthDigit(int n) {
        //1-9表示9个数  1-9
        //10-99 表示 90*2个数 9+1~9+180
        //100-999 900*3 9+180+1 ~9+180+2700
        long long len = 1, cnt = 9, start = 1;
        while (n > len * cnt)
        {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len;//n此时代表区间里的第i个
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
};
//14=9 10 11 12 13 14 15 16 17 18 19 20 21
