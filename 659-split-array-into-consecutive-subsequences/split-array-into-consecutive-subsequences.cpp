// You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
//
// Example 1:
//
// Input: [1,2,3,3,4,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3
// 3, 4, 5
//
//
//
// Example 2:
//
// Input: [1,2,3,3,4,4,5,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3, 4, 5
// 3, 4, 5
//
//
//
// Example 3:
//
// Input: [1,2,3,4,4,5]
// Output: False
//
//
//
// Note:
//
// The length of the input is in range of [1, 10000]
//
//


class Solution {
public:
    //1234 1234
bool isPossible(vector<int>& nums)
	{
		unordered_map<int, priority_queue<int, vector<int>, std::greater<int>>> backs;

		// Keep track of the number of sequences with size < 3
		int need_more = 0;

		for (int num : nums)
		{
			if (! backs[num - 1].empty())
			{	// There exists a sequence that ends in num-1
				// Append 'num' to this sequence
				// Remove the existing sequence
				// Add a new sequence ending in 'num' with size incremented by 1 
				int count = backs[num - 1].top();
				backs[num - 1].pop();
				backs[num].push(++count);

				if (count == 3)
					need_more--;
			}
			else
			{	// There is no sequence that ends in num-1
				// Create a new sequence with size 1 that ends with 'num'
				backs[num].push(1);
				need_more++;
			}
		}
		return need_more == 0;
	}
};
