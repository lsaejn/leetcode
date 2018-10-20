// Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.
//
// Since the answer may be large, return the answer modulo 10^9 + 7.
//
//  
//
// Example 1:
//
//
// Input: [3,1,2,4]
// Output: 17
// Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 30000
// 	1 <= A[i] <= 30000
//
//
//
//  
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


#define MOD 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        set<int> s;
        s.insert(-1);
        s.insert(A.size());
        long long ans = 0;
        vector<pair<int,int>> v;
        for (int i = 0; i < A.size(); i++)
            v.push_back({A[i], i});
        sort(v.begin(), v.end());
        for (auto p : v) {
            auto it = s.insert(p.second).first;
            it--;
            long long ia = p.second - *it;
            it++;
            it++;
            long long ib = *it - p.second;
            ans =(ans + ia * ib % MOD * p.first) % MOD;
        }
        return ans;
    }
};
