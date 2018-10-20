// Given an integer, return its base 7 string representation.
//
// Example 1:
//
// Input: 100
// Output: "202"
//
//
//
// Example 2:
//
// Input: -7
// Output: "-10"
//
//
//
// Note:
// The input will be in range of [-1e7, 1e7].
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)
            return "0";
        //不断模7再除7，注意符号即可
        int sign=1;
        if(num<0) 
            sign=-1;
        num*=sign;
        string re;
        while(num)
        {
            int i=num%7;
            re+=to_string(i);
            num/=7;
        }
        reverse(re.begin(),re.end());
        if(sign==-1)
            return "-"+re;
        return re;
    }
};
