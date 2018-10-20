// Alice plays the following game, loosely based on the card game "21".
//
// Alice starts with 0 points, and draws numbers while she has less than K points.  During each draw, she gains an integer number of points randomly from the range [1, W], where W is an integer.  Each draw is independent and the outcomes have equal probabilities.
//
// Alice stops drawing numbers when she gets K or more points.  What is the probability that she has N or less points?
//
// Example 1:
//
//
// Input: N = 10, K = 1, W = 10
// Output: 1.00000
// Explanation:  Alice gets a single card, then stops.
//
//
// Example 2:
//
//
// Input: N = 6, K = 1, W = 10
// Output: 0.60000
// Explanation:  Alice gets a single card, then stops.
// In 6 out of W = 10 possibilities, she is at or below N = 6 points.
//
//
// Example 3:
//
//
// Input: N = 21, K = 17, W = 10
// Output: 0.73278
//
// Note:
//
//
// 	0 <= K <= N <= 10000
// 	1 <= W <= 10000
// 	Answers will be accepted as correct if they are within 10^-5 of the correct answer.
// 	The judging time limit has been reduced for this question.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //显然可以用dfs,但是效率可能堪忧，因为K太大了
    //用dp，又想不出来
    double new21Game(int N, int K, int W) {
        vector<double> p(K+W+1);
        double s=0.0;
        for(int i=K;i<K+W;i++) //走完最后一步之后，最多可能获得(K-1)+W，最少可能是K分。即倒数第一步时的分数[K-W,K-1-W]
            p[i]=1.0*(i<=N),s+=p[i];//求出其中<=N的概率，比如例子3，17,18,19,20,21,最后的概率都是1，因为它们都>=17,<=21，得到s=5.0,[17,27）的概率
        for(int i=K-1;i>=0;i--)//开始倒推，依次给可能出现的数字加上自己对其影响的概率，比如17和21都可能影响16，它们都有0.1的概率从16得到，
        {
            p[i]=s/W;//p[i]=0.5,
            s+=p[i]-p[i+W];//出现16的概率，但是要减掉出现26的概率，获得s，即出现[16，26）
        }
        return p[0];//现在，这就是最初的概率
    }
};
