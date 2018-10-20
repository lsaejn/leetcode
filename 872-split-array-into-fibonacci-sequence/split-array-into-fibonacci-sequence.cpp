// Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].
//
// Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:
//
//
// 	0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
// 	F.length >= 3;
// 	and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
//
//
// Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
//
// Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.
//
// Example 1:
//
//
// Input: "123456579"
// Output: [123,456,579]
//
//
// Example 2:
//
//
// Input: "11235813"
// Output: [1,1,2,3,5,8,13]
//
//
// Example 3:
//
//
// Input: "112358130"
// Output: []
// Explanation: The task is impossible.
//
//
// Example 4:
//
//
// Input: "0123"
// Output: []
// Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
//
//
// Example 5:
//
//
// Input: "1101111"
// Output: [110, 1, 111]
// Explanation: The output [11, 0, 11, 11] would also be accepted.
//
//
// Note: 
//
//
// 	1 <= S.length <= 200
// 	S contains only digits.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:

    bool backtrack(string &S, int start, vector<int> &nums){        
        int n = S.size();

        if(start >= n && nums.size()>=3)
            return true;

        int maxSplitSize = (S[start]=='0') ? 1 : 10;//为什么是10呢？你想想int32最大值是2147483647
        for(int i=1; i<=maxSplitSize && start+i<=S.size(); i++){
            long long num = stoll(S.substr(start, i));//依次构建2，21，214，2147....
            if(num > INT_MAX)
                return false;
            int sz = nums.size();

            if(sz >= 2 && nums[sz-1]+nums[sz-2] < num)
                return false;
            if(sz<=1 || nums[sz-1]+nums[sz-2]==num){
                nums.push_back(num);
                if(backtrack(S, start+i, nums))//对剩下的依次构建
                    return true;
                nums.pop_back();                
            }
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> nums;
        backtrack(S, 0, nums);
        return nums;
    }
};
