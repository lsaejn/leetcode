// Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
//
// Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
//
// So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
//
// Note:
//
// Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
// Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
// As long as a house is in the heaters' warm radius range, it can be warmed.
// All the heaters follow your radius standard and the warm radius will the same.
//
//
//
// Example 1:
//
// Input: [1,2,3],[2]
// Output: 1
// Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
//
//
//
// Example 2:
//
// Input: [1,2,3,4],[1,4]
// Output: 1
// Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        //根据题意，heart应该是再house的范围种
        //求出相邻heart能不能覆盖中间区域，记录其最小distance，这些distance里最大的值
        //即为所求
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            //遍历每个房子，查找第一个不小于house的heart的位置
            auto pos = upper_bound(heaters.begin(), heaters.end(), house);
            //以2为例，dist1是2到4的距离，dist2是2到1的距离
            int dist1 = (pos == heaters.end()) ? INT_MAX : *pos - house;//end()最大心在左边
            int dist2 = (pos == heaters.begin()) ? INT_MAX : house - *(--pos);
            //对于2，显然1就能覆盖它，4离得较远
            //res是所有房子的最低需求。求这么距离的最大值
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};
