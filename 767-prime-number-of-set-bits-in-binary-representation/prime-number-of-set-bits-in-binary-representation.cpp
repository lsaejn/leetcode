//
// Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.
//
// (Recall that the number of set bits an integer has is the number of 1s present when written in binary.  For example, 21 written in binary is 10101 which has 3 set bits.  Also, 1 is not a prime.)
//
//
// Example 1:
// Input: L = 6, R = 10
// Output: 4
// Explanation:
// 6 -> 110 (2 set bits, 2 is prime)
// 7 -> 111 (3 set bits, 3 is prime)
// 9 -> 1001 (2 set bits , 2 is prime)
// 10->1010 (2 set bits , 2 is prime)
//
//
// Example 2:
// Input: L = 10, R = 15
// Output: 5
// Explanation:
// 10 -> 1010 (2 set bits, 2 is prime)
// 11 -> 1011 (3 set bits, 3 is prime)
// 12 -> 1100 (2 set bits, 2 is prime)
// 13 -> 1101 (3 set bits, 3 is prime)
// 14 -> 1110 (3 set bits, 3 is prime)
// 15 -> 1111 (4 set bits, 4 is not prime)
//
//
// Note:
// L, R will be integers L <= R in the range [1, 10^6].
// R - L will be at most 10000.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        if(L>R) return 0;
        int sum=0;
        for(int i=L;i<=R;++i)
        {
            bitset<32> b(i);
            int num=b.count();
            if(isPrime(num))
            {
               sum++; 
            }  
        }
        return sum;
        
    }
    
    bool isPrime(int n)
    {
        
                if(n==1)
            return false;
        if(n==2||n==3)
            return true;
        for(int i=2;i<=sqrt(n)+1;++i)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }

};
