// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
// Note:
//
// You can assume that you can always reach the last index.


class Solution {
public:
    //有点像bfs，每一次跳跃会有个可到达范围(index)，我们遍历整个index
    //可以得到下一次能到达的最大范围。
int jump(vector<int>& nums) {
	int res = 0;
	int n = nums.size();
	int pos_pre = 0, pos_now = 0;
	while (pos_now < n - 1)
	{	
        int start=pos_pre;
		pos_pre = pos_now;//记录当前位置
		while (start <= pos_pre)//上一次的点到当前位置所有的点
		{
			pos_now = max(pos_now, start + nums[start]);//选择那个跳得最远的点
			start++;
		}
		if (pos_pre == pos_now) return -1; // May not need this
		++res;//跳一次
	}
	return res;
}
};
