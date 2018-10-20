//
// A string S of lowercase letters is given.  We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
//
//
// Example 1:
//
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
//
//
//
// Note:
// S will have length in range [1, 500].
// S will consist of lowercase letters ('a' to 'z') only.
//


class Solution {
public:
//画个图，本质上就是合并相交的区间
    
    //ababcbaca defegde hijhklij bpmn
    //但是一次遍历似乎也可以a找到最后一个相同的a，下标8，它们必然要组成1个区间。
    //d呢？它在前面没出现，所以继续本次循环即可。
    //d找到d，然后是e，e找最后一个e，在之前的区间里
    vector<int> partitionLabels(string S) 
    {
        if (S.empty()) return {};
        vector<int> result;
        for (int i = 0; i<S.size(); ++i)
        {
            int begin = i;
            int end = S.find_last_of(S[i]);
            if (end == string::npos)
            {
                result.push_back(S.size() - i);
                return result;
            }
            for (int j = i + 1; j<=end; ++j)
            {
                if (S.find_first_of(S[j])<j) continue;
                int begin2 = j;
                int end2 = S.find_last_of(S[j]);
                if (end2 <= end)
                    continue;
                else if (end == string::npos)
                {
                    result.push_back(S.size() - i);
                    return result;
                }
                else
                    end = end2;
            }
            result.push_back(end - i + 1);
            i = end;
        }
        return result;
    }
};
