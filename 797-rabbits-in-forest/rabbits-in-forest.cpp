// In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those answers are placed in an array.
//
// Return the minimum number of rabbits that could be in the forest.
//
//
// Examples:
// Input: answers = [1, 1, 2]
// Output: 5
// Explanation:
// The two rabbits that answered "1" could both be the same color, say red.
// The rabbit than answered "2" can't be red or the answers would be inconsistent.
// Say the rabbit that answered "2" was blue.
// Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
// The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
//
// Input: answers = [10, 10, 10]
// Output: 11
//
// Input: answers = []
// Output: 0
//
//
// Note:
//
//
// 	answers will have length at most 1000.
// 	Each answers[i] will be an integer in the range [0, 999].
//


class Solution {
public:
    //总结一下，如果1说还有一个1，那么就有2个1
    //如果出现1，1，1就是错的,有2个1可以配对，还一个1找不到配对。所以是4
    //那么10，10，10呢？显然，有11只兔子可以给出答案10，
    //也就是说，对于数字n,出现1次n，数组里最多可以有n+1个n。那么最少有几个呢？我们假设n出现m次，那么一共有ceil(m/n+1)*(n+1)
    //我们统计每个数字即可
    int numRabbits(vector<int>& answers) {
        int res = 0;  
        int len = answers.size();  
        if (len == 0)  return 0;  
        unordered_map<int,int> cols;  
        for (int answer : answers)   
            cols[answer]++;  
        for (auto col:cols)
        {  
            int group = col.second/(col.first+1);  
            if (col.second%(col.first+1)== 0)   
                res += group * (col.first+1);  
            else   
                res += (group + 1) * (col.first+1);    
        }  
        return res;  
    }  
};
