// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// Example:
//
//
// Input: 
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Output: 4
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //由于我们从左向右从上向下边遍历，如果本元素是1，向下找到最长的高，向右找宽,得到较小值
    //然后要求我右下角的点是个较小值-1的正方形，这样来递推。
    int maximalSquare(vector<vector<char> >& matrix) 
    {
        if(matrix.size()==0) return 0;
        if(matrix[0].size()==0) return 0;
        vector<vector<int>> wh(matrix.size(),vector<int>(matrix[0].size()));
        int res=0;
        for (int i = 0; i < matrix.size(); ++i) 
        {
            for (int j = 0; j < matrix[0].size(); ++j) 
            {              
                if(matrix[i][j]=='1')
                {
                    int wid=1;
                    int hei=1;
                    int j1=j;
                    int i1=i;
                    while(j1+1<matrix[0].size()&&matrix[i][j1+1]=='1') {++wid;j1++;} 
                    while(i1+1<matrix.size()&&matrix[i1+1][j]=='1') {++hei; i1++;}
                    wh[i][j]=min(wid,hei);
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) 
        {
            for (int j = 0; j < matrix[0].size(); ++j) 
            {
                if(matrix[i][j]=='1')
                {
                    int len=wh[i][j];
                    for(int slen=len;slen>=1;--slen)
                    {
                       if(isSquareArea(matrix,wh,i+1,j+1,slen-1))
                       {
                          res=max(res,slen*slen); 
                          break;
                       } 
                    }

                }
            }
        }
        return res;
    }
    bool isSquareArea(vector<vector<char> >& matrix,vector<vector<int>>&wh, int x,int y,int k) //给定左顶点x,y,检查它是否能形成边长为k的正方形
    {
        if(k<=0) return true;
        if(x==matrix.size()||y==matrix[0].size()) return false;
        if(wh[x][y]<k) return false;
        else{
            if(isSquareArea(matrix,wh,x+1,y+1,k-1)) return true;
            else return false;
        }

    }
};
