// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
//
// Example 1:
//
//
// Input: 11
// Output: 3
// Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
//
//
// Example 2:
//
//
// Input: 128
// Output: 1
// Explanation: Integer 128 has binary representation 00000000000000000000000010000000
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int hammingWeight(uint32_t n) {//1110 1101-1100
        auto x=n;
if(!x) return 0;
        int count=0;
        //右移x比左移1要优化许多。
            while(x)//0010 0001  0000好像记得是x&x-1,但是试了半天没用。
            {
                if(x&1==1)//本质就是最后一位和1比
                    count++;
                x=x>>1;
            }
        return count;
    }
};
