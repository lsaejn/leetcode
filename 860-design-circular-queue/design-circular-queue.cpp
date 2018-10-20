// Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called ‘Ring Buffer’.
// One of the Benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we can not insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.
// Your implementation should support following operations:
//
//
// 	MyCircularQueue(k): Constructor, set the size of the queue to be k.
// 	Front: Get the front item from the queue. If the queue is empty, return -1.
// 	Rear: Get the last item from the queue. If the queue is empty, return -1.
// 	enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
// 	deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
// 	isEmpty(): Checks whether the circular queue is empty or not.
// 	isFull(): Checks whether the circular queue is full or not.
//
//
// Example:
//
//
// MyCircularQueue circularQueue = new MycircularQueue(3); // set the size to be 3
//
// circularQueue.enQueue(1);  // return true
//
// circularQueue.enQueue(2);  // return true
//
// circularQueue.enQueue(3);  // return true
//
// circularQueue.enQueue(4);  // return false, the queue is full
//
// circularQueue.Rear();  // return 3
//
// circularQueue.isFull();  // return true
//
// circularQueue.deQueue();  // return true
//
// circularQueue.enQueue(4);  // return true
//
// circularQueue.Rear();  // return 4
//  
//  
//
// Note:
//
//
// 	All values will be in the range of [1, 1000].
// 	The number of operations will be in the range of [1, 1000].
// 	Please do not use the built-in Queue library.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        max=k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        col.push_back(value);
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        col.pop_front();
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return col.front();
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return col.back();
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return col.size()==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return col.size()>=max;
    }
    deque<int> col;
    int max;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
