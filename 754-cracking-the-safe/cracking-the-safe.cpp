//
// There is a box protected by a password.  The password is n digits, where each letter can be one of the first k digits 0, 1, ..., k-1.
//
// You can keep inputting the password, the password will automatically be matched against the last n digits entered.
//
// For example, assuming the password is "345", I can open it when I type "012345", but I enter a total of 6 digits.
//
// Please return any string of minimum length that is guaranteed to open the box after the entire string is inputted.
//
//
// Example 1:
//
// Input: n = 1, k = 2
// Output: "01"
// Note: "10" will be accepted too.
//
//
//
// Example 2:
//
// Input: n = 2, k = 2
// Output: "00110"
// Note: "01100", "10011", "11001" will be accepted too.
//
//
//
// Note:
//
// n will be in the range [1, 4].
// k will be in the range [1, 10].
// k^n will be at most 4096.
//
//


class Solution 
{
//1.所有的字符串最后都在这个结果里，可以想象成循环的串，所以没有必要在意顺序
public:
    string crackSafe(int n, int k) //n=3,k=4.  031
    {
        string ans = string(n, '0');//000
        unordered_map<string, bool>vis;
        vis[ans] = true;
        dfs(n, k, vis, ans);
        return ans;
    }
    
    //代码还可以，没有必要每次计算pow
    bool dfs(const int n, const int k, unordered_map<string, bool>&vis, string& ans)
    {
        if (vis.size() == pow(k, n)) //已全部构建
            return true;

        for (int i = 0; i < k; ++i)
        {
            ans += '0' + i;//依次添加一个可能的答案
            string pwd = ans.substr(ans.length() - n);//只要最后n个字符串
            if (vis.find(pwd) == vis.end())
            {
                vis[pwd] = 1;
                if (dfs(n, k, vis, ans)) 
                    return true;
                vis.erase(pwd);
            }
            ans.pop_back();
        }
        return false;
    }
};
