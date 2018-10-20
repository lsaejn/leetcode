// Write a program to find the node at which the intersection of two singly linked lists begins.
//
// For example, the following two linked lists: 
//
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
//
// begin to intersect at node c1.
//
// Notes:
//
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns. 
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
//
//
//
// Credits:Special thanks to @stellari for adding this problem and creating all test cases.


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //用一个顺序容器保存list1的指针即可，因为如果节点地址相同，后面必然相同
        vector<ListNode *> col;
        while(headA)
        {
            col.push_back(headA);
            headA=headA->next;
        }
        while(headB)
        {
            if(find(col.begin(),col.end(),headB)!=col.end())
                return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};
