// You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
//
// The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.
//
// Example 1:
//
// Input: Binary tree: [1,2,3,4]
//        1
//      /   \
//     2     3
//    /    
//   4     
//
// Output: "1(2(4))(3)"
// Explanation: Originallay it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)".
//
//
//
// Example 2:
//
// Input: Binary tree: [1,2,3,null,4]
//        1
//      /   \
//     2     3
//      \  
//       4 
//
// Output: "1(2()(4))(3)"
// Explanation: Almost the same as the first example, except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
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
//如果我们不用递归，而用栈,这会使得输出括号变得非常困难
//因为要记录自己是不是存在父节点。正常的想法是将加括号交给自己父节点，在压栈的时候进行处理。
//用两个栈，一个压节点，一个压字符串。
//我们模拟一下1入栈，1出栈，2，3入栈，2出栈，4，5，入栈。1-> 1 )3()2() 
//我们需要在2入栈的时候先放一个()
string left_S="(";
string right_S=")";
class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t) return "";
        string re;
        if(t)
            re+=to_string(t->val);
        if(t->left&&t->right)
            re+=left_S+tree2str(t->left)+")("+tree2str(t->right)+")";
        else if(t->left&&!t->right)
            re+=left_S+tree2str(t->left)+")";
        else if(!t->left&&t->right)
            re+=left_S+tree2str(t->left)+")("+tree2str(t->right)+")";
        return re;       
    }
private:
    string re;
};
