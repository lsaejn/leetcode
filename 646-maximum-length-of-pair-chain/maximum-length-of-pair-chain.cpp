//
// You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
//
//
//
// Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion. 
//
//
//
// Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
//
//
//
// Example 1:
//
// Input: [[1,2], [2,3], [3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4]
//
//
//
// Note:
//
// The number of given pairs will be in the range [1, 1000].
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int nPairs=pairs.size();
        sort(pairs.begin(),pairs.end(),[](const vector<int> &v1,const vector<int> &v2){
                if(v1[1]==v2[1])
                    return v1[0]<=v2[0];
                else
                    return v1[1]<v2[1]; 
             });
        int dp[nPairs];//如何设置dp成了关键，我们假设dp就是当前位置能放置的最多数对链
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<nPairs;i++)
        {
            for(int j=i-1;j>=0;j--)
                //往前查找，只要能够接在pairs[i]之前的pairs[j]，dp[i]=dp[j]+1
                //因为pairs[i][1]在升序排序的基础上，pairs[i][0]也按升序排序，所以仅需找到离pairs[i]最近的pairs[j]即可执行break
                if(pairs[j][1]<pairs[i][0])
                {
                    dp[i]=dp[j]+1;
                    break;
                }
            //由于pairs[i][1]是按升序排序的，所以必有dp[i]>=dp[i-1]
            dp[i]=max(dp[i-1],dp[i]);//ok，chose or not
        }
        return dp[nPairs-1];
    }
};
