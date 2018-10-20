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
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


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
