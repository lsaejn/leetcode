// Given a binary tree, return the preorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,2,3]
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
    //前序遍历有一个很直观的写法，放入root，取出，再放入左右非空结点。
    //但是建议和中序一起记忆，因为2个写法只是访问顺序不同
    vector<int> preorderTraversal(TreeNode* root) {
                if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s({root});
        while (!s.empty()) {
            TreeNode *t = s.top(); s.pop();
            res.push_back(t->val);
            if (t->right) s.push(t->right);
            if (t->left) s.push(t->left);
        }
        return res;
    }
};
