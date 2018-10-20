// Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
//
// If possible, output any possible result.  If not possible, return the empty string.
//
// Example 1:
//
//
// Input: S = "aab"
// Output: "aba"
//
//
// Example 2:
//
//
// Input: S = "aaab"
// Output: ""
//
//
// Note:
//
//
// 	S will consist of lowercase letters and have length in range [1, 500].
//
//
//  


class Solution {
public:
    //aaaaaabbbccddee->abababacadacaeade
    //思路是两个，一个是深度遍历
    //一个是贪婪插入，找出最多的元素，放入。贪婪算法的思路是每次都把出现次数最多的两个组成对子。
    /*
    首先建立每个字符到其出现次数的映射，然后建立一个大顶堆。每次都取出大顶堆上的两个元素，然后将其加入结果字符串中。如果这两个元素的剩余出现次数还大于0，则我们将其压入大顶堆中继续循环。这样直到大顶堆为空。
我们最后只需要判断用这种贪心算法得到的结果的最后两个字符是否相同，如果相同，则说明无法返回符合条件的结果；否则直接返回结果。算法的时间复杂度是O(nlogn)，空间复杂度是O(n)。
    */
    string reorganizeString(string S) {
        unordered_map<char, int> hash;      // 统计字符出现次数 
        for (auto c : S)  
            ++hash[c];  
        vector<vector<int>> vec;  //vec里存放pair<次数，字符>
        for (auto it = hash.begin(); it != hash.end(); ++it)  
            vec.push_back({it->second, it->first});   
        make_heap(vec.begin(), vec.end());  //根据次数排序
        string ret;  
        while (!vec.empty()) //现在我们开始把vec里的字符依次取出
        {  
            if (vec.size() == 1)
            {  
                ret.insert(ret.end(), vec[0][0], vec[0][1]);  //只剩最后一个字母c，我们在尾部插入n个c
                vec.pop_back();  
            }  
            else 
            {  //小堆的堆顶是最大值
                vector<int> first = vec[0];         // pop the first two chars that appear most  
                pop_heap(vec.begin(), vec.end());  
                vec.pop_back();  //通用算法不会删除元素
                vector<int> second = vec[0];  
                pop_heap(vec.begin(), vec.end());  
                vec.pop_back();  
                ret.push_back(first[1]), ret.push_back(second[1]);  
                if (--first[0] > 0) {               // push the two chars if they have remainings  
                    vec.push_back(first);  
                    push_heap(vec.begin(), vec.end());  
                }  
                if (--second[0] > 0) {  
                    vec.push_back(second);  
                    push_heap(vec.begin(), vec.end());  
                }  
            }  
        }  
        int length = ret.length();  
        if (length > 2 && ret[length - 1] == ret[length - 2]) 
            return "";  
        else   
            return ret;   
    }
};
