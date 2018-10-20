// Given a linked list, swap every two adjacent nodes and return its head.
//
// Example:
//
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Note:
//
//
// 	Your algorithm should use only constant extra space.
// 	You may not modify the values in the list's nodes, only nodes itself may be changed.
//
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
    //有一件很尴尬的事情就是，如果是奇数个结点呢？我们不得不跑一次测试用例：[1,2,3,4,5]->[2,1,4,3,5]
    ListNode* swapPairs(ListNode* head) {
        //如果头节点之前有一个结点h，那就好了，我们交换第1、2个结点，再前进2次，交换3、4个结点
        //我们可以创造这个结点，也可以先交换1，2结点，让这个结点指向新的第2个结点。这里我用的是第2种办法

        if(!head||!head->next) return head;//保证有两个结点
        auto h=head;
        auto temp=h->next->next;
        head=h->next;
        h->next->next=h;
        h->next=temp;
       //现在head：2.。。。21345//h指向1，现在我们可以交换1的后面两个，然后执行循环
        while(h->next&&h->next->next)//后2个结点存在
        {
            auto temp=h->next->next->next;//3
            auto t=h->next->next;
            h->next->next->next=h->next;
            h->next->next=temp;
            h->next=t;    
            h=h->next->next;
        }
        return head;
    }
};
