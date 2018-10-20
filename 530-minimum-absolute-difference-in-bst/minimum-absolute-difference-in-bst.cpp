// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
//
//
// Example:
//
// Input:
//
//    1
//     \
//      3
//     /
//    2
//
// Output:
// 1
//
// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
//
//
//
//
// Note:
// There are at least two nodes in this BST.
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
public:
    // 第一次看错题了，是any two nodes.由于是二叉线索树，只需要中序遍历依次即可
    int getMinimumDifference(TreeNode* root)
    {
        int res = INT_MAX, pre = -1;
        inorder(root, pre, res);
        return res;
    }
    void inorder(TreeNode* root, int& pre, int& res) //看到吗？又来了，这个pre给按顺序遍历时使用
    {
        if (!root) return;
        inorder(root->left, pre, res);
        if (pre != -1) 
            res = min(res, root->val - pre);
        pre = root->val;
        inorder(root->right, pre, res);
    }
};
