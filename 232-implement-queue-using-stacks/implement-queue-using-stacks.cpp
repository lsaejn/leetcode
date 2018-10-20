// Implement the following operations of a queue using stacks.
//
//
// 	push(x) -- Push element x to the back of queue.
// 	pop() -- Removes the element from in front of queue.
// 	peek() -- Get the front element.
// 	empty() -- Return whether the queue is empty.
//
//
// Example:
//
//
// MyQueue queue = new MyQueue();
//
// queue.push(1);
// queue.push(2);  
// queue.peek();  // returns 1
// queue.pop();   // returns 1
// queue.empty(); // returns false
//
// Notes:
//
//
// 	You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
// 	Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
// 	You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
         _new.push(x);//放到入栈
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
               shiftStack();
        if (!_old.empty()) 
        {
            auto x=_old.top();
            _old.pop();
            return x;
        } 
    }
    
    /** Get the front element. */
    int peek() {
               shiftStack();
        if (!_old.empty()) return _old.top();
        return 0; 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _old.empty() && _new.empty();
    }
    

private:
    stack<int> _old, _new;
    
    void shiftStack() {//如果出栈为空，那么入栈全压到出栈
        if (_old.empty()) {//从api的角度来看，应该放在这里吗？
            while (!_new.empty()) {
                _old.push(_new.top());
                _new.pop();
            }
        }
    }
};



/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
