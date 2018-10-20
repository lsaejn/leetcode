//
// Given an integer n, return 1 - n in lexicographical order.
//
//
//
// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
//
//
//
// Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //我们希望一次遍历就放入元素。1,10,100,1000,1001,1002,100
    //1,10,11....19 or 1,10,100,101...109,11...110,111....19
    //2,20,21.....29
    //9,90......99
    vector<int> lexicalOrder(int n) 
    {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; ++i) 
        {
            res[i] = cur;
            if (cur * 10 <= n)
            {
                cur *= 10;
            } 
            else 
            {
                if (cur >= n) 
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0) cur /= 10;
            }
        }
        return res;
    }
};
