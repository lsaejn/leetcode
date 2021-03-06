// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example, given a 3-ary tree:
//
//  
//
//
//
//  
//
// We should return its level order traversal:
//
//
// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]
//
//
//  
//
// Note:
//
//
// 	The depth of the tree is at most 1000.
// 	The total number of nodes is at most 5000.
//
//


/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        vector<Node*> floor;
        vector<int> temp;
        vector<Node*> floor_next;
        if(root)
            floor.push_back(root);
        while(!floor.empty())
        {
            for(auto elem:floor)
            {
                temp.push_back(elem->val);
                for(auto node:elem->children)
                    if(node)
                        floor_next.push_back(node);
            }
            result.push_back(temp);
            swap(floor,floor_next);
            temp.clear();
            floor_next.clear();            
        }
        return result;
    }
};
