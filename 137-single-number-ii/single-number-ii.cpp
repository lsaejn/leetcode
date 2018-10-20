// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
//
// Input: [2,2,3,2]
// Output: 3
//
//
// Example 2:
//
//
// Input: [0,1,0,1,0,1,99]
// Output: 99
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    
    //要求O(n)时间复杂度，且不用额外内存。。。
    //遍历不可能，排序不可能，只能求和看看sum=3x+y
    //x+y/3=sum/3
    //111 222 333 555 6
//建立一个32位的数字，来统计每一位上1出现的个数，我们知道如果某一位上为1的话，那么如果该整数出现了三次，对3去余为0，我们把每个数的对应位都加起来对3取余，最终剩下来的那个数就是单独的数字
    int singleNumber(vector<int>& nums) {
       vector<int> re(32,0);
        for(int i=0;i!=nums.size();++i)//0~31位
        {
            for(int j=0;j!=32;++j)
            {
                if(nums[i]&1<<j)
                    re[j]++;
            }
        }
        long result=0;
        for(int k=0;k!=32;++k)
        {
            re[k]=re[k]%3;
            if(re[k]!=0)
            result+=pow(2,k);
        }
        
        return result;
    }
};
