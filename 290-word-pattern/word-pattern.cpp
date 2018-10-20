// Given a pattern and a string str, find if str follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
// Example 1:
//
//
// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true
//
// Example 2:
//
//
// Input:pattern = "abba", str = "dog cat cat fish"
// Output: false
//
// Example 3:
//
//
// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false
//
// Example 4:
//
//
// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false
//
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //没好说的，split第2个字符串，遍历第一个字符串
        //将对应关系放到一个hashmap里
        //为提搞速度，我们使用move
        int begin=0;
        vector<string> col;
        auto pos=str.find(' ');
        while(pos!=string::npos)
        {
            col.emplace_back(str,begin,pos-begin);
            begin=pos+1;
            pos=str.find(' ',begin);
        }
        col.emplace_back(str,begin,str.size()-begin);//abc adcd
        
        for(int i=0;i!=col.size();++i)
            cout<<col[i]<<endl;
        
        //ok,可以执行下一步了
        if(pattern.size()!=col.size()) return false;
        
        map<char,string> charMap;
        for(int i=0;i!=col.size();++i)
        {
            auto iter=charMap.find(pattern[i]);
            if(iter==charMap.end())//没有key，但string重复
            {
               for (auto it = charMap.begin(); it != charMap.end(); ++it)
               {
                    if (it->second ==col[i]) 
                        return false;
               }
                charMap[pattern[i]]=col[i];
            }
            else if(charMap[pattern[i]]!=col[i])//有key，但string不同
            {
               return false; 
            }                            
        }       
        return true;
    }
};
