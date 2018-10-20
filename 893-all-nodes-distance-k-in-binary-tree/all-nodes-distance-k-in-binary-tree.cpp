// We are given a binary tree (with root node root), a target node, and an integer value `K`.
//
// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
// Output: [7,4,1]
// Explanation: 
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.
//
// Note that the inputs "root" and "target" are actually TreeNodes.
// The descriptions of the inputs above are just serializations of these objects.
//
//
//
// Note:
//
//
// 	The given tree is non-empty.
// 	Each node in the tree has unique values 0 <= node.val <= 500.
// 	The target node is a node in the tree.
// 	0 <= K <= 1000.
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
public://难度在于距离为k的结点包含了跨越父结点的结点，使用dfs是非常考验功力的
void getDown(TreeNode* root, int k, vector<int>&ans) {//以root为根向下寻找距离它k的结点，放入ans,返回root的父节点应该增加的距离
        if (!root) return;
        if (k == 0) 
            ans.push_back(root->val);
        getDown(root->left, k-1, ans);
        getDown(root->right, k-1, ans);
    }
    
    int dfs(TreeNode*root, TreeNode* target, int k, vector<int>&ret) {//以root为根结点找到target，返回2者距离
        if (!root) return -2;
        if (root == target) {
            getDown(target, k, ret);
            return 0;
        }
        
        int d = dfs(root->left, target, k, ret);
        if (d >=0) {
            if (d+1 == k) {
                ret.push_back(root->val);
            } else {
                 getDown(root->right,   k-d-2, ret);
            }
            return d + 1;
            
        }
        
        d = dfs(root->right, target, k, ret);
        if (d>=0) {
            if (d+1 == k) {
                ret.push_back(root->val);
            } else {
                 getDown(root->left,  k-d-2, ret);
            }
            return d+1;
        }
        
        return -2;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ret;
        if (!root) return ret;
        dfs(root, target, K, ret);
        return ret;
    }

};
