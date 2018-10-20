// We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, and spaces, and ended up with the string S.  Return a list of strings representing all possibilities for what our original coordinates could have been.
//
// Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".
//
// The final answer list can be returned in any order.  Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)
//
//
// Example 1:
// Input: "(123)"
// Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
//
//
//
// Example 2:
// Input: "(00011)"
// Output:  ["(0.001, 1)", "(0, 0.011)"]
// Explanation: 
// 0.0, 00, 0001 or 00.01 are not allowed.
//
//
//
// Example 3:
// Input: "(0123)"
// Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
//
//
//
// Example 4:
// Input: "(100)"
// Output: [(10, 0)]
// Explanation: 
// 1.0 is not allowed.
//
//
//  
//
// Note: 
//
//
// 	4 <= S.length <= 12.
// 	S[0] = "(", S[S.length - 1] = ")", and the other elements in S are digits.
//
//
//  


class Solution {
public:
	//为了让逻辑更加清楚，我们需要一个函数，将string用.分开，返回它所有的合法字符串
	vector<string> ambiguousCoordinates(string S) {
        if(S.size()<=2) return {};
        S=S.substr(1,S.size()-2);
		vector<string> result;
		for (int i = 0; i != S.size(); ++i)
		{
			string left = S.substr(0, i + 1);
			auto right = S.substr(i + 1);
			auto vec1 = helper(left);
            auto vec2 = helper(right);
			for (int j = 0; j != vec1.size(); ++j)
			    for (int k = 0; k != vec2.size(); ++k)
					result.push_back("(" +vec1[j] + ", " + vec2[k]+")");
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}

	vector<string> helper(string& s)
	{

		int len = s.size();
		if (len == 0) return {};
		if (len == 1) return { s };
		if (len == 2 && s == "00") return {};
		if (s.back() == '0')
		{
			if (s[0] == '0')
				return {};
			else return { s };
		}
		else
		{
			if (s[0] == '0')
			{
					s.insert(1, ".");
					return { s };
			}
			else
			{
				vector<string> re;
				re.push_back(s);
				for (int i = 1; i<s.size(); ++i)
				{
					string t = s;
					t.insert(i, ".");
					re.push_back(t);
				}
				return re;
			}
		}
        return {};//这里逻辑似乎不对
	}

};
