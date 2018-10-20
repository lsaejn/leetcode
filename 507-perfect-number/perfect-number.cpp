// We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself. 
//
// Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
//
//
// Example:
//
// Input: 28
// Output: True
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
//
//
//
// Note:
// The input number n will not exceed 100,000,000. (1e8)
//


class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=0) return false;
        //第一反应是，只能求出它所有的正因子。
        //剩下的就是如何减少计算次数。显然应该从1-num**1/2里计算，例如20，计算1-4即可，%为0，则余数就是令一个数
        set<int> result;
        for(int i=1;i<=sqrt(num);++i)
        {
            if(0==num%i)
            {
                result.insert(i);
                
                result.insert(num/i);
                cout<<i<<" "<<num/i<<endl;
            }
        }
        cout<<accumulate(result.begin(),result.end(),0);
        return 2*num==accumulate(result.begin(),result.end(),0);
    }
};
