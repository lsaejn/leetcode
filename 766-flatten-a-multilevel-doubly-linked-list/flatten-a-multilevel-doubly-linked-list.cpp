// You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.
//
// Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.
//
// Example:
//
//
// Input:
//  1---2---3---4---5---6--NULL
//          |
//          7---8---9---10--NULL
//              |
//              11--12--NULL
//
// Output:
// 1-2-3-7-8-11-12-9-10-4-5-6-NULL
//
//
// Explanation for the above example:
//
// Given the following multilevel doubly linked list:
//
//
//
// We should return the following flattened doubly linked list:
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* getTail(Node* head) { /* 获取尾节点 */
        Node* now = head;
        while (now->next) {
            now = now->next;
        }
        return now;
    }
    
    Node* flatten(Node* head) {
        Node* now = head;
        while (now) {
            if (now->child) {
                Node* subHead = flatten(now->child); /* 递归获取展开后的子序列的头节点 */
                Node* subTail = getTail(subHead); /* 获取子序列的尾节点 */
                Node* nowNext = now->next;
                now->child = nullptr; /* 断开儿子节点 */
                /* 将当前节点与子序列的头部进行链接 */
                now->next = subHead; 
                subHead->prev = now;
                /* 若当前节点存在后驱，则要将当前节点的后驱与子序列的尾部链接 */
                if (nowNext) { 
                    nowNext->prev = subTail;
                    subTail->next = nowNext;
                }
            }
            now = now->next;
        }
        return head;
    }
};
