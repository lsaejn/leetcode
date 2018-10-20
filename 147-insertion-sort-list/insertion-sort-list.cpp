// Sort a linked list using insertion sort.
//
//
//
//
//
// A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
// With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
//  
//
//
//
//
// Algorithm of Insertion Sort:
//
//
// 	Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
// 	At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
// 	It repeats until no input elements remain.
//
//
//
// Example 1:
//
//
// Input: 4->2->1->3
// Output: 1->2->3->4
//
//
// Example 2:
//
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5
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
    //有一个链表头head将极大地方便操作
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* newhead=new ListNode(INT32_MIN);
        while(head)
        {
            auto copy=newhead;
            while(copy->next&&head->val>copy->next->val)
            {
                copy=copy->next;
            }
            auto temp1=copy->next;
            auto temp2=head->next;
            copy->next=head;
            copy->next->next=temp1;
            head=temp2;
        }
        return newhead->next;
    }
};
