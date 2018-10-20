//
// Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.
//
//
//
// If there is no solution for the equation, return "No solution".
//
//
// If there are infinite solutions for the equation, return "Infinite solutions".
//
//
// If there is exactly one solution for the equation, we ensure that the value of x is an integer.
//
//
// Example 1:
//
// Input: "x+5-3+x=6+x-2"
// Output: "x=2"
//
//
//
// Example 2:
//
// Input: "x=x"
// Output: "Infinite solutions"
//
//
//
// Example 3:
//
// Input: "2x=x"
// Output: "x=0"
//
//
//
// Example 4:
//
// Input: "2x+3x-6x=x+2"
// Output: "x=-1"
//
//
//
// Example 5:
//
// Input: "x=x+2"
// Output: "No solution"
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //依次读取左右,读取x系数，读取整形
    //但是如果再出一道包括乘除法的题，这个类就不能用了
    //123
string solveEquation(string equation)
{
	string left, right;
	auto pos = equation.find("=");
	left = equation.substr(0, pos);
	right = equation.substr(pos+1);
	auto p1 = split(left);
	auto p2 = split(right);
	int sumOfcol1 = 0; int sumOfx1 = 0;
	int sumOfcol2 = 0; int sumOfx2 = 0;
	for (int i = 0; i != p1.second.size(); ++i)
		sumOfcol1 += stoi(p1.second[i]);
	for (int i = 0; i != p2.second.size(); ++i)
		sumOfcol2 += stoi(p2.second[i]);
	for (int i = 0; i != p1.first.size(); ++i)
	{
		auto temp = p1.first[i];
		temp.pop_back();
		if (temp.size() == 1) temp += "1";
		sumOfx1 += stoi(temp);
	}
	for (int i = 0; i != p2.first.size(); ++i)
	{
		auto temp = p2.first[i];
		temp.pop_back();
		if (temp.size() == 1) temp += "1";
		sumOfx2 += stoi(temp);
	}
	sumOfx1 -= sumOfx2;
	sumOfcol2 -= sumOfcol1;
	//ax=b;
	if (!sumOfx1 && !sumOfcol2) return "Infinite solutions";
	if (!sumOfx1&&sumOfcol2)  return "No solution";
	else return "x=" + to_string(sumOfcol2 / sumOfx1);
}

pair<std::vector<std::string>, std::vector<std::string>> split(string equation)
{
	if (equation[0] != '-')
	equation = "+" + equation;//这样每个数都有符号了
	std::string::size_type pos1, pos2;
	std::vector<std::string> v;
	pos1 = 0;
	pos2 = equation.find_first_of("+-", 1 + pos1);
	while (std::string::npos != pos2)
	{
		v.push_back(equation.substr(pos1, pos2 - pos1));
		pos1 = pos2;
		pos2 = equation.find_first_of("+-", 1 + pos1);
	}
	v.push_back(equation.substr(pos1));
	std::vector<std::string> vx, col;
	for (auto&elem : v)
	{
		if (elem.back() == 'x')
			vx.push_back(elem);
		else
			col.push_back(elem);
	}
	return { vx,col };
}
};
