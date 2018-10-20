// Count the number of prime numbers less than a non-negative number, n.
//
// Example:
//
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //用递归的话超出内存限制，我们准备一个容器表示从1到n-1是不是质数

        int countPrimes(int n) 
    {
        vector<bool> num(n - 1, true);
        num[0] = false;
            
        int res = 0, limit = sqrt(n);
            //我们假设全是质数，那么哪些不是呢？
            //1~256里.1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
        for (int i = 2; i <= limit; ++i) 
        {
            if (num[i - 1])
            {
                //n的倍数肯定为false
                //这个算法快在提前把false的元素标记处来
                for (int j = i * i; j < n; j += i) {
                    num[j - 1] = false;
                }
            }
        }
        for (int j = 0; j < n - 1; ++j) {
            if (num[j]) ++res;
        }
        return res;
    }
};
