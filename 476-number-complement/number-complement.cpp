// Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
//
// Note:
//
// The given integer is guaranteed to fit within the range of a 32-bit signed integer.
// You could assume no leading zero bit in the integer’s binary representation.
//
//
//
// Example 1:
//
// Input: 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
//
//
//
// Example 2:
//
// Input: 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
//
//


class Solution {
public:
    //给定数是32bit有符号的正整数,注意，C++的bitset低位在左
    //此外，没有前导的0
    //bitset查位有点抽象，但还是靠感觉通过
    int findComplement(int num)
    {
        std::bitset<32> b1(static_cast<unsigned long>(num));
        size_t idx = 0;
        size_t begin=b1.size()-1;
        while(begin>=0&&!b1.test(begin))
        {
            --begin;
        }
        while (idx <= begin) 
        {
            if(b1.test(idx))
                b1[idx]=0;
            else 
                b1[idx]=1;
            ++idx;
        }
        return b1.to_ulong();
        
        
        
    }
};
