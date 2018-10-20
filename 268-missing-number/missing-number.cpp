// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
// Example 1:
//
//
// Input: [3,0,1]
// Output: 2
//
//
// Example 2:
//
//
// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8
//
//
// Note:
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
//


class Solution {
public:
    int missingNumber(vector<int>& nums) {
    //n不定无法使用bitset
    //将nums和完整的数组异或一次,太精妙了，怎么想出来的
            int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
/*
000
001
010
011
100
101
110
111
*/
};
