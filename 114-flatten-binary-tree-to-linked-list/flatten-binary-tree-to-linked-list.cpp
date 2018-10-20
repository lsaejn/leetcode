// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
//
//
// The flattened tree should look like:
//
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
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
    //注意，要求的是原地
    //非迭代版本的实现，这个方法是从根节点开始出发，先检测其左子结点是否存在，如存在则将根节点和其右子节点断开，将左子结点及其后面所有结构一起连到原右子节点的位置，把原右子节点连到元左子结点最后面的右子节点之后。
    void flatten(TreeNode* root) {
        if(!root) return;
        while(root)
        {
            if(root->left)
            {
                auto temp=root->left;
                while(temp->right)
                    temp=temp->right;
                temp->right=root->right;
                root->right=root->left;
                root->left=nullptr;
                
            }
            else
            {
                root=root->right;
            }
            
        }
        
    }
    
        void flatten(TreeNode *root,int version2) {
        if (!root) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) root = root->right;
        root->right = tmp;
    }
};
