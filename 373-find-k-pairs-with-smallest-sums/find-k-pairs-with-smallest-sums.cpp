//
// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k. 
//
//
// Define a pair (u,v) which consists of one element from the first array and one element from the second array.
//
// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
//
//
// Example 1:
//
// Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
//
// Return: [1,2],[1,4],[1,6]
//
// The first 3 pairs are returned from the sequence:
// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//
//
//
// Example 2:
//
// Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
//
// Return: [1,1],[1,1]
//
// The first 2 pairs are returned from the sequence:
// [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
//
//
// Example 3:
//
// Given nums1 = [1,2], nums2 = [3],  k = 3 
//
// Return: [1,3],[2,3]
//
// All possible pairs are returned from the sequence:
// [1,3],[2,3]
//
//
//
// Credits:Special thanks to @elmirap and @StefanPochmann for adding this problem and creating all test cases." />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty()||nums2.empty()) return {};
		auto cmpLambda = [](const pair<int, pair<int, int>>&lhs, const pair<int, pair<int, int>> &rhs) {
			if (lhs.first<rhs.first) return true;
			else if (lhs.first == rhs.first)
			{
				if (lhs.second.first<rhs.second.first)
					return true;
				else if (lhs.second.first == rhs.second.first)
				{
					if (lhs.second.second<rhs.second.second) return true;
				}
			}
			return  false;
		};

		multiset<pair<int, pair<int, int>>, decltype(cmpLambda)> col(cmpLambda);
		for (int i = 0; i != nums1.size(); ++i)
			for (int j = 0; j != nums2.size(); ++j)
			{
				pair<int, pair<int, int>> temp = { nums1[i] + nums2[j],{ i,j } };
				col.insert(temp);
			}
				
		vector<pair<int, int>> re;
		auto iter = col.begin();
		while (k>0)
		{
			re.push_back({nums1[iter->second.first],nums2[iter->second.second]});
			k--;
			iter++;
			if (iter == col.end()) break;
		}
		return re;
	}
};
