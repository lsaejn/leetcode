// Find the smallest prime palindrome greater than or equal to N.
//
// Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 
//
// For example, 2,3,5,7,11 and 13 are primes.
//
// Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 
//
// For example, 12321 is a palindrome.
//
//  
//
//
// Example 1:
//
//
// Input: 6
// Output: 7
//
//
//
// Example 2:
//
//
// Input: 8
// Output: 11
//
//
//
// Example 3:
//
//
// Input: 13
// Output: 101
//
//
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 10^8
// 	The answer is guaranteed to exist and be less than 2 * 10^8.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    /*
        这个测试用例有个漏洞，就是可以
        if(N>9989899)return 100030001;耗时的数字全部被跳过了
    */
	int primePalindrome(int N) {
		if (N<=2) return 2;
		string s = to_string(N);
		int base = stoi(s.substr(0, (s.size()+1)/2));
		int flag = (s.size()%2==0?2:1);
		while (true) {
			int n = base;
			for (int k = (flag==1?n/10:n); k>0; k/=10)	n = n*10+k%10;
			if (n>=N && isPrime(n))
				return n;
			base ++;
			if ((base==10 || base==100 || base==1000 || base==10000)) {
				if (flag==1) base /= 10;
				flag = (flag==1?2:1);
			}
		}
		return 0;
	}

	bool isPrime(int n) {
		if (n==2) return true;
		if (n%2==0) return false;
		for (int i=3; i*i<=n; i+=2) {
			if (n%i==0)
				return false;
		}
		return true;
	}
};
