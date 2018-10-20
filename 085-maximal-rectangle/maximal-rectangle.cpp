// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example:
//
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6
//
//


class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        vector<int> height;//每一层的直方图
        for (int i = 0; i < matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);//更新直方图
            }
            res = max(res, largestRectangleArea(height));//使用之前的函数
        }
        return res;
    }
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);//最后面添加一个0
        for (int i = 0; i < height.size(); ++i) 
        {
            if (s.empty() || height[s.top()] <= height[i]) 
                s.push(i);//栈内存放递增的索引
            else
            {
                int tmp = s.top();
                s.pop();
                res = max(res, height[tmp] * (s.empty() ? i : (i - s.top()-1)));
                --i;
            }
        }
        return res;
    }
};
