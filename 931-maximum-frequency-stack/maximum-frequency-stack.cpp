// Implement FreqStack, a class which simulates the operation of a stack-like data structure.
//
// FreqStack has two functions:
//
//
// 	push(int x), which pushes an integer x onto the stack.
// 	pop(), which removes and returns the most frequent element in the stack.
//
// 		If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
//
//
//
//
//  
//
// Example 1:
//
//
// Input: 
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
// [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
// Output: [null,null,null,null,null,null,null,5,7,5,4]
// Explanation:
// After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:
//
// pop() -> returns 5, as 5 is the most frequent.
// The stack becomes [5,7,5,7,4].
//
// pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
// The stack becomes [5,7,5,4].
//
// pop() -> returns 5.
// The stack becomes [5,7,4].
//
// pop() -> returns 4.
// The stack becomes [5,7].
//
//
//  
//
// Note:
//
//
// 	Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
// 	It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
// 	The total number of FreqStack.push calls will not exceed 10000 in a single test case.
// 	The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
// 	The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
//
//
//
//  
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class FreqStack {
public:
    FreqStack() {
        
    }
    /*Hash map freq will count the frequence of elements.
Hash map m is a map of stack.
If element x has n frequence, we will push x n times in m[1], m[2] .. m[n]
maxfreq records the maximum frequence.
*/
    unordered_map<int, int> freq;//元素，次数
    unordered_map<int, stack<int>> m;//次数，元素栈
    int maxfreq = 0;

    void push(int x) {
        maxfreq = max(maxfreq, ++freq[x]);
        m[freq[x]].push(x);
    }

    int pop() {
        int x = m[maxfreq].top();
        m[maxfreq].pop();
        if (!m[freq[x]--].size()) 
            maxfreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
