// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
// You may assume that the array is non-empty and the majority element always exist in the array.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: 3
//
// Example 2:
//
//
// Input: [2,2,1,1,1,2,2]
// Output: 2
//
//


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //哈希表即可
        //假设一个元素是大数，它遇到不同的就减技术，最后肯定count>=1
        //nnnnmmmmm
        int count=0;
        int elem=nums[0];
        for(auto iter=nums.begin();iter!=nums.end();++iter)
        {
            if(count==0)
            {
                elem=*iter;
                ++count;
            }
            else if(*iter==elem)
            {
               count++; 
            }
                
            else
            {
                count--;
            }
        }
            
        return elem;
    }
};
