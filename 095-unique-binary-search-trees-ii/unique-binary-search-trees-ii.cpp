// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//
// Example:
//
//
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
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
    //之前想破脑袋都不行，其实关键就在于，用比自己小的数建立左子树
    vector<TreeNode *> generateTrees(int n) 
    {
        if (n == 0) 
            return {};
        return generateTreesDFS(1, n);
    }
    
    vector<TreeNode*> generateTreesDFS(int start, int end) 
    {
        vector<TreeNode*> subTree;
        if (start > end) 
            subTree.push_back(nullptr);
        else 
        {
            for (int i = start; i <= end; ++i)
            {
                vector<TreeNode*> leftSubTree = generateTreesDFS(start, i - 1);
                vector<TreeNode*> rightSubTree = generateTreesDFS(i + 1, end);
                for (int j = 0; j < leftSubTree.size(); ++j)
                {
                    for (int k = 0; k < rightSubTree.size(); ++k)
                    {
                        TreeNode *node = new TreeNode(i);
                        node->left = leftSubTree[j];
                        node->right = rightSubTree[k];
                        subTree.push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
};
