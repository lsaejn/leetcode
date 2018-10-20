//
// Given an integer, write a function to determine if it is a power of two.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    bool isPowerOfTwo(int n) {//100 &011=0
        //cool
        return (n > 0) && (!(n & (n - 1)));
    } 
};
