//
// Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. 
//
//
//
// Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree. 
//
//
//
// If no such second minimum value exists, output -1 instead.
//
//
// Example 1:
//
// Input: 
//     2
//    / \
//   2   5
//      / \
//     5   7
//
// Output: 5
// Explanation: The smallest value is 2, the second smallest value is 5.
//
//
//
// Example 2:
//
// Input: 
//     2
//    / \
//   2   2
//
// Output: -1
// Explanation: The smallest value is 2, but there isn't any second smallest value.
//
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
    //If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes
    //这是一个强烈的条件，我们要做的就是1.如果是根，检查它是不是最小值。如果不是，必然有次小值
    int findSecondMinimumValue(TreeNode* root)
    {
        if(!root) return false;
        int re=root->val;
        findSecondMinimumValue(root,root->val,re);
        return re>root->val?re:-1;
    }
    
    void findSecondMinimumValue(TreeNode* root,int value,int& result)
    {
        if(!root) return;
        if(root->val>value) 
        {
            if(root->val>result)
            {
                if(result==value)
                    result=root->val;
                return;  
            }
                
            else
                result=root->val;
        }
        else
        {
            findSecondMinimumValue (root->left,value,result);
            findSecondMinimumValue (root->right,value,result);
        }
    }

};
