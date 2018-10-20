//
// We are given N different types of stickers.  Each sticker has a lowercase English word on it.
//
// You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.
//
// You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
//
// What is the minimum number of stickers that you need to spell out the target?  If the task is impossible, return -1.
//
//
// Example 1:
// Input:
// ["with", "example", "science"], "thehat"
//
//
// Output:
// 3
//
//
// Explanation:
// We can use 2 "with" stickers, and 1 "example" sticker.
// After cutting and rearrange the letters of those stickers, we can form the target "thehat".
// Also, this is the minimum number of stickers necessary to form the target string.
//
//
// Example 2:
// Input:
// ["notice", "possible"], "basicbasic"
//
//
// Output:
// -1
//
//
// Explanation:
// We can't form the target "basicbasic" from cutting letters from the given stickers.
//
//
// Note:
// stickers has length in the range [1, 50].
// stickers consists of lowercase English words (without apostrophes).
// target has length in the range [1, 15], and consists of lowercase English letters.
// In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.
// The time limit may be more challenging than usual.  It is expected that a 50 sticker test case can be solved within 35ms on average.
//


class Solution {   
public:
    //虽然排序花费了一定的时间，但是s.find(target[0]) == string::npos这一句太神奇了，set_intersection之后，s.find(target[0]) == string::npos
    //淘汰掉大部分没用的单词
    //我之前是直接开始删除元素，其实稍微比较一下就可以排除大量无效的比较
    int minStickers(vector<string>& stickers, string target) {
        unordered_map<string, int> memo;
        memo[""] = 0;
        sort(target.begin(), target.end());
        vector<string> sorted_stk = stickers;
        for (string & s : sorted_stk) 
        {
            sort(s.begin(), s.end());
            string same;
            set_intersection(s.begin(), s.end(), target.begin(), target.end(), back_inserter(same));//无关的字母全部去掉
            s=same;         
        }        
        const int cap = target.size() + 1;
        find_min_stickers(target, cap, memo, sorted_stk);
        return memo[target] == cap ? -1 : memo[target];
    }
    
private:
    int find_min_stickers(string target, const int cap, unordered_map<string, int> & memo, vector<string> & stickers) {
        if (memo.find(target) != memo.end()) 
            return memo[target];
        int res = cap;
        for (string & s : stickers) 
        {
            if (s.find(target[0]) == string::npos) continue;//!beautiful!!!，至少找到一个！
            string diff;
            set_difference(target.begin(), target.end(), s.begin(), s.end(), back_inserter(diff));//1 2 5 5 5 9 minus 2 5 7 is: 1 5 5 9
            res = min(res, find_min_stickers(diff, cap, memo, stickers) + 1);
        }
        return memo[target] = res;
    }
};
