// Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
//
//
// Note:
// The number of people is less than 1,100.
//
//
//
//
// Example
//
// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //如果顺着题意做，思路是这样的，找到身高的人，它身前的序数就是该安插的位置。注意，这个位置是空着的位置的序号
    //为了提高查找速度，我们以身高排序
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
{
	sort(people.begin(), people.end(), [](pair<int, int>& x1, pair<int, int>& x2) {return x1.first<x2.first; });
	vector<pair<int, int>> result(people.size(), { -1,-1 });
	for (auto &elem : people)
	{
		int count = elem.second+1;//不比自己first小的元素个数
		for (int j = 0; j<result.size();++j)
		{
			if (result[j].first>=elem.first|| result[j].first==-1)
			{
				--count;
				if (count == 0)
				{
					result[j] = elem;
					break;
				}
			}
		}
	}
	return result;
}
};
