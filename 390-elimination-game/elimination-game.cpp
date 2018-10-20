//
// There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
//
// Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
//
// We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
//
// Find the last number that remains starting with a list of length n.
//
// Example:
//
// Input:
// n = 9,
// 1 2 3 4 5 6 7 8 9
// 2 4 6 8
// 2 6
// 6
//
// Output:
// 6
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //http://www.cnblogs.com/grandyang/p/5860706.html
    int lastRemaining(int n) {
    /*第一次从左往右删除的时候，奇数都被删掉了，剩下的都是偶数。如果我们对所有数都除以2，那么得到一个1到n/2的新数列。下一次我们从右往左删出，那么返回的结果应该是调用递归的结果lastRemaining(n / 2)在数组1到n/2之间的镜像。何为镜像，比如1, 2, 3, 4这个数字，2的镜像就是3, 1的镜像是4，参见代码如下：
    //假设序列为a={1,2,3,4,5,6,7,8,9}
    //f(a)={2,4,6,8}
    //b=f(a)/2={1,2,3,4}
    //f(reverse(b))
    */
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2)); 
    }
};
