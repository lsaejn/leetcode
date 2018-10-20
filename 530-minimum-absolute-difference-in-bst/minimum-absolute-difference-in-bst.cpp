// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
//
//
// Example:
//
// Input:
//
//    1
//     \
//      3
//     /
//    2
//
// Output:
// 1
//
// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
//
//
//
//
// Note:
// There are at least two nodes in this BST.
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
    // 第一次看错题了，是any two nodes.由于是二叉线索树，只需要中序遍历依次即可
    int getMinimumDifference(TreeNode* root)
    {
        int res = INT_MAX, pre = -1;
        inorder(root, pre, res);
        return res;
    }
    void inorder(TreeNode* root, int& pre, int& res) //看到吗？又来了，这个pre给按顺序遍历时使用
    {
        if (!root) return;
        inorder(root->left, pre, res);
        if (pre != -1) 
            res = min(res, root->val - pre);
        pre = root->val;
        inorder(root->right, pre, res);
    }
};
