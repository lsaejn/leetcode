// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//
// Given linked list -- head = [4,5,1,9], which looks like following:
//
//
//     4 -> 5 -> 1 -> 9
//
//
// Example 1:
//
//
// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list
//              should become 4 -> 1 -> 9 after calling your function.
//
//
// Example 2:
//
//
// Input: head = [4,5,1,9], node = 1
// Output: [4,5,9]
// Explanation: You are given the third node with value 1, the linked list
//              should become 4 -> 5 -> 9 after calling your function.
//
//
// Note:
//
//
// 	The linked list will have at least two elements.
// 	All of the nodes' values will be unique.
// 	The given node will not be the tail and it will always be a valid node of the linked list.
// 	Do not return anything from your function.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //这是不可能做到的，唯一的办法就是交换值
        if(!node->next) cout<<"should not happen";
        node->val=node->next->val;
        auto temp=node->next;
        node->next=temp->next;
        delete temp;
    }
        
};