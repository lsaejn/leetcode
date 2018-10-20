// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
//
// You may return any answer array that satisfies this condition.
//
//  
//
//
// Example 1:
//
//
// Input: [3,1,2,4]
// Output: [2,4,3,1]
// The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 5000
// 	0 <= A[i] <= 5000
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=-1;
        int j=A.size();
        while(1)
        {
            while(A[++i]%2==0) if(i==A.size()-1) break;;
            while(A[--j]%2!=0) if(j==0) break;
            if(i>=j) break;
            swap(A[i],A[j]);
        }
        return A;
    }
};
