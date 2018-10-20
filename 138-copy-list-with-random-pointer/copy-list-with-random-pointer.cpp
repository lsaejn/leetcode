//
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//
//
// Return a deep copy of the list.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
//指针的遍历非常耗时，最好的办法是，每次创造一个结点的时候就把随机指针创造处来。
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if(!head) return head;
        unordered_map<RandomListNode*,RandomListNode*> col;
        auto dummy=new RandomListNode(0);
        auto h=dummy;
        while(head)
        {
            auto temp=copyOrGetNode(head,col);//取得head
            h->next=temp;
            h=h->next;
            head=head->next;
        }
        return dummy->next;
    }
    
    RandomListNode * copyOrGetNode(RandomListNode*src,unordered_map<RandomListNode*,RandomListNode*>& col)
    {
        if(!src) return nullptr;
        if(col.count(src)>0) return col[src];
        RandomListNode * des=new RandomListNode(src->label);
        col.insert({src,des});
        //如果用while循环，会搞不定互相random的情况
        if(src->random)
        {
            auto temp=copyOrGetNode(src->random,col);
            des->random=temp;
        }

        return des;
    }
};
