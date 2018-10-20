// Print a binary tree in an m*n 2D string array following these rules: 
//
//
// The row number m should be equal to the height of the given binary tree.
// The column number n should always be an odd number.
// The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them. 
// Each unused space should contain an empty string "".
// Print the subtrees following the same rules.
//
//
// Example 1:
//
// Input:
//      1
//     /
//    2
// Output:
// [["", "1", ""],
//  ["2", "", ""]]
//
//
//
//
// Example 2:
//
// Input:
//      1
//     / \
//    2   3
//     \
//      4
// Output:
// [["", "", "", "1", "", "", ""],
//  ["", "2", "", "", "", "3", ""],
//  ["", "", "4", "", "", "", ""]]
//
//
//
// Example 3:
//
// Input:
//       1
//      / \
//     2   5
//    / 
//   3 
//  / 
// 4 
// Output:
//
// [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
//  ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
//  ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
//  ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
//
//
//
// Note:
// The height of binary tree is in the range of [1, 10].
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
    我们先来看第一行，由于根结点只有一个，所以第一行只需要插入一个数字，不管这一行多少个位置，我们都是在最中间的位置插入结点值。下面来看第二行，我们仔细观察可以发现，如果我们将这一行分为左右两部分，那么插入的位置还是在每一部分的中间位置，这样我们只要能确定分成的部分的左右边界位置，就知道插入结点的位置了，所以应该是使用分治法的思路。在递归函数中，如果当前node不存在或者当前深度超过了最大深度直接返回，否则就给中间位置赋值为结点值，然后对于左子结点，范围是左边界到中间位置，调用递归函数，注意当前深度加1；同理对于右子结点，范围是中间位置加1到右边界，调用递归函数，注意当前深度加1
    
    */
    vector<vector<string>> printTree(TreeNode* root)
    {
        int h = getHeight(root), w = pow(2, h) - 1;
        vector<vector<string>> res(h, vector<string>(w, ""));
        helper(root, 0, w - 1, 0, h, res);//
        return res;
    }
    //@1 root,@2 leftpos,@3 rightpos @4当前高度 @5树高 @6 result
    void helper(TreeNode* node, int i, int j, int curH, int height, vector<vector<string>>& res) {
        if (!node || curH == height) return;
        res[curH][(i + j) / 2] = to_string(node->val);
        helper(node->left, i, (i + j) / 2, curH + 1, height, res);
        helper(node->right, (i + j) / 2 + 1, j, curH + 1, height, res);
    }
    
    int getHeight(TreeNode* node) 
    {
        if (!node) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
};
