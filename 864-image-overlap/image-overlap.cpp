// Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)
//
// We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.
//
// (Note also that a translation does not include any kind of rotation.)
//
// What is the largest possible overlap?
//
// Example 1:
//
//
// Input: A = [[1,1,0],
//             [0,1,0],
//             [0,1,0]]
//        B = [[0,0,0],
//             [0,1,1],
//             [0,0,1]]
// Output: 3
// Explanation: We slide A to right by 1 unit and down by 1 unit.
//
// Notes: 
//
//
// 	1 <= A.length = A[0].length = B.length = B[0].length <= 30
// 	0 <= A[i][j], B[i][j] <= 1
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
	//这个题是纯体力活。。。。
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int max = 0;
		for (int i = 0; i<A.size(); ++i)
			for (int j = 0; j<A[0].size(); ++j)
				max = std::max(std::max(getCount(A, B, i, j), max),std::max(getCount(B, A, i, j), max));
		return max;
	}

	int getCount(vector<vector<int>>& A, vector<vector<int>>& B, int right, int down)
	{
		int count = 0;
		for (int i = down, i2=0; i != B.size(); ++i,++i2)
			for (int j = right,j2=0; j != B.size(); ++j,++j2)
			{
				if (A[i2][j2] == B[i][j] && A[i2][j2] == 1)
					count++;					
			}
		return count;
	}
};
