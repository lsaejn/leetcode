//
// Given an integer, write a function to determine if it is a power of two.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases." />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isPowerOfTwo(int n) {//100 &011=0
        //cool
        return (n > 0) && (!(n & (n - 1)));
    } 
};
