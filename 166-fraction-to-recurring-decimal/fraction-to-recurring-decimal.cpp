// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
// If the fractional part is repeating, enclose the repeating part in parentheses.
//
// Example 1:
//
//
// Input: numerator = 1, denominator = 2
// Output: "0.5"
//
//
// Example 2:
//
//
// Input: numerator = 2, denominator = 1
// Output: "2"
//
// Example 3:
//
//
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"
//
//


class Solution {
public:
    //4/9，4/333，还有边界条件。这道题太TMD难了，可见没有套路才是最大的套路。。。。
    //纯粹得数学题才是最难的
    string fractionToDecimal(int numerator, int denominator) 
    {
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        long long num = abs( (long long)numerator );
        long long den = abs( (long long)denominator );
        long long out = num / den;
        long long rem = num % den;//4/333
        
        
        string res = to_string(out);//整数部分        
        if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;       
        if (rem == 0) return res;
               
        res += ".";
        string s = "";
        int pos = 0;
        unordered_map<long long, int> m;
        while (rem != 0)//这个除法是怎么做的呢？4/333.4/333得0，先放4，0.再40/333得0，放0，再用400/333得1，余67，670/333=2，余4，发现重复，结束
        {//就和我们人类手除一样，至不过我个人都是先补0，所以出现了思维真空
            if (m.find(rem) != m.end())
            {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;//4，0
            s += to_string((rem * 10) / den);//
            rem = (rem * 10) % den;
            ++pos;
        }
        return res + s;
        
        
    }
    
    //int getCd(int numerator,int denominator)
};
