// Given an n-ary tree, return the postorder traversal of its nodes' values.
//  
//
// For example, given a 3-ary tree:
//
//
//  
//
// Return its postorder traversal as: [5,6,3,2,4,1].
//  
//
// Note: Recursive solution is trivial, could you do it iteratively?


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root)
    {
        if(!root) return {};       
        for(auto node:root->children)
        {
            postorder(node);
           // re.push_back(node->val);
        }
        re.push_back(root->val);
        return re;
    }
    vector<int> re;
};
