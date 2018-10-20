// You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.
//
// Note: You can assume that
//
//
// 	0 <= amount <= 5000
// 	1 <= coin <= 5000
// 	the number of coins is less than 500
// 	the answer is guaranteed to fit into signed 32-bit integer
//
//
//  
//
// Example 1:
//
//
// Input: amount = 5, coins = [1, 2, 5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
//
//
//  
//
// Example 2:
//
//
// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
//
//
//  
//
// Example 3:
//
//
// Input: amount = 10, coins = [10] 
// Output: 1
//
//
//  
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int change(int amount, vector<int>& coins){
        vector<int> dpt(amount+1,0);
        dpt[0]=1;//base case
        for(auto c:coins){
            for(int a=c;a<=amount;a++){
                dpt[a]+=dpt[a-c];    
            }
        }
        return dpt[amount];
    }   
};
