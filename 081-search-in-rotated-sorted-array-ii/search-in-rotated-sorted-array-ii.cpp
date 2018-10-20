// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
//
// Example 2:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
// Follow up:
//
//
// 	This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// 	Would this affect the run-time complexity? How and why?
//
//


class Solution {
public:
    bool search(vector<int>& A, int target) {
        if (A.empty()) return false;
        
        int left =0;
        int right=A.size()-1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (A[mid] == target) return true;
            else if (A[mid] < A[right])
            {
                if (A[mid] < target && A[right] >= target) 
                    left = mid + 1;
                else 
                    right = mid - 1;
            } 
            else if (A[mid] > A[right])
            {
                if (A[left] <= target && A[mid] > target) 
                    right = mid - 1;
                else left = mid + 1;
            } 
            else --right;
        }
        return false;
    }
};
