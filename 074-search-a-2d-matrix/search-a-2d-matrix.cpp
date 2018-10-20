// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //现在要2分查找，很显然，matrix从0到m*n-1,我们找到中点的pos和矩阵x,y的转换公式即可
    //毫无难度
    //0-m*n-1,x=pos/4,y=pos%4
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int begin=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int end=m*n;
        while(begin<end)
        {
            int mid=begin+(end-begin)/2;
            cout<<mid<<endl;
            if(target==matrix[mid/n][mid%n]) return true;
            else if(matrix[mid/n][mid%n]<target)
                begin=mid+1;
            else
                end=mid;           
        }
        return false;
        
    }
};
