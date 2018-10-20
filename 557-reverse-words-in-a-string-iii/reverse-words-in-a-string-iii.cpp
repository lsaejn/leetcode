// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
// Example 1:
//
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
//
//
//
// Note:
// In the string, each word is separated by single space and there will not be any extra space in the string.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    string reverseWords(string s) {
        //查找空格，找到则反转
        auto begin=s.begin();
        //不需要trim
        auto end=find(begin,s.end(),' ');
        while(end!=s.end())
        {
            reverse(begin,end);
            
            begin=end+1;
            end=find(begin,s.end(),' ');
        }
        reverse(begin,s.end());
        cout<<s<<endl;
        return s;
    }
};
