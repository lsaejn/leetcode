// Remove all elements from a linked list of integers that have value val.
//
// Example:
//
//
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head) return nullptr;
        while(head&&head->val==val)
            head=head->next;
        auto h=head;
        while(h)
        {
            if(!h->next)
                break;
            if(h->next->val!=val)
            {
                h=h->next;
               continue; 
            }
                
            if(h->next->val==val)
            {
                auto temp=h->next->next;
                //delete h->next;
                h->next=temp;
            }            
        }
        return head;
        
    }
};
