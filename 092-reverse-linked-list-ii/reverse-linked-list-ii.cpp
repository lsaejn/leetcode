// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL
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
    //反转它，需要记录m-1的位置和n结点指针
    //入股要一次遍历，那么我们需要按顺序依次逆序过去
    //count=1,因为逆序都是2个起。先找到1，反转2，3.1->3->2->4,count++ ,4移到3前面，然后.。。
    /*
    给定 1->2->3->4->5->NULL, m = 2 和 n = 4,
    返回 1->4->3->2->5->NULL.
    m和n是位置，索引+1，一次遍历
    */
    //如果要反转的结点在头部，非常尴尬。我们准备一个空结点
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        auto size=n-m;
        if(size==0) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        auto h=dummy;
        while(m>1)
        {
            h=h->next;//h的next指向要反转的第一个结点
            --m;
        }
        auto toexchange_before=h->next;
        //我们一直交换h的下一个结点和toexchange
        while(size)
        {
            auto temp=toexchange_before->next;//要交换的结点3
            toexchange_before->next=temp->next;//2->4
            temp->next=h->next;//2->4
            h->next=temp;
            size--;
        }
        return dummy->next;
    }
};
