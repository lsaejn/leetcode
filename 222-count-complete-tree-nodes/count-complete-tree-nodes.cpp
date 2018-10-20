// Given a complete binary tree, count the number of nodes.
//
// Note: 
//
// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
//
// Example:
//
//
// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6
//
// Output: 6
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
    //用递归，如果左右结点都是完全二叉树，那么自己也是完全二叉树
    /*
        算结点很容易，但是超出时间限制。对于一颗满二叉树，最左结点最右结点的高度相同的话，
        我们马上可以得到这棵树的结点数。借此优化计算
    */
    int countNodes(TreeNode* root)
    {
        /*
        if(!root) return 0;
        int lh=0;
        int rh=0;
        auto lroot=root;
        auto rroot=root;
        while(lroot->left)
        {
            ++lh;
            lroot=lroot->left;
        }
        while(rroot->right)
        {
            ++lh;
            rroot=rroot->right;
        }
        if(lh==rh) return pow(2,lh+1)-1;
        return countNodes(root->left) + countNodes(root->right) + 1;*/
        if(!root) return 0;
        int hLeft = 0, hRight = 0;
        auto pLeft = root->left, pRight = root->right;
        while (pLeft) {
            ++hLeft;
            pLeft = pLeft->left;
        }
        while (pRight) {
            ++hRight;
            pRight = pRight->right;
        }
        if (hLeft == hRight) return pow(2, hLeft+1) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
