// Given an array A, partition it into two (contiguous) subarrays left and right so that:
//
//
// 	Every element in left is less than or equal to every element in right.
// 	left and right are non-empty.
// 	left has the smallest possible size.
//
//
// Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.
//
//  
//
// Example 1:
//
//
// Input: [5,0,3,8,6]
// Output: 3
// Explanation: left = [5,0,3], right = [8,6]
//
//
//
// Example 2:
//
//
// Input: [1,1,1,0,6,12]
// Output: 4
// Explanation: left = [1,1,1,0], right = [6,12]
//
//
//  
//
//
// Note:
//
//
// 	2 <= A.length <= 30000
// 	0 <= A[i] <= 10^6
// 	It is guaranteed there is at least one way to partition A as described.
//
//
//
//  
//


class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int max_of_left=INT32_MIN;
        int min_of_right=INT32_MAX;
        vector<pair<int,int>> dp(A.size(),{0,0});
        for(int i=0;i!=A.size();++i)
        {
            max_of_left=max(max_of_left,A[i]);
            dp[i].first=max_of_left;
            min_of_right=min(min_of_right,A[A.size()-1-i]);
            dp[A.size()-1-i].second=min_of_right;
        }
        for(int i=0;i!=dp.size();++i)
            if(dp[i].first<=dp[i+1].second)
                return i+1;
        return -1;
    }
};
