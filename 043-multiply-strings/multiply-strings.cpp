// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
// Note:
//
//
// 	The length of both num1 and num2 is < 110.
// 	Both num1 and num2 contain only digits 0-9.
// 	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// 	You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这道题是体力题
    //12345 * 99
    string multiply(string num1, string num2) 
    {
        /*我的写法是字符串的做法，很显然，把求出的每位的和都放到数组里，比较方便，最后才处理进位
        if(num1=="0"||num2=="0") return "0";
        vector<string> result;
		for (int i = num1.size()-1; i >= 0; --i)//num1里的每个数
		{
			string re;
			int pro = 0;
			for (int j = num2.size()-1; j >= 0; --j)
			{
				auto bit = (num1[i] - '0')*(num2[j] - '0') + pro;
				pro = bit/10;
				bit %= 10;
                re.push_back(bit+'0');
			}
			if (pro != 0)
				re += to_string(pro);
			int n = i;
			while (num1.size()-1-n>0)
			{
				re = "0" + re;
				n++;
			}
			result.push_back(re);			
		}
		int max = 0;
		for (int k = 0; k != result.size(); ++k)
			max = result[k].size() > max ? result[k].size() : max;

		string sumstr;
		int pro = 0;
		for (int m = 0; m != max; ++m)//第m位
		{
			int sum = 0;
			for (int n = 0; n != result.size(); ++n)//n元素
			{
				if (m <= result[n].size() - 1)//有这个位
				{
					sum += result[n][m] - '0';
				}
			}
            sum += pro;
			pro = sum / 10;
			sum = sum % 10;
			sumstr.push_back(sum+'0');
		}
		while (pro)
		{
			pro %= 10;
			sumstr.push_back(pro+'0');

		}
		reverse(sumstr.begin(), sumstr.end());
		return sumstr;*/
        string res;
        int n1 = num1.size(), n2 = num2.size();
        int k = n1 + n2 - 2, carry = 0;
        vector<int> v(n1 + n2, 0);
        for (int i = 0; i < n1; ++i) 
        {
            for (int j = 0; j < n2; ++j) 
            {
                v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i < n1 + n2; ++i) 
        {
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }
        int i = n1 + n2 - 1;
        while (v[i] == 0) 
            --i;
        if (i < 0) return "0";
        while (i >= 0) 
            res.push_back(v[i--] + '0');
        return res;
        
    }

};
