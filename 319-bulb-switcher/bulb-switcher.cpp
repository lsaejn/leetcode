// There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.
//
// Example:
//
//
// Input: 3
// Output: 1 
// Explanation: 
// At first, the three bulbs are [off, off, off].
// After first round, the three bulbs are [on, on, on].
// After second round, the three bulbs are [on, off, on].
// After third round, the three bulbs are [on, off, off]. 
//
// So you should return 1, because there is only one bulb is on.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //假设有9个灯泡，第一个灯泡被1整除，所以变化1次
    //第2个，被1，2整除，变化2次
    //第6个，1，2，3，6各一次
    //第8个灯泡，1，2一次，4一次
    int bulbSwitch(int n) 
    {
        int res = 1;
        while (res * res <= n) 
            ++res;
        return res - 1;
    }
};
