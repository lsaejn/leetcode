// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
//
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
//
// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
//
// 	I can be placed before V (5) and X (10) to make 4 and 9. 
// 	X can be placed before L (50) and C (100) to make 40 and 90. 
// 	C can be placed before D (500) and M (1000) to make 400 and 900.
//
//
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
//
// Example 1:
//
//
// Input: 3
// Output: "III"
//
// Example 2:
//
//
// Input: 4
// Output: "IV"
//
// Example 3:
//
//
// Input: 9
// Output: "IX"
//
// Example 4:
//
//
// Input: 58
// Output: "LVIII"
// Explanation: C = 100, L = 50, XXX = 30 and III = 3.
//
//
// Example 5:
//
//
// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）
    //左减的数字有限制，仅限于I、X、C
    //左减数字必须为一位
    //右加数字不可连续超过三位，比如14写成XIV，而非XIIII
    //同一数码最多只能出现三次，如40不可表示为XXXX，而要表示为XL
    //385=VXLD,485=IVD,585
    string intToRoman(int num)
    {
        string res = "";
        char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int value[] = {1000, 500, 100, 50, 10, 5, 1};
        
        for (int n = 0; n < 7; n += 2) {
            int x = num / value[n];
            if (x < 4) //本位出现次数必须小于4
            {
                for (int i = 1; i <= x; ++i) 
                    res += roman[n];
            } 
            else if (x == 4) //等于4，注意，每一位都可以用5和1表示，>4:5+x,<=4用5-x
                res = res + roman[n] + roman[n - 1];
            else if (x > 4 && x < 9) 
            {
                res += roman[n - 1];//先加5
                for (int i = 6; i <= x; ++i)
                    res += roman[n];//比5大几就加几
                
            }
            else if (x == 9) 
                res = res + roman[n] + roman[n - 2];
            num %= value[n];            
        }
        return res;
        
    }
};
