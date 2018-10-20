// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
//
// Basically, the deletion can be divided into two stages:
//
// Search for a node to remove.
// If the node is found, delete the node.
//
//
//
// Note: Time complexity should be O(height of tree).
//
// Example:
//
// root = [5,3,6,2,4,null,7]
// key = 3
//
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Given key to delete is 3. So we find the node with value 3 and delete it.
//
// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
//
//     5
//    / \
//   4   6
//  /     \
// 2       7
//
// Another valid answer is [5,2,6,null,4,null,7].
//
//     5
//    / \
//   2   6
//    \   \
//     4   7
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
    //这是我见过最优雅的递归，你没看错，差不多全是递归，连min里都是。。。
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return nullptr;
        int cmp=key-root->val;
        if(cmp<0)       root->left=deleteNode(root->left,key);
        else if(cmp>0)  root->right=deleteNode(root->right,key);
        else
        {
            if(!root->left) return root->right;
            if(!root->right) return root->left;          
            TreeNode* t=root;
            root=min(t->right);
            root->right=deleteMin(t->right);
            root->left=t->left;
            delete t;
        }
        
        return root;
    }
    
    
    TreeNode* deleteMin(TreeNode* root)
    {
        if(!root->left) return root->right;   
        root->left=deleteMin(root->left);
        return root;    
    }
    
    TreeNode* min(TreeNode* root)
    {
        while(root->left) 
            root=root->left;
        return root;
        
    }
};
