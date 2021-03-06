// Given a linked list, rotate the list to the right by k places, where k is non-negative.
//
// Example 1:
//
//
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
//
//
// Example 2:
//
//
// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//题目不太清晰，【1，2】可以右旋转3？
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //首先要找到倒数第k+1个节点
        if(!head) 
            return nullptr;
        
        if (!head) return NULL;
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        k %= n;
        ListNode* current=head;
       // k--;
        while(k>0&&current){
            current=current->next;
            k--;
        }
        if(k!=0||current==nullptr) return head;
        ListNode* newHeader=head;
        while(current->next){
            current=current->next;
            newHeader=newHeader->next;
        }
        current->next=head;
        ListNode* temp=newHeader->next;
        newHeader->next=nullptr;
        return temp;
    }
};
