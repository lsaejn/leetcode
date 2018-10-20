// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//  
//
//
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//  
//
// Example:
//
//
// Input: [2,1,5,6,2,3]
// Output: 10
//
//


class Solution {
public:
    //本质上我们要找一个区间，使得区间长度x*min(height(x1),...,height(x))最大
    //显然，如果发生了递减，我的高度要重新计算
    int largestRectangleArea(vector<int>& heights)
    {
        int res = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!s.empty() && heights[s.top()] >= heights[i]) 
            {
                int cur = s.top(); 
                s.pop();
                res = max(res, heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }
};
