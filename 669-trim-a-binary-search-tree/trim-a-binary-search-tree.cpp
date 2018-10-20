//
// Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.
//
//
// Example 1:
//
// Input: 
//     1
//    / \
//   0   2
//
//   L = 1
//   R = 2
//
// Output: 
//     1
//       \
//        2
//
//
//
// Example 2:
//
// Input: 
//     3
//    / \
//   0   4
//    \
//     2
//    /
//   1
//
//   L = 1
//   R = 3
//
// Output: 
//       3
//      / 
//    2   
//   /
//  1
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return NULL;
        if (root->val < L) return trimBST(root->right, L, R);//根小于L，显然它的右子数也小于L
        if (root->val > R) return trimBST(root->left, L, R);//
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};
