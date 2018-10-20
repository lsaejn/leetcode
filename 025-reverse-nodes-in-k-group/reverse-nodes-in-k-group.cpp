// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//
//
//
// Example:
//
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
//
// Note:
//
//
// 	Only constant extra memory is allowed.
// 	You may not alter the values in the list's nodes, only nodes itself may be changed.
//
//


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        int count=k;
        auto probe=head;
        while(k--&&probe) 
            probe=probe->next;
        if(k>-1) return head;
        ListNode* newhead=nullptr;
        ListNode* newtail=nullptr;
        k=count;
        while(k--)
        {
            if(head)
            {
                auto copy=head->next;
                if(!newtail) newtail=head;
                head->next=newhead;                
                newhead=head;
                head=copy;
            }
            //else return head;
        }
        newtail->next=reverseKGroup(head,count);
        return newhead;
        
    }
};
