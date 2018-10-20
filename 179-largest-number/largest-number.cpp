// Given a list of non negative integers, arrange them such that they form the largest number.
//
// Example 1:
//
//
// Input: [10,2]
// Output: "210"
//
// Example 2:
//
//
// Input: [3,30,34,5,9]
// Output: "9534330"
//
//
// Note: The result may be very large, so you need to return a string instead of an integer.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //[3, 30, 34, 5, 9]     95
    //121 12 12112/12121
    string largestNumber(vector<int>& nums)
    {
        string res;
        sort(nums.begin(), nums.end(),
             [](int a, int b)  {
           //return to_string(a)[0]> to_string(b)[0]; //比较第一位还不够！
           return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        }
            );
        for (int i = 0; i < nums.size(); ++i)
            res += to_string(nums[i]);
        return res[0] == '0' ? "0" : res;
    }
};
