// Write an iterator that iterates through a run-length encoded sequence.
//
// The iterator is initialized by RLEIterator(int[] A), where A is a run-length encoding of some sequence.  More specifically, for all even i, A[i] tells us the number of times that the non-negative integer value A[i+1] is repeated in the sequence.
//
// The iterator supports one function: next(int n), which exhausts the next n elements (n >= 1) and returns the last element exhausted in this way.  If there is no element left to exhaust, next returns -1 instead.
//
// For example, we start with A = [3,8,0,9,2,5], which is a run-length encoding of the sequence [8,8,8,5,5].  This is because the sequence can be read as "three eights, zero nines, two fives".
//
//  
//
// Example 1:
//
//
// Input: ["RLEIterator","next","next","next","next"], [[[3,8,0,9,2,5]],[2],[1],[1],[2]]
// Output: [null,8,8,5,-1]
// Explanation: 
// RLEIterator is initialized with RLEIterator([3,8,0,9,2,5]).
// This maps to the sequence [8,8,8,5,5].
// RLEIterator.next is then called 4 times:
//
// .next(2) exhausts 2 terms of the sequence, returning 8.  The remaining sequence is now [8, 5, 5].
//
// .next(1) exhausts 1 term of the sequence, returning 8.  The remaining sequence is now [5, 5].
//
// .next(1) exhausts 1 term of the sequence, returning 5.  The remaining sequence is now [5].
//
// .next(2) exhausts 2 terms, returning -1.  This is because the first term exhausted was 5,
// but the second term did not exist.  Since the last term exhausted does not exist, we return -1.
//
//
//
// Note:
//
//
// 	0 <= A.length <= 1000
// 	A.length is an even integer.
// 	0 <= A[i] <= 10^9
// 	There are at most 1000 calls to RLEIterator.next(int n) per test case.
// 	Each call to RLEIterator.next(int n) will have 1 <= n <= 10^9.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class RLEIterator {
public:
    //A = [3,8,0,9,2,5]
    RLEIterator(vector<int> A):V(move(A))
    {
    }
    
    int next(int n) 
    {
        while(cur_index < V.size())
        {
            if (n > V[cur_index])//不够，那么减掉次数，索引变成下一个元素的次数
            {
                n -= V[cur_index];
                cur_index += 2;
            } 
            else //n<=V[cur_index]足够，那么次数减掉，返回之
            {
                V[cur_index] -= n;
                return V[cur_index+1];
            }
        }
        return -1;
    }
    int cur_index=0;
    vector<int> V;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
