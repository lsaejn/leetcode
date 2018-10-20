// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//
// Example 1:
//
//
// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o  
// +------------->
// 0  1  2  3  4
//
//
// Example 2:
//
//
// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    //本题通过率只有1/10...太吓人了，一般都是写一次，改2-3次通过。
    int maxPoints(vector<Point>& points) 
    {
        int res = 0;
        for (int i = 0; i < points.size(); ++i)//遍历所有点
        {
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) //再找一个点，确定一条直线
            {
                int cnt = 0;
                long long x1 = points[i].x, y1 = points[i].y;
                long long x2 = points[j].x, y2 = points[j].y;
                if (x1 == x2 && y1 == y2)
                {
                    ++duplicate; //相同点,这个是什么意思呢？相同点一定在一条直线上。我们求出和点1相同的点
                    continue;
                }
                for (int k = 0; k < points.size(); ++k)// 
                {
                    int x3 = points[k].x, y3 = points[k].y;
                    if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0) 
                        ++cnt;
                }
                res = max(res, cnt);
            }
            res = max(res, duplicate);
        }
        return res;
    }
};
