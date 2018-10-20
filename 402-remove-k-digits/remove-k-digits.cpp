// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//
// Note:
//
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
//
//
//
//
// Example 1:
//
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//
//
//
// Example 2:
//
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//
//
//
// Example 3:
//
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string removeKdigits(string num, int k)//1432219,3
    {
        string res = "";
        int n = num.size(), keep = n - k;//7,4
        for (char c : num) 
        {
            while (k && res.size() && res.back() > c) //k>0,res不为空,res的结尾>本字符
            {
                res.pop_back();
                --k;//被排除的数的数量
            }
            res.push_back(c);
        }
        res.resize(keep);
        while (!res.empty() && res[0] == '0') //10200
            res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};
