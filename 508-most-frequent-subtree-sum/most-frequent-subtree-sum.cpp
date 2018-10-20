//
// Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
//
//
// Examples 1
// Input:
//
//   5
//  /  \
// 2   -3
//
// return [2, -3, 4], since all the values happen only once, return all of them in any order.
//
//
// Examples 2
// Input:
//
//   5
//  /  \
// 2   -5
//
// return [2], since 2 happens twice, however -5 only occur once.
//
//
// Note:
// You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
    //很容易用递归获得每个结点的value
    //但是怎么才是最高效的呢？计算root的时候，root会要求计算左右子树，和后序遍历一致，所以我们用后序遍历的递归
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        vector<int> res;
        unordered_map<int, int> m;
        int cnt = 0;
        postorder(root, m, cnt, res);
        return res;
    }
    int postorder(TreeNode* node, unordered_map<int, int>& m, int& cnt, vector<int>& res)
    {
        if (!node) return 0;
        int left = postorder(node->left, m, cnt, res);
        int right = postorder(node->right, m, cnt, res);
        int sum = left + right + node->val;
        ++m[sum];
        if (m[sum] >= cnt) 
        {
            if (m[sum] > cnt) res.clear();
            res.push_back(sum);
            cnt = m[sum];
        }
        return sum;
    }
};
