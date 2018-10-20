// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
//
// Example 1:
//
// Input: 5
// Output: True
// Explanation:
// The binary representation of 5 is: 101
//
//
//
// Example 2:
//
// Input: 7
// Output: False
// Explanation:
// The binary representation of 7 is: 111.
//
//
//
// Example 3:
//
// Input: 11
// Output: False
// Explanation:
// The binary representation of 11 is: 1011.
//
//
//
// Example 4:
//
// Input: 10
// Output: True
// Explanation:
// The binary representation of 10 is: 1010.
//
//


class Solution {
public:
    //先看符合条件的数：01 10 101 1010 10101 101010 1010101
    //1,2,3,5,10
    //它们+1都不会影响第3位
    //11  100 110
    bool hasAlternatingBits(int n) {
        bitset<32> b(n);
        //0000001
        //biset左高右低
        int idx=31;//我们跳过符号位
        while (idx >=0&&!b.test(idx))
        {
            --idx;//得到第一个1的bit位
        }
        cout<<idx;
        if(idx==-1) return false;//全0
        if(idx==0) return true;//1
        for(int i=0;i<idx;++i)
        {
            if(b[i]==b[i+1])
                return false;
        }
        return true;
        
    }
};
