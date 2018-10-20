//
// Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once. 
//
//
// Example 1:
//
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
//
//
//
// Example 2:
//
// Input: [3,3,7,7,10,11,11]
// Output: 10
//
//
//
// Note:
// Your solution should run in O(log n) time and O(1) space.
//
//


class Solution {
public:
    //我们看看异或是不是有用001 001 011 011 100 100 101 101 111
    int singleNonDuplicate(vector<int>& nums) {
        //if(nums.empty()) return 0;
        int i=nums[0];
        for(int j=1;j!=nums.size();++j)
        {
            i=i^nums[j];
        }
        return i;
    }
};
