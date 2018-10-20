// Write a program to find the n-th ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//
// Example:
//
//
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
// Note:  
//
//
// 	1 is typically treated as an ugly number.
// 	n does not exceed 1690.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
//这个必须对着公式写，自己写了两个小时也没搞定
    //找最小值，找到了+1，然后继续下一轮
    /*
    (1) 1x2,  2x2, 2x2, 3x2, 3x2, 4x2, 5x2...
    (2) 1x3,  1x3, 2x3, 2x3, 2x3, 3x3, 3x3...
    (3) 1x5,  1x5, 1x5, 1x5, 2x5, 2x5, 2x5...
    
    */
    int nthUglyNumber(int n)
    {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;//倍数
        while (res.size() < n)
        {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int mn = min(m2, min(m3, m5));
            if (mn == m2) ++i2;
            if (mn == m3) ++i3;
            if (mn == m5) ++i5;
            res.push_back(mn);
        }
        return res.back();
    }


};
