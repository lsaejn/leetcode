// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //这个规律看了半天没看懂，毕竟大家都用的封装http://www.cnblogs.com/grandyang/p/4428207.html
    void nextPermutation(vector<int>& num)
    {
        //1,2,3 4
        int i, j, n = num.size();
        for (i = n - 2; i >= 0; --i)
        {
            if (num[i + 1] > num[i]) //从右到左找到第一个降序 1　　2　　7　　4　　3　　1，也就是7
            {
                for (j = n - 1; j > i; --j) //找比i大的数
                {
                    if (num[j] > num[i]) break;
                }
                swap(num[i], num[j]);//交换
                reverse(num.begin() + i + 1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
        
    }
};
