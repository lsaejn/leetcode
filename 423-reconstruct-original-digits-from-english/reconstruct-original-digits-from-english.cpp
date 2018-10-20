// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
//
// Note:
//
// Input contains only lowercase English letters.
// Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
// Input length is less than 50,000.
//
//
//
// Example 1:
//
// Input: "owoztneoer"
//
// Output: "012"
//
//
//
// Example 2:
//
// Input: "fviefuro"
//
// Output: "45"
//
//


class Solution {
public:
    
    //one:o two:w three:h four:u five:v six:x seven:s eight:g nine:..
    //
    string originalDigits(string s) 
    {
        string res = "";
        vector<int> counts(128, 0), nums(10, 0);
        for (char c : s) 
            ++counts[c];
        nums[0] = counts['z'];
        nums[2] = counts['w'];
        nums[4] = counts['u'];
        nums[6] = counts['x'];
        nums[8] = counts['g'];
        nums[1] = counts['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = counts['h'] - nums[8];
        nums[5] = counts['f'] - nums[4];
        nums[7] = counts['s'] - nums[6];
        nums[9] = counts['i'] - nums[6] - nums[8] - nums[5];
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                res += (i + '0');
            }
        }
        return res;
    }
};
