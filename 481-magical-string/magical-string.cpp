//
// A magical string S consists of only '1' and '2' and obeys the following rules:
//
//
// The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string S itself.
//
//
//
// The first few elements of string S is the following:
// S = "1221121221221121122……"
//
//
//
// If we group the consecutive '1's and '2's in S, it will be:
//
//
// 1   22  11  2  1  22  1  22  11  2  11  22 ......
//
//
// and the occurrences of '1's or '2's in each group are:
//
//
// 1   2	   2    1   1    2     1    2     2    1    2    2 ......
//
//
//
// You can see that the occurrence sequence above is the S itself. 
//
//
//
// Given an integer N as input, return the number of '1's in the first N number in the magical string S.
//
//
// Note:
// N will not exceed 100,000.
//
//
//
// Example 1:
//
// Input: 6
// Output: 3
// Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public://通过计数1组和2组的个数，又能生成相同的字符串
    /*
    根据第三个数字2开始往后生成数字，此时生成两个1，然后根据第四个数字1，生成一个2，再根据第五个数字1，生成一个1，以此类推，生成的数字1或2可能通过异或3来交替生成，在生成的过程中同时统计1的个数即可，
    */
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        int res = 1, head = 2, tail = 3, num = 1;
        vector<int> v{1, 2, 2};
        while (tail < n) {
            for (int i = 0; i < v[head]; ++i) {
                v.push_back(num);
                if (num == 1 && tail < n) ++res;
                ++tail;
            }
            num ^= 3;
            ++head;
        }
        return res;
    }
};
