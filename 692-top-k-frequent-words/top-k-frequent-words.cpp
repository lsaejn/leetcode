// Given a non-empty list of words, return the k most frequent elements.
// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
//
// Example 1:
//
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
//
//
//
// Example 2:
//
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
//
//
//
// Note:
//
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
//
//
//
// Follow up:
//
// Try to solve it in O(n log k) time and O(n) extra space.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //O(n log k),只有用优先队列。
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> col;
        for(auto& elem:words)
            col[elem]++;
        auto compare=[](const pair<string,int>&e1,const pair<string,int>&e2){
            if(e1.second>e2.second) return true;//lik,4>like,5
            if(e1.second==e2.second&&e1.first<e2.first) return true;//like,4>lika,4
               return false;
        };
        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(compare)> minHop(compare);
        for(auto& elem:col)
        {
            if (minHop.size() == k)
            {
                if (compare(elem,minHop.top()))
                {
                    minHop.pop();
                    minHop.push(elem);
                }
            }
            else 
                minHop.push(elem);	
        }
        vector<string> result;
        while(!minHop.empty())
        {
            auto elem=minHop.top();
            result.push_back(elem.first);
            minHop.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
