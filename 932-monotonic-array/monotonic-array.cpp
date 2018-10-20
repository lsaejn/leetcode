// An array is monotonic if it is either monotone increasing or monotone decreasing.
//
// An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
//
// Return true if and only if the given array A is monotonic.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: [1,2,2,3]
// Output: true
//
//
//
// Example 2:
//
//
// Input: [6,5,4,4]
// Output: true
//
//
//
// Example 3:
//
//
// Input: [1,3,2]
// Output: false
//
//
//
// Example 4:
//
//
// Input: [1,2,4,5]
// Output: true
//
//
//
// Example 5:
//
//
// Input: [1,1,1]
// Output: true
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 50000
// 	-100000 <= A[i] <= 100000
//
//
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isMonotonic(vector<int>& digits) {
        return std::is_sorted(std::begin(digits), std::end(digits)) || std::is_sorted(std::rbegin(digits), std::rend(digits));
    }
};
