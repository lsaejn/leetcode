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
// Note: Recursive solution is trivial, could you do it iteratively?" />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


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
