// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
// Example 1:
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
//
//
//
//
// Example 2:
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False
//
//
//
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
    //我们需要层次遍历。或者像这样递归到叶子
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> s;
        return helper(root, k, s);//根节点，目标数，哈希表
    }
    bool helper(TreeNode* node, int k, unordered_set<int>& s) {
        if (!node) return false;//表示本节点找不到
        if (s.count(k - node->val)) return true;//不为空，看表
        s.insert(node->val);//表里没有，放入自己，然后交给左右子树
        return helper(node->left, k, s) || helper(node->right, k, s);
    }
};
