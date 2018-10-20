// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example:
//
//
// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
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
    //构造一棵树相当于找到根节点，再构造左右子树，依次递归
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
    
    //不管如何，指定范围通常都是不错的办法，起码和C++标准库思想类似
    TreeNode* sortedArrayToBST(vector<int>& nums,int begin,int end)
    {
        //因为是有序的，根节点就是中心
        if(begin>end) return nullptr;
        if(begin==end) return new TreeNode(nums[begin]); ;
        auto mid=(end-begin)/2+begin;         

            auto root=new TreeNode(nums[mid]); 
            root->left=sortedArrayToBST(nums,begin,mid-1);
            root->right=sortedArrayToBST(nums,mid+1,end);
            return root;

            
                   
    }
    
};
