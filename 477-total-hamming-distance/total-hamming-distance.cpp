// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
// Now your job is to find the total Hamming distance between all pairs of the given numbers.
//
//
// Example:
//
// Input: 4, 14, 2
//
// Output: 6
//
// Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
// showing the four bits relevant in this case). So the answer will be:
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
//
//
//
// Note:
//
// Elements of the given array are in the range of 0  to 10^9
// Length of the array will not exceed 10^4. 
//
//


class Solution {
public:
    //0的个数乘以1的个数
    int totalHammingDistance(vector<int>& nums)
    {
        int res = 0;
        for (int i = 0; i != sizeof(int)*8; ++i)
        {
            int sum_1 = 0;
            for (int j = 0; j != nums.size(); ++j)
            {
                bitset<sizeof(int)*8> b = nums[j];
                if (b[i] == 1)
                    ++sum_1;
            }
            res += sum_1 * (nums.size() - sum_1);
        }
        return res;
    }
};
//0000 0101 0011 1001
//0001 1100 1010 0011
