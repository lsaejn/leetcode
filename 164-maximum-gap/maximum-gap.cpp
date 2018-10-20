// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
// Return 0 if the array contains less than 2 elements.
//
// Example 1:
//
//
// Input: [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either
//              (3,6) or (6,9) has the maximum difference 3.
//
// Example 2:
//
//
// Input: [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
//
// Note:
//
//
// 	You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// 	Try to solve it in linear time/space.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //用桶排序，达到了惊人的简练
    int maximumGap(vector<int> &numss) {
        if (numss.empty()) return 0;
        int mx = INT_MIN, mn = INT_MAX, n = numss.size();
        for (int d : numss) 
        {
            mx = max(mx, d);
            mn = min(mn, d);
        }
        int size = (mx - mn) / n + 1;
        int bucket_nums = (mx - mn) / size + 1;
        vector<int> bucket_min(bucket_nums, INT_MAX);
        vector<int> bucket_max(bucket_nums, INT_MIN);
        set<int> s;
        for (int d : numss)
        {
            int idx = (d - mn) / size;
            bucket_min[idx] = min(bucket_min[idx], d);
            bucket_max[idx] = max(bucket_max[idx], d);
            s.insert(idx);
        }
        int pre = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            if (!s.count(i)) continue;
            res = max(res, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return res;
    }
};
