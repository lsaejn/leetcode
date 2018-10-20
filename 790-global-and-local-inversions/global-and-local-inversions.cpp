// We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.
//
// The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].
//
// The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].
//
// Return true if and only if the number of global inversions is equal to the number of local inversions.
//
// Example 1:
//
//
// Input: A = [1,0,2]
// Output: true
// Explanation: There is 1 global inversion, and 1 local inversion.
//
//
// Example 2:
//
//
// Input: A = [1,2,0]
// Output: false
// Explanation: There are 2 global inversions, and 1 local inversion.
//
//
// Note:
//
//
// 	A will be a permutation of [0, 1, ..., A.length - 1].
// 	A will have length in range [1, 5000].
// 	The time limit for this problem has been reduced.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    /*
     01234 0/0
     10234 1/1
     21034 3/2
     10243 2/2
    只有和身边的交换一次才相等
    */
    bool isIdealPermutation(vector<int>& A) 
    {
	for (int i = 0; i < A.size(); ++i) 
    {
            if (abs(A[i] - i) > 1) 
                return false;
        }
	return true;
    }
};
