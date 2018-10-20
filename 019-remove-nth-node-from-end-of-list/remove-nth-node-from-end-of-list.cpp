// Given a linked list, remove the n-th node from the end of list and return its head.
//
// Example:
//
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//
// Note:
//
// Given n will always be valid.
//
// Follow up:
//
// Could you do this in one pass?
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
    //如果要遍历一次，必须快慢指针，而n始终有效，我们可以大胆地遍历
    //要删除倒数第n个指针，我们要遍历到倒数第n-1个指针
    //一个遍历了length 一个遍历了length-n
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto h=head;
        while(n>0)
        {
            h=h->next;
            n--;
        }
        if(!h) return head->next;
        auto slow=head;
        while(h&&h->next)//移动n次之后，自己可能在tail，或者下一个是tail
        {
            h=h->next;
            slow=slow->next;
        }
        auto temp=slow->next->next;//我们没有删除那个结点，因为。。。
        slow->next=temp;
        return head;
        
    }
};
