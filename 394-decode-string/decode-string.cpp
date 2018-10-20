//
// Given an encoded string, return it's decoded string.
//
//
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//
//
// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
//
// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
//
//
// Examples:
//
// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
//
//


class Solution {
public:
    //唯一的难度在于嵌套的处理，和字符串混在一起
    //我只能说，这里的代码写的很恶心，非常，非常地恶心！！！
    string decodeString(string s)
    {
		string res = "";
		string temp;
		stack<string> S;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')//如果下一个也是数字
			{
				auto pos = s.find_first_of("[]", i);
				S.push(s.substr(i, pos - i));
				i = pos - 1;
			}
			else if (s[i] == '[')
				S.push("[");
			else if (s[i] == ']')
			{
				auto k = S.top();
				S.pop();
				S.pop();
				auto num = S.top();
				S.pop();
				auto temp = k;
				for (int j = 0; j < stoi(num)-1; ++j)
					k+= temp;
				if (S.empty()) S.push(k);
				else if (S.top().find_first_of("[]1234567890") == string::npos) S.top()+= k;
                else S.push(k);
			}
			else//字符串
			{
				auto pos = s.find_first_of("[]1234567890", i);
				if (pos != string::npos)
				{
					if (!S.empty() && S.top().find_first_of("[]1234567890") == string::npos)
						S.top() += s.substr(i, pos - i);
					else
						S.push(s.substr(i, pos - i));
					i = pos - 1;
				}
				else
				{
					if (!S.empty() && S.top().find_first_of("[]1234567890") == string::npos)
						S.top() += s.substr(i);
					else
						S.push(s.substr(i));
					break;
				}
			}
		}
		while (!S.empty())
		{
			res += S.top();
			S.pop();
		}
		return res;
    }
};
