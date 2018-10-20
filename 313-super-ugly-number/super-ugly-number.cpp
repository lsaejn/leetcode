// Write a program to find the nth super ugly number.
//
// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
//
// Example:
//
//
// Input: n = 12, primes = [2,7,13,19]
// Output: 32 
// Explanation: [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]  is the sequence of the first 12 
//              super ugly numbers given primes = [2,7,13,19] of size 4.
//
// Note:
//
//
// 	1 is a super ugly number for any given primes.
// 	The given numbers in primes are in ascending order.
// 	0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
// 	The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
//
//


class Solution {
public:
    //这个题是有规则的http://www.cnblogs.com/grandyang/p/4743837.html
    //再解释一下，再上题里，首先是3个列表，一开始是都乘以1
    //得到最小的数2，2就是第2个乘数.开始第2次更新，2*2=4，其他不变，得到3是最小值，3就是所有数要乘的第3个乘数，
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        vector<int> res{1};//最开始只有一个丑数1
        vector<int> idx(primes.size(), 0);
        vector<int> tmp;
        for (int i = 0; i < primes.size(); ++i) 
            tmp.push_back(res[idx[i]] * primes[i]);//所有数乘以自己应该乘的那个丑数
        while (res.size() < n) 
        {          
            int mn = INT_MAX;
            auto iter = min_element(tmp.begin(),tmp.end());//找到最小值
            mn=*iter;
            res.push_back(mn);
            for (int i = 0; i < primes.size(); ++i)
                if (mn == tmp[i]) 
                {
                    ++idx[i];      //丑数索引+1
                    tmp[i]=primes[i]*res[idx[i]];
                }
            
        }
        return res.back();
    }
};
