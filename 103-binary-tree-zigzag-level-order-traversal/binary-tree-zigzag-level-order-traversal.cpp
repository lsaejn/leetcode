// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
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
    //如果你能够层次遍历，那么顺序其实无所谓
    //可以用栈，可以逆序
    
    //1 23 7654 891011
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >res;
        if (!root) return res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        vector<int> out;
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                TreeNode *cur = s1.top();
                s1.pop();
                out.push_back(cur->val);
                if (cur->left) s2.push(cur->left);
                if (cur->right) s2.push(cur->right);
            } 
            if (!out.empty()) res.push_back(out);
            out.clear();
            while (!s2.empty()) {
                TreeNode *cur = s2.top();
                s2.pop();
                out.push_back(cur->val);
                if (cur->right) s1.push(cur->right);
                if (cur->left) s1.push(cur->left);
            }
            if (!out.empty()) res.push_back(out);
            out.clear();
        }
        return res;
    }
};
