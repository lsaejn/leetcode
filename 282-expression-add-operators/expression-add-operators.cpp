// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
//
// Example 1:
//
//
// Input: num = "123", target = 6
// Output: ["1+2+3", "1*2*3"] 
//
//
// Example 2:
//
//
// Input: num = "232", target = 8
// Output: ["2*3+2", "2+3*2"]
//
// Example 3:
//
//
// Input: num = "105", target = 5
// Output: ["1*0+5","10-5"]
//
// Example 4:
//
//
// Input: num = "00", target = 0
// Output: ["0+0", "0-0", "0*0"]
//
//
// Example 5:
//
//
// Input: num = "3456237490", target = 9191
// Output: []
//
//



    // cur: {string} expression generated so far.
    // pos: {int}    current visiting position of num.
    // cv:  {long}   cumulative value so far.
    // pv:  {long}   previous operand value.
    // op:  {char}   previous operator used.
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }
    
    void dfs(string& s, int target, int pos, long cv, long pv, string r, vector<string>& res) {
        if (pos == s.size() && cv == target) {
            res.push_back(r);
            return;
        }
        for (int i = 1; i <= s.size() - pos; i++) {
            string t = s.substr(pos, i);
            if (i > 1 && t[0] == '0') break; // preceding 
            long n = stol(t);
            if (pos == 0) {
                dfs(s, target, i, n, n, t, res);
                continue;
            }
            dfs(s, target, pos+i, cv+n, n, r+"+"+t, res);
            dfs(s, target, pos+i, cv-n, -n, r+"-"+t, res);
            dfs(s, target, pos+i, cv-pv+pv*n, pv*n, r+"*"+t, res);
        }
    }
};
