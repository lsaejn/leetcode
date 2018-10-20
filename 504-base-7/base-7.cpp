// Given an integer, return its base 7 string representation.
//
// Example 1:
//
// Input: 100
// Output: "202"
//
//
//
// Example 2:
//
// Input: -7
// Output: "-10"
//
//
//
// Note:
// The input will be in range of [-1e7, 1e7].
//


class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)
            return "0";
        //不断模7再除7，注意符号即可
        int sign=1;
        if(num<0) 
            sign=-1;
        num*=sign;
        string re;
        while(num)
        {
            int i=num%7;
            re+=to_string(i);
            num/=7;
        }
        reverse(re.begin(),re.end());
        if(sign==-1)
            return "-"+re;
        return re;
    }
};
