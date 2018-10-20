//
// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
// Example:
// Given num = 16, return true.
// Given num = 5, return false.
//
//
// Follow up: Could you solve it without loops/recursion?
//
// Credits:Special thanks to @yukuairoy  for adding this problem and creating all test cases." />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<1) return false;
        return std::log10(num)/log10(4)==static_cast<int>(log10(num)/log10(4));
        
    }
};
