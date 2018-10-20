// Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.
// You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.  You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)
// Return the maximum profit you can make.
//
// Example 1:
//
// Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// Buying at prices[0] = 1Selling at prices[3] = 8Buying at prices[4] = 4Selling at prices[5] = 9The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
//
//
//
// Note:
// 0 < prices.length <= 50000.
// 0 < prices[i] < 50000.
// 0 <= fee < 50000.
//


class Solution {
public:
    /*
难度在于建模，sold[i]表示第i天卖掉股票的最大利润，hold[i]表示第i天保留手里的股票此时的最大利润
最开始我们可以选择买和不买。持有1时，利润是-1，不持有(或者当成是卖掉)，是0
到了8，s=5,h=-1
再到4，s=5,h=
    */
    int maxProfit(vector<int>& prices, int fee) {
        int sold = 0, hold = -prices[0];
        for (int price : prices) {
            int t = sold;
            sold = max(sold, hold + price - fee);//盈利则卖掉
            hold = max(hold, t - price);//亏本则不卖
        }
        return sold;
    }
};
