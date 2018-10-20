// You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.
//
//
// Example:
// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2
// Explanation: 
// The five points are show in the figure below. The red triangle is the largest.
//
//
//
//
// Notes: 
//
//
// 	3 <= points.length <= 50.
// 	No points will be duplicated.
// 	 -50 <= points[i][j] <= 50.
// 	Answers within 10^-6 of the true value will be accepted as correct.
//
//
//  


class Solution {
public:
    //必须用海伦公式
    double largestTriangleArea(vector<vector<int>>& points) {
        double re=0.0;
        for(int i=0;i!=points.size();++i)
        {
            for(int j=i;j!=points.size();++j)
            {
                for(int k=j;k!=points.size();++k)
                {
                    double a=sqrt(pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2));
                    double b=sqrt(pow(points[i][0]-points[k][0],2)+pow(points[i][1]-points[k][1],2));
                    double c=sqrt(pow(points[k][0]-points[j][0],2)+pow(points[k][1]-points[j][1],2));
                    double p=(a+b+c)*0.5;
                    double area=sqrt(p*(p-a)*(p-b)*(p-c));
                    re=max(re,area);
                }               
            }
        }
        return re;
    }
};
