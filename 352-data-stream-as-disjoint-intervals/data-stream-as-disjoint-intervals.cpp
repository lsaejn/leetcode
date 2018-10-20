// Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
//
// For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
//
// [1, 1]
// [1, 1], [3, 3]
// [1, 1], [3, 3], [7, 7]
// [1, 3], [7, 7]
// [1, 3], [6, 7]
//
//
// Follow up:
// What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
//
//
// Credits:Special thanks to @yunhong for adding this problem and creating most of the test cases.


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {//就是不断生成新区间,1只能是1，1；3呢变成了1,1 3,3 然后是1,3,7 然后是 [1,3] 接着是[6,7]
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        Interval cur(val, val);
        vector<Interval> res;
        int pos = 0;
        for (auto a : v) 
        {
            if (cur.end + 1 < a.start) 
                res.push_back(a);
            else if (cur.start > a.end + 1)
            {
                res.push_back(a);
                ++pos;
            } 
            else 
            {
                cur.start = min(cur.start, a.start);
                cur.end = max(cur.end, a.end);
            }
        }
        res.insert(res.begin() + pos, cur);
        v = res;
    }
    
    vector<Interval> getIntervals() {
        return v;    
    }
    
private:
    vector<Interval> v;//区间的集合
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
