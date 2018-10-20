// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
//
// Example:
//
//
// Input: 13
// Output: 6 
// Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
//
//


class Solution {
public:
    //1-9：1
    //10-99：1x,x1
    //100-999:1xx,x1x,xx1
    //199 1xx 100 01x 20 0x1 20=140
    //599 1xx 100 x1x 60 xx1 60=220
    //562 1xx 100 x1x 52 xx1 56=
    int countDigitOne(int n) {
                int res = 0, a = 1, b = 1;
        while (n > 0) {
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};
