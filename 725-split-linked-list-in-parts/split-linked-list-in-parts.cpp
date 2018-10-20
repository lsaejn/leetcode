// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the two partitions.
//
// Example:
//
//
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5
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
    //1->4->3->2->5->2
    //1->2->3->4->5->2
    //1->2->2->4->5->3
    //想保持顺序，只有两个方法，找到比x大的位置i，然后继续从i开始找比x小的位置，j，把j插到i的前头
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next) return head;
        //如果第一个就是比x大的，那很尴尬
        ListNode* dummy=new ListNode(x-1);
        dummy->next=head;
        auto h=dummy;
        while(h->next&&h->next->val<x)
        {
            h=h->next;
        }
        //h结点下一个结点是不小于x
        auto pos=h->next;
        while(pos)
        {
            while(pos->next&&pos->next->val>=x)
                pos=pos->next;
                    //pos是2之前的3
            if(!pos->next) break;
            //3->5
            auto temp=pos->next;
            pos->next=pos->next->next;
            temp->next=h->next;
            h->next=temp;
            h=temp;
        }   
        return dummy->next;
    }
};
