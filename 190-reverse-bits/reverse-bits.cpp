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
// If this function is called many times, how would you optimize it?" />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


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
