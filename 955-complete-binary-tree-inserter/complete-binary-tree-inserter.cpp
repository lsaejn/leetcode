// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
//
// Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:
//
//
// 	CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
// 	CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
// 	CBTInserter.get_root() will return the head node of the tree.
//
//
//
//
//
//
//  
//
// Example 1:
//
//
// Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
// Output: [null,1,[1,2]]
//
//
//
// Example 2:
//
//
// Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
// Output: [null,3,4,[1,2,3,4,5,6,7,8]]
//
//
//
//  
//
// Note:
//
//
// 	The initial given tree is complete and contains between 1 and 1000 nodes.
// 	CBTInserter.insert is called at most 10000 times per test case.
// 	Every value of a given or inserted node is between 0 and 5000.
//
//
//
//
//
//  
//
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root=root;
        length=getLen(root);
    }
    
    int insert(int v) {
        auto root=this->root;
        vector<int> direct;
        auto len=++length;
        while(len>=1)
        {            
            direct.push_back(len);
            len/=2;
        }
        reverse(direct.begin(),direct.end());        
        for(int i=0;i<direct.size()-1;++i)
        {
            if (i == direct.size() - 2) break;
            if(direct[i+1]==2*direct[i])    root=root->left;
            else    root=root->right;
        }
        if(!root->left) root->left=new TreeNode(v);
        else root->right=new TreeNode(v);
        return root->val;
    }
    
    int getLen(TreeNode* root)
    {
        if(!root) return 0;
        return 1+getLen(root->left)+getLen(root->right);
    }
    
    TreeNode* get_root()
    {
        return root;
    }
    
    TreeNode* root;
    int length=0;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
