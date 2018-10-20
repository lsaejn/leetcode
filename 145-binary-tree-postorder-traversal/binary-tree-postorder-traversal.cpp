// Given a binary tree, return the postorder traversal of its nodes' values.
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
// Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        if (!root) return {};
        stack<TreeNode*> s;
        vector<int> output;
        s.push(root);
        while(!s.empty())
        {
            root=s.top();
            s.pop();
            output.push_back(root->val);
            if (root->left) s.push(root->left);
            if (root->right) s.push(root->right);
        }
        reverse(output.begin(),output.end());
        return output;
    }
};
