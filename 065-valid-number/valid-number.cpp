// Validate if a given string is numeric.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
//
// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
//
// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //首先它是个数字，可能是小数，是指数。
    //可以是以特殊字母结尾吗？f,d,b之类的？可以测一下
    //可以是负数
    //可以是0000吗？可以是0000e吗？
    bool isNumber(string s) 
    {
        s.erase(0, s.find_first_not_of(' '));
	    s.erase(s.find_last_not_of(' ') + 1);
        int i = 0;
        // 处理正负号
        if ('+' == s[i] || '-' == s[i])
            ++i;
        bool digit = false, dot = false, exp = false;//'.','e','数字'
        for (; i < s.size(); ++i)
        {
            if ('.' == s[i] && !dot) // '.'不能出现2次，'.'前面不能够没有数字。注意.后面可以为空
                 dot = true;
            else if ('e' == s[i] && !exp && digit) // 'e'不能出现2次，'e'前面必须有数字
            {
                // 'e'后面不能出现'.'，'e'后面必须是整数（能够是正的或负的）
                dot = exp = true;
                if (i + 1 < s.size() && ('+' == s[i + 1] || '-' == s[i + 1]))//e后面不能是空
                    ++i;
                if (i + 1 >= s.size() || !(s[i + 1] >= '0' && s[i + 1] <= '9'))
                    return false;
            }
            else if (s[i] >= '0' && s[i] <= '9')
                digit = true;
            else
                break;
            }
            // 跳过后面空格
            return digit && i == s.size();   
    }
};
