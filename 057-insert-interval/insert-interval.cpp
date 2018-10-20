// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
//
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
//
// Example 2:
//
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		//我们先找到第一个起点大于新区间起点的端点，然后判断前面一个区间是不是和新区间有重叠。
		//如果是，前面一个需要合并。
		//然后向后移动，直到起点>=新区间终点
        if(intervals.empty()) return {newInterval};
        if(newInterval.end<intervals.begin()->start)
        {
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        if(newInterval.start>intervals.back().end)
        {
            intervals.push_back(newInterval);
			return intervals; 
        }
		auto iter = intervals.begin();
		for (; iter != intervals.end(); ++iter)
			if (iter->end>= newInterval.start)  break;
		auto start = iter;
        auto end = start;
		for (; end != intervals.end(); ++end)
			if (end->start>newInterval.end) break;		
		int first = min(start->start,newInterval.start);
		int second =max( (end - 1)->end, newInterval.end);
		auto begin = start - intervals.begin();
		intervals.erase(start, end);
		intervals.insert(intervals.begin()+begin, { first,second });
		return intervals;
	}
    
        vector<Interval> insert1(vector<Interval>& intervals, Interval newInterval) {
        auto compare = [] (const Interval &intv1, const Interval &intv2)
                          { return intv1.end < intv2.start; };
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);//找到i1.end>=new.start i2.end>new.start
        auto itr1 = range.first, itr2 = range.second;
        if (itr1 == itr2) {
            intervals.insert(itr1, newInterval);
        } else {
            itr2--;//我们修改最后一个元素的区间
            itr2->start = min(newInterval.start, itr1->start);
            itr2->end = max(newInterval.end, itr2->end);
            intervals.erase(itr1, itr2);
        }
        return intervals;
    }
};
