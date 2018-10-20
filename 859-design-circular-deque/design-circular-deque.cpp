// Design your implementation of the circular double-ended queue (deque).
// Your implementation should support following operations:
//
//
// 	MyCircularDeque(k): Constructor, set the size of the deque to be k.
// 	insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
// 	insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
// 	deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
// 	deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
// 	getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
// 	getRear(): Gets the last item from Deque. If the deque is empty, return -1.
// 	isEmpty(): Checks whether Deque is empty or not. 
// 	isFull(): Checks whether Deque is full or not.
//
//
// Example:
//
//
// MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
// circularDeque.insertLast(1);			// return true
// circularDeque.insertLast(2);			// return true
// circularDeque.insertFront(3);			// return true
// circularDeque.insertFront(4);			// return false, the queue is full
// circularDeque.getRear();  				// return 32
// circularDeque.isFull();				// return true
// circularDeque.deleteLast();			// return true
// circularDeque.insertFront(4);			// return true
// circularDeque.getFront();				// return 4
//  
//  
//
// Note:
//
//
// 	All values will be in the range of [1, 1000].
// 	The number of operations will be in the range of [1, 1000].
// 	Please do not use the built-in Deque library.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        max=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(col.size()==max) return false;
        col.push_front(value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(col.size()==max) return false;
        col.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        
        if(col.empty()) return false;
        col.pop_front();
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(col.empty()) return false;
        col.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(col.empty()) return -1;
        return col.front();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(col.empty()) return -1;
        return col.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return col.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return col.size()==max;
    }
    deque<int> col;
    int max;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
