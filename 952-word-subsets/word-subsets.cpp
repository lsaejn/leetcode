// We are given two arrays A and B of words.  Each word is a string of lowercase letters.
//
// Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".
//
// Now say a word a from A is universal if for every b in B, b is a subset of a. 
//
// Return a list of all universal words in A.  You can return the words in any order.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
// Output: ["facebook","google","leetcode"]
//
//
//
// Example 2:
//
//
// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
// Output: ["apple","google","leetcode"]
//
//
//
// Example 3:
//
//
// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
// Output: ["facebook","google"]
//
//
//
// Example 4:
//
//
// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
// Output: ["google","leetcode"]
//
//
//
// Example 5:
//
//
// Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
// Output: ["facebook","leetcode"]
//
//
//  
//
// Note:
//
//
// 	1 <= A.length, B.length <= 10000
// 	1 <= A[i].length, B[i].length <= 10
// 	A[i] and B[i] consist only of lowercase letters.
// 	All words in A[i] are unique: there isn't i != j with A[i] == A[j].
//
//
//
//
//
//


//对于每个字符串的要求，其实就是最多的那个
class Solution
{
    public:
        vector<string> wordSubsets(vector<string>& A, vector<string>& B)
        {
            vector<int> hash(26,0);
            vector<int> hash_max(26,0);
            for(auto s:B)
            {
                hash.assign(26,0);
                for(auto c:s)
                    hash_max[c-'a']=++hash[c-'a'] > hash_max[c-'a']?hash[c-'a']:hash_max[c-'a'];
            }            
            hash.assign(26,0);
            vector<string> result;
            int flag = 1;
            for(auto s:A)
            {
                flag = 1;
                hash.assign(26,0);
                for(auto c:s)
                    hash[c-'a'] ++;
                for(int i = 0 ;i < 26;i ++)
                {
                    if(hash[i] < hash_max[i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)    result.push_back(s);
            }
            return result;
        }
};
