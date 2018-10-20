// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
//
// Note:
// A naive algorithm of O(n2) is trivial. You MUST do better than that.
//
// Example:
//
//
// Input: nums = [-2,5,-1], lower = -2, upper = 2,
// Output: 3 
// Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    /*
    给了我们一个数组，又给了我们一个下限和一个上限，让我们求有多少个不同的区间使得每个区间的和在给定的上下限之间
    [-2, 5, -1],-2,2
    [0,0]=nums[0]=-2
    [2,2]=nums[2]=-1
    [0,2]=nums[0,1,2]=2
    */
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //区间必定是连续递增的，我们遍历，同时记录总和，同时算出区间数
        //模拟一下-2, 5, -1，-2, 5, -1，-2, 5, -1
        //sums=0,sum=-2找sum[i]在[-4,0]的区间长度,res+=1;
        //sums=-2,0,sum=3,找[1,5]的区间长度,res+=0;
        //sums=-2,0,3,sum=2,找[0,4]的长度，res+=2
        //sums=-2,0,2,3;break
        //解释:lower <= sum[i] - sum[j] <= upper 的j能形成一个区间[j, i]满足题意
        //即sum[j]满足sum[i]-upper<=sum[j]<=sum[i]-lower,sums已排序，那么lower_bound(sum - upper)返回sums里<=该数的迭代器
        //upper_bound(sum - lower)返回大于该数的迭代器,数量刚好是二者只差。比如我们查找数组{-1,0,1,2,3,5,6}里位于[0,4]的数
        //iter1=&0,iter2=&5,数量是&5-&0=5-1=4
        int res = 0;
        long long sum = 0;
        multiset<long long> sums;
        sums.insert(0);
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            res += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
            sums.insert(sum);
        }
        return res;
    } 
};
