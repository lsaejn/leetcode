// Implement int sqrt(int x).
//
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
//
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
// Example 1:
//
//
// Input: 4
// Output: 2
//
//
// Example 2:
//
//
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.
//
//


class Solution {
public:
    int mySqrt(int x) {
        //对半肯定不是最快的，但是题目也要求，那就凑合写了
        if(x==0) return 0;
        if(x==1) return 1;
        long num=x;
        long long begin=0;
        long long end=x;
        while(begin<end){
            long long mid=(end+begin)/2;//这里越界，弄了半天
            if(mid*mid==x) return mid;
            if(mid*mid>x)
            {
                end=mid;
            }
            else
            {
                begin=mid;
            } 
            if(begin+1==end)
                return begin;
        }
        return begin;
        
    }
};
