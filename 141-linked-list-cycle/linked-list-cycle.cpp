//
// Given a linked list, determine if it has a cycle in it.
//
//
//
// Follow up:
// Can you solve it without using extra space?
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//本题只是说有环，没有说是循环链表，环可以在后面
public:
        bool hasCycle(ListNode *head) //陷入了思维陷阱，你怎么可能想到用快慢指针呢。。。
        {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
//12345
//1 3 5 1 3 5 1 3 5 1 3 5 1 3 5 1 3 5   
//1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3
