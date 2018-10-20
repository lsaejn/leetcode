// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
//
// Note: The length of path between two nodes is represented by the number of edges between them.
//
//
// Example 1:
//
//
//
//
// Input:
//
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
//
//
//
//
// Output:
//
// 2
//
//
//
//
// Example 2:
//
//
//
//
// Input:
//
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
//
//
//
//
// Output:
//
// 2
//
//
//
// Note:
// The given binary tree has not more than 10000 nodes.  The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root)
    {
        //对每个结点都从上到底部找最长路径。。
        if (!root) 
            return 0;
        int sub = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));//查找左右子树的最长路径
        return max(sub,helper(root->left, root->val) + helper(root->right, root->val));//左右子树的最大值和自己比较
    }
    
    int helper(TreeNode* node, int parent)//带着父亲结点的值查找最大深度。 注意，是这个值在本树的深度
    {
        if (!node || node->val != parent) return 0;//本结点值和父结点不等，让子树查找它的深度
        return 1 + max(helper(node->left, parent), helper(node->right, parent));
    }
};
