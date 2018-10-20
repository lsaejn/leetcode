//
// Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.
//
// Letters also wrap around.  For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
//
//
// Examples:
//
// Input:
// letters = ["c", "f", "j"]
// target = "a"
// Output: "c"
//
// Input:
// letters = ["c", "f", "j"]
// target = "c"
// Output: "f"
//
// Input:
// letters = ["c", "f", "j"]
// target = "d"
// Output: "f"
//
// Input:
// letters = ["c", "f", "j"]
// target = "g"
// Output: "j"
//
// Input:
// letters = ["c", "f", "j"]
// target = "j"
// Output: "c"
//
// Input:
// letters = ["c", "f", "j"]
// target = "k"
// Output: "c"
//
//
//
// Note:
//
// letters has a length in range [2, 10000].
// letters consists of lowercase letters, and contains at least 2 unique letters.
// target is a lowercase letter.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //把元素放进去，再排序。当然也可以查找第一个大于目标的数
    //注意是sorted
    char nextGreatestLetter(vector<char>& letters, char target) {
        

        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? *letters.begin() : *it;
    }
};
