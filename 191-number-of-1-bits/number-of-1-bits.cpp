// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
//
// Example 1:
//
//
// Input: 11
// Output: 3
// Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
//
//
// Example 2:
//
//
// Input: 128
// Output: 1
// Explanation: Integer 128 has binary representation 00000000000000000000000010000000
//
//


class Solution {
public:
    int hammingWeight(uint32_t n) {//1110 1101-1100
        auto x=n;
if(!x) return 0;
        int count=0;
        //右移x比左移1要优化许多。
            while(x)//0010 0001  0000好像记得是x&x-1,但是试了半天没用。
            {
                if(x&1==1)//本质就是最后一位和1比
                    count++;
                x=x>>1;
            }
        return count;
    }
};
