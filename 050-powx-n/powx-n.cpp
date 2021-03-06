// Implement pow(x, n), which calculates x raised to the power n (xn).
//
// Example 1:
//
//
// Input: 2.00000, 10
// Output: 1024.00000
//
//
// Example 2:
//
//
// Input: 2.10000, 3
// Output: 9.26100
//
//
// Example 3:
//
//
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
//
//
// Note:
//
//
// 	-100.0 < x < 100.0
// 	n is a 32-bit signed integer, within the range [−231, 231 − 1]
//
//


class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0) return 1;
        double half = myPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        else if (n > 0) return half * half * x;
        else return half * half / x;
    }
};
/*正常的代码通不过，vs上ok，但精度和答案不对
if (0 == n)
			return 1;
		int sig = 1;
		if (n<0)
		{
			n *= -1;
			sig = -1;
		}

		long double result = 1;;
		while (n)
		{
			result *= x;
			--n;
		}
		if(sig>0)
		return result;
		else 
		 return 1/result;
*/


