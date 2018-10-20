// You need to find the largest value in each row of a binary tree.
//
// Example:
//
// Input: 
//
//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 
//
// Output: [1, 3, 9]
//
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
    vector<int> largestValues(TreeNode* root) 
    {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            int n = q.size(), mx = INT_MIN;
            for (int i = 0; i < n; ++i) 
            {
                TreeNode *t = q.front(); 
                q.pop();
                mx = max(mx, t->val);
                if (t->left) 
                    q.push(t->left);
                if (t->right) 
                    q.push(t->right);
            }
            res.push_back(mx);
        }
        return res; 
    }
};
