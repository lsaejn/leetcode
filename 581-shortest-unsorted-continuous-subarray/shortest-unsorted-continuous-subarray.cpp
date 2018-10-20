// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.  
//
// You need to find the shortest such subarray and output its length.
//
// Example 1:
//
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//
//
//
// Note:
//
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=. 
//
//


class Solution {
public:
    //[2, 6, 4, 8, 10, 9, 15,17,19,18,1,2,3,4,5,20
    //要求是whole array
    //20不需要重排，然后是5，不是剩余里的最大值，返回
    //只不过是另一种说法而已。我们从后遍历每个元素，找到最大值.这个值就是所求
    int findUnsortedSubarray(vector<int>& nums) 
    {
        if(is_sorted(nums.begin(),nums.end())) return 0;
        int i=nums.size()-1;
        for(;i>=0;--i)
        {
            if(nums[i]!=*max_element(nums.rbegin()+nums.size()-1-i,nums.rend()))
                break;          
        }
        
        int j=0;
        for(;j<nums.size();++j)
        {
            if(nums[j]!=*min_element(nums.begin()+j,nums.end()))
                break;       
        }
        cout<<i<<"===="<<j<<endl;

        return abs(j-i)+1;
    }
};
