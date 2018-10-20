// In a deck of cards, each card has an integer written on it.
//
// Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:
//
//
// 	Each group has exactly X cards.
// 	All the cards in each group have the same integer.
//
//
//  
//
// Example 1:
//
//
// Input: [1,2,3,4,4,3,2,1]
// Output: true
// Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
//
//
//
// Example 2:
//
//
// Input: [1,1,1,2,2,2,3,3]
// Output: false
// Explanation: No possible partition.
//
//
//
// Example 3:
//
//
// Input: [1]
// Output: false
// Explanation: No possible partition.
//
//
//
// Example 4:
//
//
// Input: [1,1]
// Output: true
// Explanation: Possible partition [1,1]
//
//
//
// Example 5:
//
//
// Input: [1,1,2,2,2,2]
// Output: true
// Explanation: Possible partition [1,1],[2,2],[2,2]
//
//
//
//
//
//
//
// Note:
//
//
// 	1 <= deck.length <= 10000
// 	0 <= deck[i] < 10000
//
//
//
//
//
//
//  
//
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<=1) return false; 
        map<int,int> mp;
        for(auto elem:deck) mp[elem]++;
        vector<int> s;
        for(auto &elem:mp)  s.push_back(elem.second);
        for(int i=1;i!=s.size();++i)
            if((gcd(s[i],s[i-1]))==1)   return false;
        return true;
    }
    
    int gcd(int m,int n)
    {
        int re;
        while(n>0)
        {
            int re=m%n;
            m=n;
            n=re;
        }
        return m;
    }
};
