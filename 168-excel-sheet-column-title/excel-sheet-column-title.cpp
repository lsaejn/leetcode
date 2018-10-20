// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
// For example:
//
//
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
//     ...
//
//
// Example 1:
//
//
// Input: 1
// Output: "A"
//
//
// Example 2:
//
//
// Input: 28
// Output: "AB"
//
//
// Example 3:
//
//
// Input: 701
// Output: "ZY"
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    const string ALPHAB=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string convertToTitle(int n) {
        
        string result;
        while (n) //27-52 AA-AZ 53 BA //如果在这里做除法，没办法处理26的倍数，采用模后除的办法12345%10/10%10/10
        {
            --n;
            result +=(n%26 + 'A');
            n /= 26;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
