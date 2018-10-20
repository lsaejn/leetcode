// Write a function that takes a string as input and returns the string reversed.
//
// Example 1:
//
//
//
// Input: "hello"
// Output: "olleh"
//
//
//
// Example 2:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: "amanaP :lanac a ,nalp a ,nam A"
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //以为有陷阱，但是。。。没有陷阱也是一种陷阱。。。
    string reverseString(string s) {
        reverse(s.begin(),s.end());
        return s;
        
    }
};
