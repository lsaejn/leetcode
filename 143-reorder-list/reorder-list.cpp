// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example 1:
//
//
// Given 1->2->3->4, reorder it to 1->4->2->3.
//
// Example 2:
//
//
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    
    //0 1 2 3 4 5 6->0 6 1 5 2 4 3
    //我们只要知道后3个结点地址就行了，先逆序。再分别插入前面，直到容器为空，或者链表到尾
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto temp=slow->next;
        
        slow->next=nullptr;
        ListNode* new_head=nullptr;
        while(temp)
        {
            auto t=temp->next;
            temp->next=new_head;
            new_head=temp;
            temp=t;
        }

        auto h=head;
        while(h->next&&new_head)
        {
            auto temp=new_head->next;
            new_head->next=h->next;
            h->next=new_head;
            h=h->next->next;
            new_head=temp;
        } 
        if(new_head)
            h->next=new_head;
    }
};
