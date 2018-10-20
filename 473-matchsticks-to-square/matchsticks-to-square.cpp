// Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//
//  Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.
//
// Example 1:
//
// Input: [1,1,2,2,2]
// Output: true
//
// Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
//
//
//
// Example 2:
//
// Input: [3,3,3,3,4]
// Output: false
//
// Explanation: You cannot find a way to form a square with all the matchsticks.
//
//
//
// Note:
//
// The length sum of the given matchsticks is in the range of 0 to 10^9.
// The length of the given matchstick array will not exceed 15.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public://本质就是分成4个组，每组sum/4根火柴
	bool makesquare(vector<int>& nums) {
        if(nums.size()<4) return false;
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int width = sum / 4;
		if (width * 4<sum) return false;
        //sort(nums.begin(), nums.end());惊人的是，一旦我们排序，就会超时
		//if (nums.back()>width) return false;
		vector<bool> used(nums.size());
		auto b = help(nums, width, used, 0, 0);
		return b ;
	}

	bool help(vector<int>& nums, int target, vector<bool>& used, int found, int currentSum)
	{
		if (found == 4) return true;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (used[i] == true) continue;
			if (currentSum + nums[i]>target)
				return false;
			//else
			else if (currentSum + nums[i] == target)
			{
				used[i] = true;
				if (help(nums,target, used, found + 1, 0)) return true;
				used[i] = false;
			}
			else
			{
				used[i] = true;
				if (help(nums, target, used, found, currentSum + nums[i])) return true;
                //我在这里犯了一个错误，如果当前和小于宽，选择 加上它/不加上它继续遍历
                //实际上是不必要的。因为我们加上它遍历失败，那么自然下一个循环就不会加上它。逻辑由for控制
                //if (help(nums, target, used, found, currentSum)) return true;
				used[i] = false;
			}
		}
		return false;
	}
};
