// Reverse a singly linked list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
//
// Follow up:
//
// A linked list can be reversed either iteratively or recursively. Could you implement both?
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//1->2->3
//null
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!(head&&head->next))
           return head;
        ListNode* newHead=nullptr;
        while(head)
        {
            ListNode* temp=head;
            head=head->next;
            temp->next=newHead;
            newHead=temp;
        }
           return newHead;
        
    }
};
