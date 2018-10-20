// Given a chemical formula (given as a string), return the count of each atom.
//
// An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
//
// 1 or more digits representing the count of that element may follow if the count is greater than 1.  If the count is 1, no digits will follow.  For example, H2O and H2O2 are possible, but H1O2 is impossible.
//
// Two formulas concatenated together produce another formula.  For example, H2O2He3Mg4 is also a formula.  
//
// A formula placed in parentheses, and a count (optionally added) is also a formula.  For example, (H2O2) and (H2O2)3 are formulas.
//
// Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.
//
// Example 1:
//
// Input: 
// formula = "H2O"
// Output: "H2O"
// Explanation: 
// The count of elements are {'H': 2, 'O': 1}.
//
//
//
// Example 2:
//
// Input: 
// formula = "Mg(OH)2"
// Output: "H2MgO2"
// Explanation: 
// The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
//
//
//
// Example 3:
//
// Input: 
// formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
// Explanation: 
// The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
//
//
//
// Note:
// All atom names consist of lowercase letters, except for the first character which is uppercase.
// The length of formula will be in the range [1, 1000].
// formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.
//


class Solution {
public:
string countOfAtoms(const string& formula) 
{
	//就像计算器一样，用栈来做，我就不亲自写了。。。？
	//逻辑是这样，遍历字符。入栈，单词依次入栈。
	//{K,1}入，4，{K,4}出，括号入，O入，N入，括号入，S,1入，O,1入,O,3入，S,2,O,6入，。。。。
	string re;
	stack<pair<string, int>> s;
	for (int i = 0; i != formula.size(); ++i)
	{
		if (isupper(formula[i]))//当前字符大写
		{
				s.push({ string() + formula[i],1 });
		}
		else if (islower(formula[i]))//小写，前面一定是大写字符，
		{
			s.top().first += string() + formula[i];
		}
		else if (formula[i] == '(' || formula[i] == ')')
		{
			s.push({ string() + formula[i],1 });
		}
		else if(isdigit(formula[i]))//use isdigit()
		{
			string num;
			num += formula[i];
			while ((i + 1) < formula.size() && (isalnum(formula[i + 1]) && !isalpha(formula[i + 1])))
			{
				num += formula[i+1];
				++i;
			}
			if (s.top().first != ")")
				s.top().second *= stoi(num);
			else
			{
				s.pop();//")"
				vector<decltype(s)::value_type> vec;
				while (s.top().first != "(")
				{
					auto elem = s.top();
					s.pop();
					elem.second *= stoi(num);
					vec.push_back(elem);
				}
				s.pop();
				for (auto &elem : vec)
					s.push(std::move(elem));
			}
		}
	}
	map<string, int> rem;
	while (!s.empty())
	{
		rem[s.top().first] += s.top().second;
		s.pop();
	}
	for (auto &elem : rem)
	{
		re += elem.first;
		if(elem.second>1)
			re += to_string(elem.second);
	}
	return re;
}
};
