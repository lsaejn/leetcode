// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
// Formally the function should:
//
// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
//
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//
// Example 1:
//
//
// Input: [1,2,3,4,5]
// Output: true
//
//
//
// Example 2:
//
//
// Input: [5,4,3,2,1]
// Output: false
//
//
//
//


class Solution {
public:
    //题目不要求连续，又要求常数空间，我们必须要准备3个数
    //5，4，3，6，5，4，3，7，5，4，8
    //我们准备3个数m1,m2,m3，都等于nums[0],5,5,5,如果num[i]<m1,更新值
    //原理就是，降序可以一直出现，比如4321543216,我们记录降序的最后一个值作为起点即可
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        for (auto a : nums) 
        {
            if (m1 >= a) m1 = a;
            else if (m2 >= a) m2 = a;
            else return true;
        }
        return false;
    }
};
