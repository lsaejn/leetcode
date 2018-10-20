// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment. 
//
// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//
// The encoded string should be as compact as possible.
//
//
//
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    //无所谓了，我们按照层序遍历，或者先序遍历都可以。重要的是自己写一遍
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string re;
        if(root)
        {
            re+=to_string(root->val);
            re+=",";
            re+=serialize(root->left);
            re+=serialize(root->right);
            return re;
            
        }
        else
            return "#,";     
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return  helper(data); 
    }
    
        TreeNode* helper(string& in)
        {
            if(in.empty()) return nullptr;
            int begin=0;
            int end=in.find_first_of(",");
            string val=in.substr(begin,end);
            if(val=="#") 
            {
                in=in.substr(end+1);
                return nullptr;
            }
            auto root=new TreeNode(stoi(val));
            in=in.substr(end+1);
            root->left=helper(in);
            root->right=helper(in);//这里遇到问题，我们每办法知道左子树处理了多少个结点
            return root;       
        }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
