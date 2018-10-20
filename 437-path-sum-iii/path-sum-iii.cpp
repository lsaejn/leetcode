// You are given a binary tree in which each node contains an integer value.
//
// Find the number of paths that sum to a given value.
//
// The path does not need to start or end at the root or a leaf, but it must go downwards
// (traveling only from parent nodes to child nodes).
//
// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
//
// Example:
//
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1
//
// Return 3. The paths that sum to 8 are:
//
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11
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
    //只要结果就行
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        vector<int> col;
        return pathSum(root,col,sum);
    }
    
    int pathSum(TreeNode* root,vector<int> sum,int target)
    {
        if(!root) return 0;
        int count=0;
        if(root->val==target)//单纯的节点==target也可以，无聊的题
            count++;
        for(int i=0;i!=sum.size();++i)
        {
            if(sum[i]+root->val==target)
                ++count;
            sum[i]+=root->val;
        }
        sum.push_back(root->val);
        return count+pathSum(root->left,sum,target)+pathSum(root->right,sum,target);        
    }
    
};
