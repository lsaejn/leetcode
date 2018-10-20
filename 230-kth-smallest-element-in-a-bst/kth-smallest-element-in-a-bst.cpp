// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
// Example 1:
//
//
// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
//
// Example 2:
//
//
// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3
//
//
// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    //通过中序遍历，我们就可以得到一个有序的序列
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> S;
        while(root||!S.empty())
        {
            if(root)
            {
                S.push(root);
                root=root->left;
            }
            else {
                root=S.top();
                S.pop();
                if(--k==0)
                    return root->val;
                root=root->right;
            }
            
        }
        
    }
};
