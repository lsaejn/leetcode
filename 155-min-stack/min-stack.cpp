//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//
// push(x) -- Push element x onto stack.
//
//
// pop() -- Removes the element on top of the stack.
//
//
// top() -- Get the top element.
//
//
// getMin() -- Retrieve the minimum element in the stack.
//
//
//
//
// Example:
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class MinStack {
public:
    /** initialize your data structure here. */
    //保存一个变量保存最小值并不有效，因为最小值出栈后你无法得到次小值
    //显然准备一个排序后的容器是可行的，但是所以元素都保存了两份
    //但是看到另一个思路，两个栈，最小栈用来保存最小元素，例如push 6 8 5 3 1 9  913586 最小栈是  1356
    //这里很巧妙的是，不会出现次小值比最小值先出栈的情况。可以说是动态规划的思想
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()||x<=s2.top())//这里是小于等于
            s2.push(x);
        
    }
    
    void pop() {
        auto x=s1.top();
        s1.pop();
        if(x==s2.top())
            s2.pop();
        
    }
    
    int top() {
        return s1.top();       
    }
    
    int getMin() {
        return s2.top();
    }
    private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
