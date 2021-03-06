// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
//
// Example 1:
//
// Input: [3, 2, 1]
//
// Output: 1
//
// Explanation: The third maximum is 1.
//
//
//
// Example 2:
//
// Input: [1, 2]
//
// Output: 2
//
// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
//
//
//
// Example 3:
//
// Input: [2, 2, 3, 1]
//
// Output: 1
//
// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.
//
//


class Solution {
public:
    //将vector的数放到set里，第三大的数就出来了
    int thirdMax(vector<int>& nums) {
        //需要注意，这里没有重复
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int num : nums) {
            if (num > first) //比第一还大
            {
                third = second;
                second = first;
                first = num;
            } else if (num > second && num < first) //大于第二，但小于第一，取代第二，2-》3
            {
                third = second;
                second = num;
            } else if (num > third && num < second) //大于第三小于第二，取代3.
            {
                third = num;
            }
        }
        return (third == LONG_MIN || third == second) ? first : third;
    }
};
