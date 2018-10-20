// We are given head, the head node of a linked list containing unique integer values.
//
// We are also given the list G, a subset of the values in the linked list.
//
// Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.
//
// Example 1:
//
//
// Input: 
// head: 0->1->2->3
// G = [0, 1, 3]
// Output: 2
// Explanation: 
// 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
//
//
// Example 2:
//
//
// Input: 
// head: 0->1->2->3->4
// G = [0, 3, 1, 4]
// Output: 2
// Explanation: 
// 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
//
//
// Note: 
//
//
// 	If N is the length of the linked list given by head, 1 <= N <= 10000.
// 	The value of each node in the linked list will be in the range [0, N - 1].
// 	1 <= G.length <= 10000.
// 	G is a subset of all values in the linked list.
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
public://把G转换成表，遍历head即可
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head) return 0;
        unordered_set<int> col(G.begin(),G.end());
        auto dummy=new ListNode(0);
        bool exist=false;
        int count=0;
        auto copy=head;
        while(copy)
        {
            if(!col.count(copy->val))
                exist=false;
            else
            {
                if(exist==false)
                {
                    ++count;
                    exist=true;//当前元素存在
                }
            }
            copy=copy->next;
        }
        return count;
    }
};
