// Given a non-empty binary tree, find the maximum path sum.
//
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
// Example 1:
//
//
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
//
//
// Example 2:
//
//
// Input: [-10,9,20,null,null,15,7]
//
//    -10
//    / \
//   9  20
//     /  \
//    15   7
//
// Output: 42
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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int result=INT32_MIN;
        int rMax=help(root,result);
        return max(result,rMax);
    }
    
    //返回值代表不可穿越root的最大值。result是可以穿越root的最大值
    int help(TreeNode* root,int& result)
    {
        int left=0;
        int right=0;
        if(root->left)
            left=help(root->left,result);
        if(root->right)
            right=help(root->right,result);
        int rmax=root->val;
        if(left>0) rmax+=left;
        if(right>0) rmax+=right;
        result=max(result,rmax);
        return max(left>0?root->val+left:root->val,right>0?root->val+right:root->val);
        
    }
};
