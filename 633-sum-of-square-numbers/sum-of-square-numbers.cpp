//
// Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
//
//
// Example 1:
//
// Input: 5
// Output: True
// Explanation: 1 * 1 + 2 * 2 = 5
//
//
//
//
// Example 2:
//
// Input: 3
// Output: False
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这是我认为比较自然的想法，c=17 c**1/2=4 c-c**1/2=1,1可以开方，true
    //再找测试用例25 可以直接开方
    //32呢？ 32开方=5 d=7 d开方2 2**2！=7所以false。太精妙了。。。我反正想不到
    bool judgeSquareSum(int c) {
        for (int i = sqrt(c); i >= 0; --i) {
            if (i * i == c) return true;
            int d = c - i * i, t = sqrt(d);
            if (t * t == d) return true;
        }
        return false;
    }
};
