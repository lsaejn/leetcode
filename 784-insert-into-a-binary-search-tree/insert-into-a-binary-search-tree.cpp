// Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
//
// Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
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
// And the value to insert: 5
//
//
// You can return this binary search tree:
//
//
//          4
//        /   \
//       2     7
//      / \   /
//     1   3 5
//
//
// This tree is also valid:
//
//
//          5
//        /   \
//       2     7
//      / \   
//     1   3
//          \
//           4
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
public://我都不敢相信有这么简单的题。。。//我们加大一点难度，让它保持平衡？但这要维护一个length
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(!root) return new TreeNode(val);
        if(val<root->val) root->left=insertIntoBST(root->left,val);
        else if(val>root->val) root->right=insertIntoBST(root->right,val);
        return root; 
    }
};
