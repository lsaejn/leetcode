//
// Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.
//
// (Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)
//
//
// Example 1:
//
// Input: N = 10
// Output: 9
//
//
//
// Example 2:
//
// Input: N = 1234
// Output: 1234
//
//
//
// Example 3:
//
// Input: N = 332
// Output: 299
//
//
//
// Note:
// N is an integer in the range [0, 10^9].
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //3453:3444错，是3449
    //333332:  222229
    //stack:1234  1234
    //stack:1237546-1236999
    //stack:1234005-1233999
    //stack:1000005-999999
    //123009
int monotoneIncreasingDigits(int N) {
	//找到第一个非升序的数字，将它和之后元素改为9，然后前面的元素-1.继续判断元素是否升序
	auto s = to_string(N);
	doit(s);
	return stoll(s);
}

void doit(string& s)
{
	int i = 1;
	for (; i != s.size(); ++i)
	{
		int current = s[i] - '0';
		int before = s[i - 1] - '0';
		if (current<before)
		{
			for (int j = i; j != s.size(); ++j)
			{
				s[j] = '9';
			}
			//s[i]='9';
			int replace = before - 1;
			s[i - 1] = replace+'0';
			break;
		}
	}
	if (i == s.size()) return;
	else doit(s);
}
};
