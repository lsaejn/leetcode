//
// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//
//
//
// Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//
// Example 1:
//
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
//
// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//
//
// Example 2:
//
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
//
// Maximum amount of money the thief can rob = 4 + 5 = 9.
//
//
// Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases." />
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
    //看似深度遍历，其实是层次遍历
    //计算出层次遍历下的金额数组，就变成了打家劫舍1
    int rob(TreeNode* root)
    {
        int l = 0, r = 0;
        return helper(root);
    }
    int helper(TreeNode* node) {//每一个结点能获得最大dp[i]值，就是下一层的dp[i+1]和本结点node->val+孙子层的dp[i+2]
        if (!node) return 0;
        int l = helper(node->left);
        int r = helper(node->right);
        int ll=0,lr=0,rl=0,rr=0;
        if(node->left)
        {
         ll=helper(node->left->left);
         lr=helper(node->left->right); 
        }
        if(node->right)
        {           
            rl=helper(node->right->left);        
            rr=helper(node->right->right); 
        }

        return max(node->val + ll + lr + rl + rr, l + r);
    }
};
