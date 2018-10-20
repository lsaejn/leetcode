// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
//
// Example 2:
//
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
//


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
    //结构体不是我们定义的，所以没办法写到内部里面。通常都是写operator< 再写一个全局函数
        static bool comp(const Interval &a, const Interval &b)
        {
            return (a.start < b.start);
        }
        
    vector<Interval> merge(vector<Interval> &intervals) 
    {
        vector<Interval> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), comp);//排序[1,3],[2,6],[8,10],[15,18],
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) 
        {
            if (res.back().end >= intervals[i].start) //有交集
                res.back().end = max(res.back().end, intervals[i].end);//找到共同结尾
            else  res.push_back(intervals[i]);
        }
        return res;
    }
};
