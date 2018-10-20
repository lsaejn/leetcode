// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
//
// Note: The algorithm should run in linear time and in O(1) space.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: [3]
//
// Example 2:
//
//
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]
//


class Solution {
public:
    //我看出来了，这种以线性时间运行的查找，基本上都以计数为方法，空间永远是INT32_MAX,但是太大了。
    //使用投票计数。
    //如果和候选者相同，则票数+1，不同则减1，如果候选人没有票数，则被新的候选者取代
    vector<int> majorityElement(vector<int>& nums) {
                vector<int> res;
        int m = 0, n = 0, cm = 0, cn = 0;
        for (auto &a : nums) {
            if (a == m) ++cm;
            else if (a ==n) ++cn;
            else if (cm == 0) m = a, cm = 1;
            else if (cn == 0) n = a, cn = 1;
            else --cm, --cn;
        }
        cm = cn = 0;
        for (auto &a : nums) {
            if (a == m) ++cm;
            else if (a == n) ++cn;
        }
        if (cm > nums.size() / 3) res.push_back(m);
        if (cn > nums.size() / 3) res.push_back(n);
        return res;
    }
};
