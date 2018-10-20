// Return any binary tree that matches the given preorder and postorder traversals.
//
// Values in the traversals pre and post are distinct positive integers.
//
//  
//
//
// Example 1:
//
//
// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
//
//
//  
//
// Note:
//
//
// 	1 <= pre.length == post.length <= 30
// 	pre[] and post[] are both permutations of 1, 2, ..., pre.length.
// 	It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
//
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
    unordered_map<int, int> m; // 后序遍历的索引
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int len = post.size();
        for (int i = 0; i < len; i++) 
            m[post[i]] = i;
        return construct(pre, post, 0, len - 1, 0, len - 1);
    }
    
    TreeNode* construct(vector<int>& pre, vector<int>& post, int a, int b, int c, int d) {
        TreeNode* n = new TreeNode(pre[a]);
        if (a == b) return n;
        int t = pre[a + 1];
        int idx = m[t];
        int len = idx - c + 1;
        n->left = construct(pre, post, a + 1, a + len, c, c + len - 1);
        if (idx + 1 == d) return n;
        n->right = construct(pre, post, a + len + 1, b, idx + 1, d - 1);
        return n;
    }
};
/*
[1,2,3,4,5,6]
[3,5,6,4,2,1]
*/
