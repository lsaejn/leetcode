// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
// Example:
//
//
// Input:  [1,2,1,3,2,5]
// Output: [3,5]
//
// Note:
//
//
// 	The order of the result is not important. So in the above example, [5, 3] is also correct.
// 	Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
//
//


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        //101 eor 011= 110, 1/0 1/0 
        //110&010=100
        //101&011
        //110 001
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;//这个是什么意思呢？比如3和5不想等，所以异或之后必然有出现1的位110,比如这里下标1的值是1，说明这个位置上两个数不等
        //我们把nums里所有的数都按这个要求分成两组，一组在下标1位置是1，一组在下标1位置是0，然后分别异或。
        //diff &= -diff就是这个目的，我们得到从低到高位第一个为1的位。因为两个数不等，所以这个位必然存在
        vector<int> res(2, 0);
        for (auto &a : nums)
        {
            if (a & diff) 
                res[0] ^= a;
            else res[1] ^= a;
        }
        return res;
    }
};
