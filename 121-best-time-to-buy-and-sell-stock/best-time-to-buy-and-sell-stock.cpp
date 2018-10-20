// Say you have an array for which the ith element is the price of a given stock on day i.
//
// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
// Note that you cannot sell a stock before you buy one.
//
// Example 1:
//
//
// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger than buying price.
//
//
// Example 2:
//
//
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //如果挨个遍历，复杂度n**2
        //如果排序呢？nlogn 排序之后找到最大值最小值是1，搜索是n，看起来好像有所提高
        //再换个思路，假设可以以O1完成任务，那么我们需要保存什么？基于经验，我们应该保存1.左边的最大价值，2左边的最低价格
        //ok，2应该可以
        int minValue=INT32_MAX;
        int maxProfit=0;
        for(int i=0;i!=prices.size();++i)
        {
            if(prices[i]<minValue)
                minValue=prices[i];
            else
            {
                int Profit=prices[i]-minValue;
                if(Profit>maxProfit)
                    maxProfit=Profit;
            }
        }
        return maxProfit;
    }
};
