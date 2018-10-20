// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// return its depth = 3.
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

    /*
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    */

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return getDepth(root,1);
    }
    int getDepth(TreeNode* root,int depth)//当前节点和所在的深度
    {
        //if(!root) //如果自身为空，则。。可以不要，而是把判断放到下面的if里
         //   return depth-1;
        if((!root->left)&&(!root->right))
            return depth;            
        if((root->left)&&(!root->right))
            return getDepth(root->left,depth+1);            
        if(root->left&&root->right)//如果左右节点都不为null，深度是它们的最大值
            return max(getDepth(root->left,depth+1),getDepth(root->right,depth+1));            
        if((!root->left)&&root->right);//看到了吗？我多写了1个分号，但移到最后作为默认的处理，居然也通过了。
            return getDepth(root->right,depth+1);           
 
    }
};
