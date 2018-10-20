// We are given an array A of positive integers, and two positive integers L and R (L <= R).
//
// Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.
//
//
// Example :
// Input: 
// A = [2, 1, 4, 3]
// L = 2
// R = 3
// Output: 3
// Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
//
//
// Note:
//
//
// 	L, R  and A[i] will be an integer in the range [0, 10^9].
// 	The length of A will be in the range of [1, 50000].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int len = A.size();
        int ans = 0;
        int left = -1;//左界
        int right = -1;//最近合法位置
        for(int i=0; i<len; i++) {
            if(A[i] > R) {
                left = i;
                right = i;
            }
            else if(A[i]<L) {
                ans += (i-left)-(i-right);
            }
            else {
                ans += (i-left);
                right = i;
            }
        }
        return ans;
    }
};
