// Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.
//
// If there is no non-empty subarray with sum at least K, return -1.
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
// Input: A = [1], K = 1
// Output: 1
//
//
//
// Example 2:
//
//
// Input: A = [1,2], K = 4
// Output: -1
//
//
//
// Example 3:
//
//
// Input: A = [2,-1,2], K = 3
// Output: 3
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 50000
// 	-10 ^ 5 <= A[i] <= 10 ^ 5
// 	1 <= K <= 10 ^ 9
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这个看作者注释可能看不懂，但道理很简单。固定B[i]
    //删除队列尾部时我们希望B[back]越小越好，这意味着前面back项的和更小，i-back中的元素和更大
    //靠后的元素反而右更大的元素和，意味着如果出现答案，他更加短
    //画个图就明白了。对于当前B[i],我们希望B[j]越小越好，最极端的情况就是B[i]-B[i-1]=A[i-1]
    //如果这个元素直接大于等于K，我们立刻得出答案
    int shortestSubarray(vector<int> A, int K) {
        int N = A.size(), res = N + 1;
        vector<int> B(N + 1, 0);
        for (int i = 0; i < N; i++) B[i + 1] = B[i] + A[i];
        deque<int> d;
        for (int i = 0; i < N + 1; i++) {
            while (d.size() > 0 && B[i] - B[d.front()] >= K)
                res = min(res, i - d.front()), d.pop_front();
            while (d.size() > 0 && B[i] <= B[d.back()]) d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
};
