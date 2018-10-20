// A full binary tree is a binary tree where each node has exactly 0 or 2 children.
//
// Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.
//
// Each node of each tree in the answer must have node.val = 0.
//
// You may return the final list of trees in any order.
//
//  
//
// Example 1:
//
//
// Input: 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// Explanation:
//
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 20
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N == 1) return {new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i = 1; i < N; i += 2)
        {
            vector<TreeNode*> L = allPossibleFBT(i), R = allPossibleFBT(N - 1 - i);
            for(int j = 0; j < L.size(); j++)//做排列组合
                for(int k = 0; k < R.size(); k++)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = L[j]; 
                    root->right = R[k];
                    ans.push_back(root);
                }
        }
        return ans;
    }
};
