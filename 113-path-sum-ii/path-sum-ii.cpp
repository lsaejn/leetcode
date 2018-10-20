// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
//
//
// Return:
//
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};        
        vector<int> before; 
        vector<vector<int>> result;
       // if(root->val==sum&&!root->left&&!root->right)
       // {
       //     before.push_back(root->val);
       //     result.push_back(before);
       //     return result;
       // }
        helper(before,result,root,sum);
       // for(auto )
        //result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
    
    void helper(vector<int>& before,vector<vector<int>>& result,TreeNode* root,int target)
    {
        if(!root) return;
        if(root&&!root->left&&!root->right&&target==root->val) 
        {
            before.push_back(root->val);
            result.push_back(before);
            before.pop_back();
            return;
        }
        
        before.push_back(root->val);
        if(root->left)
            helper(before,result,root->left,target-root->val);
        if(root->right)
            helper(before,result,root->right,target-root->val);
        before.pop_back();
    }
};
