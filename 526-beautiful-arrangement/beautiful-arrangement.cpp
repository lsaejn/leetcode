//
// Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:
//
// The number at the ith position is divisible by i.
// i is divisible by the number at the ith position.
//
//
//
//
// Now given N, how many beautiful arrangements can you construct?
//
//
// Example 1:
//
// Input: 2
// Output: 2
// Explanation: 
// The first beautiful arrangement is [1, 2]:
// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
// The second beautiful arrangement is [2, 1]:
// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
//
//
//
// Note:
//
// N is a positive integer and will not exceed 15.
//
//


class Solution {
public:
    //N不超过15，先看看用permutation
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) 
            nums[i] = i + 1;
        return helper(N, nums);
    }
    int helper(int n, vector<int>& nums) {
        if (n <= 0) return 1;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (n % nums[i] == 0 || nums[i] % n == 0) //比纯粹的permutation快在这里，有效的数字才进行迭代
            {
                swap(nums[i], nums[n - 1]);//非常棒的思路，我们不是要严格的permutation，只是要所有的排列
                res += helper(n - 1, nums);
                swap(nums[i], nums[n - 1]);
            }
        }
        return res;
    }
};
