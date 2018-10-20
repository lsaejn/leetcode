// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
//
//
//
//
// For example:
// Given BST [1,null,2,2],
//
//    1
//     \
//      2
//     /
//    2
//
//
//
// return [2].
//
//
// Note:
// If a tree has more than one mode, you can return them in any order.
//
//
// Follow up:
// Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
/*
由于是二分搜索树，那么我们中序遍历出来的结果就是有序的，这样我们只要比较前后两个元素是否相等，就等统计出现某个元素出现的次数，因为相同的元素肯定是都在一起的。我们需要一个结点变量pre来记录上一个遍历到的结点，然后mx还是记录最大的次数，cnt来计数当前元素出现的个数，我们在中序遍历的时候，如果pre不为空，说明当前不是第一个结点，我们和之前一个结点值比较，如果相等，cnt自增1，如果不等，cnt重置1。如果此时cnt大于了mx，那么我们清空结果res，并把当前结点值加入结果res，如果cnt等于mx，那我们直接将当前结点值加入结果res，然后mx赋值为cnt。最后我们要把pre更新为当前结点，
*/
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int mx = 0, cnt = 1;
        TreeNode *pre = NULL;
        inorder(root, pre, cnt, mx, res);
        return res;
    }
    //这个TreeNode*& pre太精妙了，建议好好看看。自己想确实难以想出来
    void inorder(TreeNode* node, TreeNode*& pre, int& cnt, int& mx, vector<int>& res)
    {
        if (!node) return;
        inorder(node->left, pre, cnt, mx, res);
        if (pre) {
            cnt = (node->val == pre->val) ? cnt + 1 : 1;
        }
        if (cnt >= mx) {
            if (cnt > mx) res.clear();
            res.push_back(node->val);
            mx = cnt;
        } 
        pre = node;
        inorder(node->right, pre, cnt, mx, res);
    }
    
};
