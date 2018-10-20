// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows) return {};
        
        vector<vector<int>> result(numRows);
        result[0]={1};
        for(int i=1;i<numRows;++i)//i行
        {               
           vector<int> row;
           for(int j=0;j<=i;++j) //第i行，要放i+1个
           {
               if(0==j||i==j)
                   row.push_back(1);                  
               else
               {
                  // if()
                   row.push_back(result[i-1][j-1]+result[i-1][j]);
               }                                               
           }
            result[i]=row;
        }
        return result;
    }
/*
**1**
*1*1*
*121*
13*31
14641
    
*/
};
