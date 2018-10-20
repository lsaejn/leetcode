// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
//
//
//
// Example 2:
//
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
//
//
// Note:
//
//
// 	Each element in the result should appear as many times as it shows in both arrays.
// 	The result can be in any order.
//
//
// Follow up:
//
//
// 	What if the given array is already sorted? How would you optimize your algorithm?
// 	What if nums1's size is small compared to nums2's size? Which algorithm is better?
// 	What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
//
//


class Solution {
public:
    //1123445 1234567
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        //remove_reference<decltype(nums1)>::type result;
        vector<int> result;
        for(auto iter=nums1.begin(),iter2=nums2.begin();iter!=nums1.end()&&iter2!=nums2.end();)
        {
            if(*iter==*iter2)
            {
                result.push_back(*iter);
                iter++;
                iter2++;
            }
            else if(*iter<*iter2)
                ++iter;
            else
                ++iter2;           
        }
        return result;        
    }
};
