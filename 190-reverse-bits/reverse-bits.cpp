// Reverse bits of a given 32 bits unsigned integer.
//
// Example:
//
//
// Input: 43261596
// Output: 964176192
// Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
//              return 964176192 represented in binary as 00111001011110000010100101000000.
//
//
// Follow up:
// If this function is called many times, how would you optimize it?


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //前16位右移，后16位左移，然后再或
        //00000010100101000001111010011100
        //高位第0位右移31，1位移动29，2移27，15位移动1
        //第16位左移1位，第31位左移31
        /*还有更简单的写法，直接把数字移到0位
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res |= ((n >> i) & 1) << (31 - i);
        }
        return res;
        */
        uint32_t result=0;
        int bit=1;
        for(int i=0;i!=32;++i)
        {
            if(i<16)//低位
            {
              uint32_t temp=n;
              temp=temp&bit;
             temp=temp<<(31-2*i);
              result|=temp;

                
            }
            else if(i>=16)
            {
              uint32_t temp=n;
              temp=temp&(1<<i);
              temp=temp>>(2*i-31);
              result|=temp;
                
            }
            bit=bit<<1;
        }
        return result;
        
    }
    
};
