// In a string S of lowercase letters, these letters form consecutive groups of the same character.
//
// For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
//
// Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
//
// The final answer should be in lexicographic order.
//
//  
//
// Example 1:
//
//
// Input: "abbxxxxzzy"
// Output: [[3,6]]
// Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
//
//
// Example 2:
//
//
// Input: "abc"
// Output: []
// Explanation: We have "a","b" and "c" but no large group.
//
//
// Example 3:
//
//
// Input: "abcdddeeeeaabbbcd"
// Output: [[3,5],[6,9],[12,14]]
//
//  
//
// Note:  1 <= S.length <= 1000" />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        S+='#';
        size_t length=1;
        if(S.empty()) return {};
        vector<vector<int>> re;
        char begin=S[0];
        for(int i=1;i<S.size();++i)
        {
            if(S[i]==begin)
                ++length;
            else
            {
                if(length>2)
                    re.push_back({i-length,i-1});
                begin=S[i];
                length=1;
            }
        }
        return re;
    }
};
