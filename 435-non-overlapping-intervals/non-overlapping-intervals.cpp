//
// Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
//
//
// Note:
//
// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
//
//
//
// Example 1:
//
// Input: [ [1,2], [2,3], [3,4], [1,3] ]
//
// Output: 1
//
// Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
//
//
//
// Example 2:
//
// Input: [ [1,2], [1,2], [1,2] ]
//
// Output: 2
//
// Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
//
//
//
// Example 3:
//
// Input: [ [1,2], [2,3] ]
//
// Output: 0
//
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2){ return i1.start < i2.start; };
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0, pre = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[pre].end)//重叠
            {
                res++;//重叠了肯定要删除，没有疑问的
                if (intervals[i].end < intervals[pre].end) //落在了内部，删掉更大那个
                    pre = i;
                //else do nothing？是的，出现交叉情况，显然删除后面的，保证第3个区间有机会和第1区间同时生存
            }
            else 
                pre = i;
        }
        return res;
    }
};
