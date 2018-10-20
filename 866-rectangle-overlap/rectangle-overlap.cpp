// A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.
//
// Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.
//
// Given two rectangles, return whether they overlap.
//
// Example 1:
//
//
// Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
// Output: true
//
//
// Example 2:
//
//
// Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
// Output: false
//
//
// Notes:
//
//
// 	Both rectangles rec1 and rec2 are lists of 4 integers.
// 	All coordinates in rectangles will be between -10^9 and 10^9.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int _x1 = rec2[0], _y1 = rec2[1], _x2 = rec2[2], _y2 = rec2[3];
        int x = max(x1, _x1);
        int _x = min(x2, _x2);
        int y = max(y1, _y1);
        int _y = min(y2, _y2);
        return x < _x && y < _y;
    }
};
