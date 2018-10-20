// You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.
//
// If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
//
// Operations allowed:
//
//
// 	Fill any of the jugs completely with water.
// 	Empty any of the jugs.
// 	Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
//
//
// Example 1: (From the famous "Die Hard" example)
//
//
// Input: x = 3, y = 5, z = 4
// Output: True
//
//
// Example 2:
//
//
// Input: x = 2, y = 6, z = 5
// Output: False
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //x和y可以组合出多少数？x=3,y=5
    //y=2,x=3
    //y=2,x=0
    //y=0,x=2;
    //y=5,x=2;
    //y=4,x=3;
    //4 = (-2) * 3 + 2 * 5
    bool canMeasureWater(int x, int y, int z) {
    //z = m * x + n * y
    //ax + by = d的解为 d = gcd(x, y)
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
        
    int gcd(int x, int y) 
    {
        return y == 0 ? x : gcd(y, x % y);
    }
};
