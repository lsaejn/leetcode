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
//


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
