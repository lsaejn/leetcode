//
// Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
//
//
//
// We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
//
//
// Example 1:
//
// Input: [4,2,3]
// Output: True
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
//
//
//
// Example 2:
//
// Input: [4,2,1]
// Output: False
// Explanation: You can't get a non-decreasing array by modify at most one element.
//
//
//
// Note:
// The n belongs to [1, 10,000].
//


class Solution {
public:
    /*
    The strategy is to lower a[i-1] to match a[i] if possible - (a[i-2] not exist or no smaller than a[i]);
otherwise rise a[i] to match a[i-1].

2 Examples:
 0  ...  i ...
 1 1 2 4[2]5 6  - in this case we can just raise a[i] to 4;
         4
 1 1 2[4]2 3 4  - in this case lower a[i-1] is better;
       2
       */
    bool checkPossibility(vector<int>& a) {
        bool modified = false;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] < a[i - 1]) {
                if (modified++) return false;
                (i - 2 < 0 || a[i - 2] <= a[i]) ? a[i - 1] = a[i] : a[i] = a[i - 1];
            }
        }
        return true;
    }

};
