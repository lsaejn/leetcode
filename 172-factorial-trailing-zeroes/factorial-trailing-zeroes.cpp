// Given an integer n, return the number of trailing zeroes in n!.
//
// Example 1:
//
//
// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
//
// Example 2:
//
//
// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
//
// Note: Your solution should be in logarithmic time complexity.
//


class Solution {
public:
    //求一个数的阶乘末尾0的个数
    //如果这个数很大，那么我们求阶层肯定会越界
    //想要得到10，就必须有5
    //11！=11*10*9*8*7*6*5*4*2*1，可以遍历[1,n]有几个(5i)就有几个0
    //这里有个陷阱比如25=5*5，125=5*5*5，所以等于计算所有5i里的元素，可以分解为多少个5
    /*
    int trailingZeroes(int n) {
        int result=0;
        for(int i=1;i<=n;++i)
        {
            int num=0;
            int j=i;
            while(0==j%5)//5的倍数
            {              
                j=j/5;
                num++;
            }
            result+=num;
            
        }
        return result;
                
    }*/
    //这个更简单，直接计算含5的个数即可，比如1-100里面有多少个5的倍数呢呢？是的 20个，但是还有25的倍数，4个，即，100/25=20/5 ，所以是24个
    //这解释了下面的公式
        int trailingZeroes(int n)
        {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
