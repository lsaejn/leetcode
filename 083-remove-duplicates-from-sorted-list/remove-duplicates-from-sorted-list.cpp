// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
// Example 1:
//
//
// Input: 1->1->2
// Output: 1->2
//
//
// Example 2:
//
//
// Input: 1->1->2->3->3
// Output: 1->2->3
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//下一个元素相同，则删除即可
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto h=head;
        while(h)
        {
            if(h->next==nullptr)
               break;
            if(h->next->val==h->val)
            {
                auto temp=h->next->next;
                delete h->next;
                h->next=temp;
            } 
            else
            {
                h=h->next;
            }
        }
        return head;
    }
};
