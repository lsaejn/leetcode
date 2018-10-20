// Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
//
// Input: [2,2,1]
// Output: 1
//
//
// Example 2:
//
//
// Input: [4,1,2,1,2]
// Output: 4
//
//


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=nums[0];
        for(int i=1;i!=nums.size();++i){
            result ^= nums[i];
        
        }
        return result;
        /*最开始是想到水王那个，但是没有辅助空间走不通，相同抵消，很快便想到位运算，写一个式子，差不多就得到结果了
            012342310
            00000000
            00000001
            00000010
            00000011
            00000100        
        */        
    }
};
