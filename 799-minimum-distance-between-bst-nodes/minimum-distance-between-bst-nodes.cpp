// Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
//
// Example :
//
//
// Input: root = [4,2,6,1,3,null,null]
// Output: 1
// Explanation:
// Note that root is a TreeNode object, not an array.
//
// The given tree [4,2,6,1,3,null,null] is represented by the following diagram:
//
//           4
//         /   \
//       2      6
//      / \    
//     1   3  
//
// while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
//
//
// Note:
//
//
// 	The size of the BST will be between 2 and 100.
// 	The BST is always valid, each node's value is an integer, and each node's value is different.
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
    //注意，这是二叉线索树，对于root，比root小的最大值是左子树的最右边一个，比root大的最小值是右子树的最左边
    int minDiffInBST(TreeNode* root) 
    {
        if(!root||(root&&!root->left&&!root->right)) return INT32_MAX;
        auto left=root->left;
        auto right=root->right;
        while(left&&left->right)//多判断了一个
            left=left->right;
        while(right&&right->left)
            right=right->left;
        int left_max=0;
        int right_min=0;
        if(!left) left_max=INT32_MAX;
        else left_max=left->val;
        if(!right) right_min=INT32_MAX;
        else right_min=right->val;
            
        return min(min(abs(root->val-left_max),abs(root->val-right_min)),min(minDiffInBST(root->left),minDiffInBST(root->right)));
    }
};
