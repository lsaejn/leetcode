// Given a binary tree, return all root-to-leaf paths.
//
// Note: A leaf is a node with no children.
//
// Example:
//
//
// Input:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
// Output: ["1->2->5", "1->3"]
//
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {

        if(!root) return {};
        if(!root->left&&!root->right) 
            return vector<string> {to_string(root->val)};
        
        string s;
        s+=(to_string(root->val));
        if(root->left)
            binaryTreePaths(root->left,s);
        if(root->right);
            binaryTreePaths(root->right,s);
        return result;
        
    }
    
    void binaryTreePaths(TreeNode* root,string s) {
        if(!root)
        {
            return;
        }
        s=s+"->";
        s+=(to_string(root->val)); 
        if(!root->left&&!root->right)
            result.push_back(s);

        binaryTreePaths(root->left,s);
        binaryTreePaths(root->right,s);
                 
    }
private:
    vector<string> result;
    
};
