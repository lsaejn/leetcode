// Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.
//
// If there aren't two consecutive 1's, return 0.
//
//  
//
//
//
//
//
//
//
//
//
//
//
// Example 1:
//
//
// Input: 22
// Output: 2
// Explanation: 
// 22 in binary is 0b10110.
// In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
// The first consecutive pair of 1's have distance 2.
// The second consecutive pair of 1's have distance 1.
// The answer is the largest of these two distances, which is 2.
//
//
//
// Example 2:
//
//
// Input: 5
// Output: 2
// Explanation: 
// 5 in binary is 0b101.
//
//
//
// Example 3:
//
//
// Input: 6
// Output: 1
// Explanation: 
// 6 in binary is 0b110.
//
//
//
// Example 4:
//
//
// Input: 8
// Output: 0
// Explanation: 
// 8 in binary is 0b1000.
// There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.
//
//
//  
//
//
//
//
// Note:
//
//
// 	1 <= N <= 10^9
//
//
//
//
//
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int binaryGap(int N) {
        int last = -1, ans = 0;
        for (int i = 0; i < 32; ++i)
            if (((N >> i) & 1) > 0)//0b10110 
            {
                if (last >= 0)
                    ans = std::max(ans, i - last);
                last = i;
            }

        return ans;
    }
};
