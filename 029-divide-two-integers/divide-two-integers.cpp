// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: dividend = 10, divisor = 3
// Output: 3
//
// Example 2:
//
//
// Input: dividend = 7, divisor = -3
// Output: -2
//
// Note:
//
//
// 	Both dividend and divisor will be 32-bit signed integers.
// 	The divisor will never be 0.
// 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
//
//


class Solution {
public:
    //,100/4
    //两个数相除，为何会溢出？MAX_INT
    //不能用除法，但是可以移位。
    //2 1
    //5 3
    //5 2
    //5 4
    //11 3 11=3*2+3*1
	int divide(int dividend, int divisor) {

        //处理特殊情况避免复杂运算
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
		if (divisor == 1) return dividend;

		int sign = 1;
		if ((dividend<0&&divisor<0)||(dividend>0&&divisor>0)) sign=1;
		else sign = -1;

		long long dividend_ = dividend; dividend_ =abs(dividend_);
		long long divisor_ = divisor; divisor_ =abs(divisor_);
		if (dividend_<divisor_) return 0;       
		if (dividend_ == divisor_) return 1 *sign;

        
		int sum = 0;
		int count = 0;//divisor*(2**count);       
		vector<long long> powerf(32, 0);//32位整形
		powerf[0] = divisor_;
		while (dividend_>divisor_)//3*(1,2,4,8,16.....)以2进制的形式把3的倍数表示处来
		{
			divisor_ = divisor_ << 1;//divisor*2  
			count++;//1 2
			if (powerf[count] == 0) powerf[count] = divisor_;
		}       
		powerf.erase(find(powerf.begin(),powerf.end(),0),powerf.end());//只是为了好看
		for (int i = powerf.size()-1; i >=0; --i)
		{
			if (dividend_ >= powerf[i])
			{
				dividend_ -= powerf[i];
				sum += pow(2, i);
			}
		}
		return sum*sign;

	}
};
