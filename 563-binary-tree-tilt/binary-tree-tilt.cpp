// Given a binary tree, return the tilt of the whole tree.
//
// The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
//
// The tilt of the whole tree is defined as the sum of all nodes' tilt.
//
// Example:
//
// Input: 
//          1
//        /   \
//       2     3
// Output: 1
// Explanation: 
// Tilt of node 2 : 0
// Tilt of node 3 : 0
// Tilt of node 1 : |2-3| = 1
// Tilt of binary tree : 0 + 0 + 1 = 1
//
//
//
// Note:
//
// The sum of node values in any subtree won't exceed the range of 32-bit integer. 
// All the tilt values won't exceed the range of 32-bit integer.
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
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        return    findNodeTilt(root)+findTilt(root->left)+findTilt(root->right);     
    }
    int findNodeTilt(TreeNode* root){
        if(!root) return 0;
        auto re=abs(sum(root->left)-sum(root->right));
            cout<<root->val<<"::"<<re<<endl;
        return re;
    }
    
    int sum(TreeNode* root)
    {        
        if(!root) return 0;
        int re=root->val+sum(root->left)+sum(root->right);
        //cout<<re<<endl;
        return re;
    }
};
