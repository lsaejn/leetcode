//
// Given an array of integers A and let n to be its length.
//
//
//
// Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:
//
//
//
// F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
//
// Calculate the maximum value of F(0), F(1), ..., F(n-1). 
//
//
// Note:
// n is guaranteed to be less than 105.
//
//
// Example:
//
// A = [4, 3, 2, 6]
//
// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
//
// So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
//
//


class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        //先暴力试一试
		if (A.empty()) return 0;
		int sum = accumulate(A.begin(), A.end(), 0);//25
		int j = 0;
		int max = 0;
		max = accumulate(A.begin(), A.end(), max, [&j](int max, int elem) {return  max + elem * j++; });
		int k = A.size() - 1;//需要计算n-1次
		int last = max;
		for (int i = 0; i != k; ++i)//每次需要删除尾部的积，尾部索引k-i,然后其他数加上一遍
		{
			last = last - k * A[k - i] + sum - A[k - i];
			max = max>last ? max : last;
		}
		return max;
    }
};
