// A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//
// For example, these are arithmetic sequence:
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
//
// The following sequence is not arithmetic. 1, 1, 2, 5, 7 
//
//
// A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
//
// A slice (P, Q) of array A is called arithmetic if the sequence:
//     A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
//
// The function should return the number of arithmetic slices in the array A. 
//
//
// Example:
//
// A = [1, 2, 3, 4]
//
// return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //对于一个最长的等差数列1,2,3,4,5,6 有递推公式a(n+1)=a(n)+n-2.相当于1-5的所有组合，加上以6结尾的组合
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        if(A.size()<3) return 0;
        int stride=A[1]-A[0];
        int result=0;
        int count=2;
        for(int i=2;i!=A.size();++i)
        {
            if(A[i]-A[i-1]==stride)
            {
                ++count;
                if(i+1==A.size())
                {
                    result+=(count-1)*(count-2)*0.5;
                }
            }
            else
            {
                if(count>=3)
                    result+=(count-1)*(count-2)*0.5;
                stride=A[i]-A[i-1];
                count=2;
            }           
        }
        return result;
    }
};
