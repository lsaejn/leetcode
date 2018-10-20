//
// N couples sit in 2N seats arranged in a row and want to hold hands.  We want to know the minimum number of swaps so that every couple is sitting side by side.  A swap consists of choosing any two people, then they stand up and switch seats. 
//
// The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).
//
// The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.
//
// Example 1:
// Input: row = [0, 2, 1, 3]
// Output: 1
// Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
//
//
// Example 2:
// Input: row = [3, 2, 0, 1]
// Output: 0
// Explanation: All couples are already seated side by side.
//
//
//
// Note:
//
//  len(row) is even and in the range of [4, 60].
//  row is guaranteed to be a permutation of 0...len(row)-1.
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
	int minSwapsCouples(vector<int>& row) 
    {
		unordered_map<int, int> col;//id,index
		for (int i = 0; i< row.size(); ++i)
			col[row[i]] = i;
		int result = INT32_MAX;
		dfs(result, row, 0, 0, col);
		return result;
	}

	int dfs(int& result, vector<int>& row, int begin, int num_now, unordered_map<int, int>& col)
	{
		if (begin == row.size()) 
            return result = num_now<result ? num_now: result;
        int i=begin;
		if (((row[i] == row[i + 1] + 1) && (row[i] % 2 == 1)) || (((row[i] == row[i + 1] - 1) && (row[i] % 2 == 0))))//成对
			dfs(result, row, begin + 2, num_now, col);
		else
		{		
            int target=0;
			if (row[i] % 2 == 0)//不匹配，第一位置是偶数x，换掉后面成x-1 0,2,1,3->0,1,2,3
				target = row[i] + 1;
			else//1,3,0,2->1,0,3,2
				target = row[i] - 1;//0
            int index_of_target = col[target];
			swap(col[row[i + 1]], col[target]);//
			swap(row[i+1], row[index_of_target]);//3,0->0,3				
			dfs(result, row, begin + 2, num_now + 1, col);
            //swap(col[row[i + 1]], col[target]);//
			//swap(row[i + 1], row[index_of_target]);	
		}
		return 0;
	}


};
