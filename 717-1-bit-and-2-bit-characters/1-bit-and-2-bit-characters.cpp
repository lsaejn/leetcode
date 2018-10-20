// We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).  
//
// Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.
//
// Example 1:
//
// Input: 
// bits = [1, 0, 0]
// Output: True
// Explanation: 
// The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
//
//
//
// Example 2:
//
// Input: 
// bits = [1, 1, 1, 0]
// Output: False
// Explanation: 
// The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
//
//
//
// Note:
// 1 <= len(bits) <= 1000.
// bits[i] is always 0 or 1.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = 0;
        //[1, 1, 1, 0],[1,1,1,0,0],[1,1,1,1,0,1]
        while (i < n - 1)
        {
            if (bits[i] == 0) ++i;//最后到n-1
            else i+= 2;//最后是i==n
        }
        return i == n - 1;
    }
};
