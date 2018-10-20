// Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.
//
// Do NOT use system's Math.random().
//
//
//
//
//  
//
//
// Example 1:
//
//
// Input: 1
// Output: [7]
//
//
//
// Example 2:
//
//
// Input: 2
// Output: [8,4]
//
//
//
// Example 3:
//
//
// Input: 3
// Output: [8,1,10]
//
//
//  
//
// Note:
//
//
// 	rand7 is predefined.
// 	Each testcase has one argument: n, the number of times that rand10 is called.
//
//
//  
//
// Follow up:
//
//
// 	What is the expected value for the number of calls to rand7() function?
// 	Could you minimize the number of calls to rand7()?
//
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() 
    {
        int sum = 0;
        for (int i = 0; i < 10; ++i) 
            sum += rand7();
        return sum % 10 + 1;
    }
};
