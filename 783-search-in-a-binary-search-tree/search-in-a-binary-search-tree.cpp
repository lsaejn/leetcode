// Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
//
// For example, 
//
//
// Given the tree:
//         4
//        / \
//       2   7
//      / \
//     1   3
//
// And the value to search: 2
//
//
// You should return this subtree:
//
//
//       2     
//      / \   
//     1   3
//
//
// In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL." />
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val==val) return root;
        else
        {
           TreeNode* re=searchBST(root->left,val);
           if(re) return re;
           re=searchBST(root->right,val);
           if(re) return re;
        }
        return NULL;
    }
};
