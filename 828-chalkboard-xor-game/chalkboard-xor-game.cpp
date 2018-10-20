// We are given non-negative integers nums[i] which are written on a chalkboard.  Alice and Bob take turns erasing exactly one number from the chalkboard, with Alice starting first.  If erasing a number causes the bitwise XOR of all the elements of the chalkboard to become 0, then that player loses.  (Also, we'll say the bitwise XOR of one element is that element itself, and the bitwise XOR of no elements is 0.)
//
// Also, if any player starts their turn with the bitwise XOR of all the elements of the chalkboard equal to 0, then that player wins.
//
// Return True if and only if Alice wins the game, assuming both players play optimally.
//
//
// Example:
// Input: nums = [1, 1, 2]
// Output: false
// Explanation: 
// Alice has two choices: erase 1 or erase 2. 
// If she erases 1, the nums array becomes [1, 2]. The bitwise XOR of all the elements of the chalkboard is 1 XOR 2 = 3. Now Bob can remove any element he wants, because Alice will be the one to erase the last element and she will lose. 
// If Alice erases 2 first, now nums becomes [1, 1]. The bitwise XOR of all the elements of the chalkboard is 1 XOR 1 = 0. Alice will lose.
//
//
//
// Notes: 
//
//
// 	1 <= N <= 1000. 
// 	0 <= nums[i] <= 2^16.
//
//
//  
//


class Solution {
public:
    //思考方式是这样，先排除初始获胜的情况。
    //那么谁都不可能再赢了，直到剩下一个数字，剩下的那个数字属于谁呢？
    //分析：假设alice能赢，当前异或为0，可以把所有数分为两堆。而billy之前删除一个数那么billy之前为什么要删除它呢？
    //只要不删除它，游戏就可以继续。
    //因此谁也不可能赢，直到剩下最后一个元素。
    /*
    All numbers won't be the same. Otherwise xor will be equal to 0
    If all numbers are not the same, It means there are at least 2 different numbers.
    Alice can always erase a number different from current xor.
    So Alice won't never lose this turn at this situation.
    */
    bool xorGame(vector<int>& nums)
    {
        int xo = 0;
        for (int i: nums) //初始即获胜
            xo ^= i;
        return xo == 0 || nums.size() % 2 == 0;
    }
};
