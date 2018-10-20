// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
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
    //从s1里找到root，取出s2里root左边的string1和右边的string2，然后对左右子树递归下去
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0) return nullptr;
        TreeNode* root=nullptr;
        buildTree(preorder,0,preorder.size(),inorder,0,inorder.size(),root);
        return root;
    }
    //前序遍历 = [3,9,20,15,7]
    //中序遍历 = [9,3,15,20,7]
    
    void buildTree(vector<int>& preorder,int begin1,int end1, vector<int>& inorder,int begin2,int end2,TreeNode*& root) 
    {
        if(begin1>end1) return;
        if(!root) root=new TreeNode(preorder[begin1]);
        if(begin1<preorder.size())
        {
            root->val=preorder[begin1];
        }
        int i=begin2;
        for(;i<end2;++i)
        {
          if(inorder[i]==root->val)
            break;
        }
        int size_left=i-begin2;
        int size_right=end2-i-1;
        if(size_left>0)
            buildTree(preorder,begin1+1,begin1+size_left,inorder,begin2,i,root->left);
        if(size_right>0)
            buildTree(preorder,begin1+1+size_left,end1,inorder,i+1,end2,root->right);
        
    }
};
