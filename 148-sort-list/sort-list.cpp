// Sort a linked list in O(n log n) time using constant space complexity.
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
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


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
    //关键在于(n log n) 的复杂度
    //用归并排序就能满足这个要求了
    ListNode* sortList(ListNode* head) 
    {
        if(!head||!head->next) return head;
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
        
    }
    
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        /*
        shared_ptr<ListNode> dummy(new ListNode(0));
        ListNode* h=dummy.get();
        while(L1&&L2)
        {
            if(L1->val<=L2->val)
            {
                h->next=L1;
                L1=L1->next;
            }
            else
            {
                h->next=L2;
                L2=L2->next;
            }
            h=h->next;
        }
        if(!L1) h->next=L2;
        else if(!L2) h->next=L2;
        return dummy->next;*/
                ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    }
};
