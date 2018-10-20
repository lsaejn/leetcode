// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=new ListNode(0);
        ListNode* current=result;
        int pro=0;
        int res;
        while(!(l1==nullptr&&l2==nullptr&&pro==0))//推出条件：都空，且没有进位
        {
            if(l1==nullptr&&l2==nullptr) 
            {
              res=pro; 
            }
                
            else if(l1==nullptr)
            {
                res=l2->val+pro;
                l2=l2->next;
            }
            else if(l2==nullptr)
            {
                res=l1->val+pro;
                l1=l1->next;
            }
            else
            {
               res=l1->val+l2->val+pro; 
               l1=l1->next;
                l2=l2->next;
            }
                
            if(res>=10)
            {
                res-=10;
                pro=1;
            }
            else
                pro=0;

            current->val=res;
            if(!(l1==nullptr&&l2==nullptr&&pro==0))
            {
                ListNode* temp=new ListNode(0);
                current->next=temp;
                current=current->next;
            }
        }
        return result;
    }
};
