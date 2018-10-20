// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
// Each LED represents a zero or one, with the least significant bit on the right.
//
// For example, the above binary watch reads "3:25".
//
// Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
//
// Example:
// Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//
//
// Note:
//
// The order of output does not matter.
// The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
// The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina



string clocks[] = { "08","04","02","01","32","16","8","4","2","1" };

struct Mytime
{
	int hour;
	int minute;
	Mytime(int i = 0, int j = 0) :hour(i), minute(j) {}
	Mytime operator+=(const Mytime& r)
	{
		this->hour += r.hour;
		this->minute += r.minute;
		return *this;
	}

	bool isValid() {
		if (hour<12 && minute<60)
			return true;
		else return false;
	}
	string toString() {
		if (!isValid()) return "";
		if (minute<10)
			return to_string(hour) + ":0" + to_string(minute);
		else
			return to_string(hour) + ":" + to_string(minute);
	}
};

class Solution {
public:
	//string clocks[]={"08","04","02","01","32","16","8","4","2","1"};
public:


	vector<string> readBinaryWatch(int num)
	{
		//似乎只有用递归
		Mytime temp_time;
		readBinaryWatch(num, temp_time);
		set<string> s;
		for (auto& elem : result)
		{
			s.insert(elem);
		}
        result.clear();
		for (auto& elem : s)
		{
			result.push_back(elem);
		}
		return result;
	}

	void readBinaryWatch(int num, Mytime temp_time)
	{
		//似乎只有用递归
		if (num <= 0 && temp_time.isValid())
		{
			result.push_back(temp_time.toString());
			return;
		}

		for (int i = 0; i != 10; ++i)
		{
			if (clocks[i] == string("-1")) continue;//无效值
			auto old_time = temp_time;
			if (clocks[i][0] == '0')
			{
				string temp = clocks[i];				
				temp_time += Mytime(stoi(clocks[i]), 0);
				if (temp_time.isValid())
				{
					clocks[i] = "-1";
					readBinaryWatch(num - 1, temp_time);
					clocks[i] = temp;
					temp_time = old_time;
				}
				temp_time = old_time;
			}
			else
			{
				string temp = clocks[i];
				temp_time += Mytime(0, stoi(clocks[i]));
				if (temp_time.isValid())
				{
					clocks[i] = "-1";
					readBinaryWatch(num - 1, temp_time);
					clocks[i] = temp;
					temp_time = old_time;
				}
				else {
					temp_time = old_time;
					continue;
				}
				

			}
		}
	}


	vector<string> result;
};
