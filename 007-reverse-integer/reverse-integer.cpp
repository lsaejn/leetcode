// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
//
//
// Input: 123
// Output: 321
//
//
// Example 2:
//
//
// Input: -123
// Output: -321
//
//
// Example 3:
//
//
// Input: 120
// Output: 21
//
//
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//


class Solution {
public:
    int reverse(int x) {
        int ret=1;
        if(x<0) 
        {
            ret=-1;
            x*=-1;
        }
            
            
        long long result=0;
        while(x/10||x)
        {
            result*=10;
            result+=x%10;
            x=x/10;
        }
        result=result*ret;
        if(result>INT32_MAX||result<INT32_MIN)
            return 0;
        else return result;
            
    }
};
