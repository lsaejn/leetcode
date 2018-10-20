// Given a binary tree, return the inorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        if(!root) return {};
        stack<TreeNode*> s;
        //s.push(root);
        vector<int> result;
        while(root||!s.empty())
        {
            if(root)
            {
                s.push(root);
                root=root->left;                
            }
            else
            {
               root=s.top();
               result.push_back(root->val);
               s.pop();
               root=root->right;
            }
        }
        return result;
        
    }
};
