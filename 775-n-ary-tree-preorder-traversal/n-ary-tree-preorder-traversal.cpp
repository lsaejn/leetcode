// Given an n-ary tree, return the preorder traversal of its nodes' values.
//  
//
// For example, given a 3-ary tree:
//
//
//  
//
// Return its preorder traversal as: [1,3,5,6,2,4].
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
    vector<int> re;
    vector<int> preorder(Node* root) {
        if(!root) return {};
        re.push_back(root->val);
        for(auto node:root->children)
            preorder(node);
        return re;
    }
};
