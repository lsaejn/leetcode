// There are two types of soup: type A and type B. Initially we have N ml of each type of soup. There are four kinds of operations:
//
//
// 	Serve 100 ml of soup A and 0 ml of soup B
// 	Serve 75 ml of soup A and 25 ml of soup B
// 	Serve 50 ml of soup A and 50 ml of soup B
// 	Serve 25 ml of soup A and 75 ml of soup B
//
//
// When we serve some soup, we give it to someone and we no longer have it.  Each turn, we will choose from the four operations with equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as we can.  We stop once we no longer have some quantity of both types of soup.
//
// Note that we do not have the operation where all 100 ml's of soup B are used first.  
//
// Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time.
//
//  
//
//
// Example:
// Input: N = 50
// Output: 0.625
// Explanation: 
// If we choose the first two operations, A will become empty first. For the third operation, A and B will become empty at the same time. For the fourth operation, B will become empty first. So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.
//
//
//
// Notes: 
//
//
// 	0 <= N <= 10^9. 
// 	Answers within 10^-6 of the true value will be accepted as correct.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //leetcode刷多了之后，你对dfs的信心会越来越低，因为除非你不得不这样做，否则它
    //一般都会以超时告终
    //这道题是典型的一看就是数学题。
    //思路:正向模拟需要dfs，但是N=10**9,没希望
    //反向呢？相当于递归
    //没办法，为了速度，用dp
    //dp[N][N]?太吓人了,内存爆了
    //100，100->{{0,100},{25,75},{50,50},{75,25}};
    //这么想，给你堆
    double memo[200][200];
    double soupServings(int N) {
        return N >= 4800 ?  1.0 : f((N + 24) / 25, (N + 24) / 25);
    }
    double f(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (memo[a][b] > 0) return memo[a][b];
        memo[a][b] = 0.25 * (f(a-4,b)+f(a-3,b-1)+f(a-2,b-2)+f(a-1,b-3));
        return memo[a][b];
    }
};
