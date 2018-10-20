//
// Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
//
//
// Example 1:
//
// Given tree s:
//
//      3
//     / \
//    4   5
//   / \
//  1   2
//
// Given tree t:
//
//    4 
//   / \
//  1   2
//
// Return true, because t has the same structure and node values with a subtree of s.
//
//
// Example 2:
//
// Given tree s:
//
//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
//
// Given tree t:
//
//    4
//   / \
//  1   2
//
// Return false.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //好吧，我也不直到怎么就通过，递归就是这么不讲道理
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if(!s) return false;
        if(!t) return true;
       return  isSameTree(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
    }
    
    bool isSameTree(TreeNode* s, TreeNode* t)
    {
        if(s==t) return true;
        if(!s||!t) return false;
        
        return s->val==t->val&&isSameTree(s->left,t->left)&&isSameTree(s->right,t->right);
    }
};
