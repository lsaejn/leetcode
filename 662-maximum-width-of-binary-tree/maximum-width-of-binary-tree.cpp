// Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null. 
//
// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
//
// Example 1:
//
// Input: 
//
//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 
//
// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
//
//
//
// Example 2:
//
// Input: 
//
//           1
//          /  
//         3    
//        / \       
//       5   3     
//
// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).
//
//
//
// Example 3:
//
// Input: 
//
//           1
//          / \
//         3   2 
//        /        
//       5      
//
// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).
//
//
// Example 4:
//
// Input: 
//
//           1
//          / \
//         3   2
//        /     \  
//       5       9 
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
//
//
//
//
// Note:
// Answer will in the range of 32-bit signed integer.
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
    //如果我们能把它写成满二叉树的形式，就能很快得出结果。所以必须引入“层”这个概念，我们需要一个helper
    //根节点序号为1，深度为0
    /*
    首先判断，如果当前结点为空，那么直接返回，然后判断如果当前深度大于start数组的长度，说明当前到了新的一层的最左结点，我们将当前位置存入start数组中。然后我们用idx - start[h] + 1来更新结果res。这里idx是当前结点的位置，start[h]是当前层最左结点的位置
    */
    //这个算法不好的一点就在于：当前深度大于start数组的长度，说明当前到了新的一层的最左结点。
    //这是和代码顺序相关的。
    int widthOfBinaryTree(TreeNode* root)
    {
        int res = 0;
        vector<int> start;
        helper(root, 0, 1, start, res);//深度0，位置1，
        return res;
    }
    void helper(TreeNode* node, int h, int idx, vector<int>& start, int& res) {
        if (!node) return;
        if (h >= start.size()) start.push_back(idx);
        res = max(res, idx - start[h] + 1);
        helper(node->left, h + 1, idx * 2, start, res);
        helper(node->right, h + 1, idx * 2 + 1, start, res);
        
    }
};
