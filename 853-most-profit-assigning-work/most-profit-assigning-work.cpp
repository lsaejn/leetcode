// We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job. 
//
// Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i]. 
//
// Every worker can be assigned at most one job, but one job can be completed multiple times.
//
// For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.
//
// What is the most profit we can make?
//
// Example 1:
//
//
// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100 
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperately.
//
// Notes:
//
//
// 	1 <= difficulty.length = profit.length <= 10000
// 	1 <= worker.length <= 10000
// 	difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        int N = profit.size(), res = 0, i = 0, maxp = 0;
        for (int j = 0; j < N; ++j) 
            jobs.push_back(make_pair(difficulty[j], profit[j]));
        sort(jobs.begin(), jobs.end());//排序之后，我们更新i变得非常方便 
        sort(worker.begin(), worker.end());
        for (int & ability: worker) 
        {
            while (i < N && ability >= jobs[i].first) 
                maxp = max(jobs[i++].second, maxp);
            res += maxp;
        }
        return res;
    }
};