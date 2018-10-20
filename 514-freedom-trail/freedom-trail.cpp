//
// In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door. 
//
//
//
// Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.
//
// Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button.
//
//
// At the stage of rotating the ring to spell the key character key[i]:
//
// You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
//
// If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
//
//
//
//
// Example:
//
//
//
//
//
// Input: ring = "godding", key = "gd"
// Output: 4
// Explanation: For the first key character 'g', since it is already in place, we just need 1 step to spell this character.  For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo". Also, we need 1 more step for spelling. So the final output is 4.
//
//
//
// Note:
//
// Length of both ring and key will be in range 1 to 100.
// There are only lowercase letters in both strings and might be some duplcate characters in both strings.
// It's guaranteed that string key could always be spelled by rotating the string ring.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //和之前140题一样，不保存中间结果将会超时
    int findRotateSteps(string ring, string key)
    {
        //注意，一定有答案
        unordered_map<string,int> col;
        return dfs(ring, key, 0, 0, col ) + key.length();//旋转的次数+按钮的次数
    }
    
    //两个id对应当前要找的索引和当前12点所指的索引
    int dfs(string& rings, string& keys, int keyIdx, int ringIdx, unordered_map<string,int>& ht)
    {
        if(keyIdx==keys.length()) //全部找完
            return 0;
        string key = to_string(keyIdx)+"-"+to_string(ringIdx);
        if(ht.find(key)!=ht.end())
        {
            //cout<<"finder"<<endl;
           return ht[key]; 
        }
            
        int minDistance = INT32_MAX;
        for(int i=0;i<rings.length();++i) //我们依旧从0开始找，只不过最后的距离 求绝对值比如abcded停留在e，要找a，其实是距离是abs(0-4),然后mod-4即可
        {
            if(rings[i]!=keys[keyIdx]) 
                continue;
            int diff = std::abs(i-ringIdx);
            int distance = std::min(diff, static_cast<int>(rings.length())-diff) + dfs(rings, keys, keyIdx+1, i, ht);
            minDistance = std::min(minDistance, distance);
        }
        ht[key]=minDistance;
        return minDistance;
    }
};
