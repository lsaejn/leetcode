// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//
//
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
//
//
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
//
// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//
// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
//
// Example 1:
//
//
// Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Output: true
//
// Example 2:
//
//
// Input: "1,#"
// Output: false
//
//
// Example 3:
//
//
// Input: "9,#,#,1"
// Output: false
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //"9,3,4,#,#,1,#,#,2,#,6,#,#"
    //每一个元素是数字，就在后面放入两个blank,如果blank够，就是有效的
    bool isValidSerialization(string preorder) 
    {
        int capacity = 1;
        preorder += ",";
        for (int i = 0; i < preorder.size(); ++i) 
        {
            if (preorder[i] != ',') continue;
            if (--capacity < 0) return false;
            if (preorder[i - 1] != '#') capacity += 2;
        }
        return capacity == 0;
    }
};
