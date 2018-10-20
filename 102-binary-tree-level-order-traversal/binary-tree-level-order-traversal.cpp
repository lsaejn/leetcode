// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
// return its level order traversal as:
//
// [
//   [3],
//   [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if(!root) return {};
        //层次遍历用2个队列
        deque<TreeNode*> current,next;
        
        current.push_back(root);
        
        vector<vector<int>> result;
        while(!current.empty())
        {
            vector<int> temp;
            for(auto elem:current)
            {
                temp.push_back(elem->val);
                if(elem->left)
                    next.push_back(elem->left);
                if(elem->right)
                    next.push_back(elem->right);
            }
            result.push_back(move(temp));
            current=next;
            next.clear();
            
        }
        return result;
        
        
    }
};
