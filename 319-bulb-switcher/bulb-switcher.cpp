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
//


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
