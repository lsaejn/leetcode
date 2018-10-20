// Let's call an array A a mountain if the following properties hold:
//
//
// 	A.length >= 3
// 	There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
//
//
// Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
//
// Example 1:
//
//
// Input: [0,1,0]
// Output: 1
//
//
//
// Example 2:
//
//
// Input: [0,2,1,0]
// Output: 1
//
//
// Note:
//
//
// 	3 <= A.length <= 10000
// 	0 <= A[i] <= 10^6
// 	A is a mountain, as defined above.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for(int i=1;i!=A.size();++i)
            if(A[i]<A[i-1])
                return i-1;
    }
};
