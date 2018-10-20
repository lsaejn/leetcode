// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
//
// Example 1:
//
// Input: [1, 2, 2, 3, 1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
//
//
//
//
// Example 2:
//
// Input: [1,2,2,3,1,4,2]
// Output: 6
//
//
//
// Note:
// nums.length will be between 1 and 50,000.
// nums[i] will be an integer between 0 and 49,999.
//


class Solution {
public:
    //第一步是找出所有的频率最高的元素
    //对这些元素执行equal_range，但，没有排序，好的，我们使用find_first_of和
    //find_last_of找到这个范围，求出长度
    //得到最大的长度
    
    //但是这个解法比我们的直觉更好，历用哈希表，边插入边查找，对每个元素
    /*
    建立数字出现次数的哈希表，还有就是建立每个数字和其第一次出现位置之间的映射，那么我们当前遍历的位置其实可以看作是尾位置，还是可以计算子数组的长度的。我们遍历数组，累加当前数字出现的次数，如果某个数字是第一次出现，建立该数字和当前位置的映射，如果当前数字的出现次数等于degree时，当前位置为尾位置，首位置在startIdx中取的，二者做差加1来更新结果res；如果当前数字的出现次数大于degree，说明之前的结果代表的数字不是出现最多的，直接将结果res更新为当前数字的首尾差加1的长度，然后degree也更新为当前数字出现的次数
    */
    int findShortestSubArray(vector<int>& nums) 
    {
        int n = nums.size(), res = INT_MAX, degree = 0;
        unordered_map<int, int> m, startIdx;
        for (int i = 0; i < n; ++i) 
        {
            ++m[nums[i]];//数字和它出现的次数
            if (!startIdx.count(nums[i])) 
                startIdx[nums[i]] = i;//数字和它第一次出现的位置
            if (m[nums[i]] == degree) //当前这个数字的次数=degree
            {
                res = min(res, i - startIdx[nums[i]] + 1);//我们得到最短长度
            } 
            else if (m[nums[i]] > degree) //大于degree，前面都白做了
            {
                res = i - startIdx[nums[i]] + 1;//结果更新为当前元素的长度
                degree = m[nums[i]];//degree也更新
            }
        }
        return res;
    }
};
