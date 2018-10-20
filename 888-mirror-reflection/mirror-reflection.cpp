// There is a special square room with mirrors on each of the four walls.  Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.
//
// The square room has walls of length p, and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.
//
// Return the number of the receptor that the ray meets first.  (It is guaranteed that the ray will meet a receptor eventually.)
//
//  
//
//
// Example 1:
//
//
// Input: p = 2, q = 1
// Output: 2
// Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.
//
//
//
//
// Note:
//
//
// 	1 <= p <= 1000
// 	0 <= q <= p
//
//


long long gcd(long long a, long long b) 
{
    while (b)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

class Solution
{
public:
    int mirrorReflection(int p, int q)//4,2
    {
        long long x = 0, y = 0;
        // 最小公倍数
        long long g = p * q / gcd(p, q);//4
        y = g / p;//1
        x = g / q;//2
        x=p/gcd(p, q);
        y=q/gcd(p, q);
        if (x % 2 == 1 && y % 2 == 0) 
            return 0;
        else if (x % 2 == 1 && y % 2 == 1) 
            return 1;
        else if (x % 2 == 0 && y % 2 == 1) 
            return 2;        
        return 0;
    }
};
