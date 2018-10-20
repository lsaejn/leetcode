// Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
//
// However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle. 
//
// You need to return the least number of intervals the CPU will take to finish all the given tasks.
//
// Example 1:
//
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
//
//
//
// Note:
//
// The number of tasks is in the range [1, 10000].
// The integer n is in the range [0, 100].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //一直交替选择任务,有点像插空，出现最多的任务先放好位置，冷却时间再放其他的任务，因为出现最多的任务决定了最短时间
    //然后加上多出来的部分 CEACE-CE ，最右边的部分长度就是和C一样长的字母的个数
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> cnt(26, 0);
        for (char task : tasks) 
            ++cnt[task - 'A'];
        sort(cnt.begin(), cnt.end());
        int mx = cnt[25];
        int i=0;
        for(;i!=cnt.size();++i)
        {
            if(cnt[i]==mx) break;
        }
        return max(static_cast<int>(tasks.size()),(mx-1)*(n+1)+26-i);
    }
};
