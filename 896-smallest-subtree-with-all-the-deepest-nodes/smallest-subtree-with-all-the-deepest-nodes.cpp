// Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.
//
// A node is deepest if it has the largest depth possible among any node in the entire tree.
//
// The subtree of a node is that node, plus the set of all descendants of that node.
//
// Return the node with the largest depth such that it contains all the deepest nodes in its subtree.
//
//  
//
// Example 1:
//
//
// Input: [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation:
//
//
//
// We return the node with value 2, colored in yellow in the diagram.
// The nodes colored in blue are the deepest nodes of the tree.
// The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
// The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
// Both the input and output have TreeNode type.
//
//
//  
//
// Note:
//
//
// 	The number of nodes in the tree will be between 1 and 500.
// 	The values of each node are unique.
//
//


class Solution {
public:
    //这个递归写得太棒了
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        if(root==NULL) return root;
        int d=0;
        TreeNode* node=findDeep(root,d);
        return node;
    }
    //仔细思考一下，我们往上返回Node*,需要比较左右的深度，深度一样，返回self，否则返回更深者，且深度+1
    TreeNode* findDeep(TreeNode* root,int& d)//计算root的深度，返回更深的结点/或自己(一样深)
    {
        if(root==NULL)
        {
            d=0;
            return root;
        }
        int d1,d2;
        TreeNode* node1=findDeep(root->left,d1);
        TreeNode* node2=findDeep(root->right,d2);
        if(d1==d2)
        {
            d=d1+1;
            return root;
        }
        else if(d1>d2)
        {
            d=d1+1;
            return node1;
        }
        else
        {
            d=d2+1;
            return node2;
        }
    }
};
