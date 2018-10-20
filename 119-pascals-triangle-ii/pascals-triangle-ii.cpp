// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
//
// Note that the row index starts from 0.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 3
// Output: [1,3,3,1]
//
//
// Follow up:
//
// Could you optimize your algorithm to use only O(k) extra space?
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
	vector<int> getRow(int rowIndex) 
    {
        if(rowIndex<0) return {};
        if(0==rowIndex) return {1};
		vector<int> re(rowIndex / 2 + 1);//开辟前一半空间即可
		for (int j = 1; j<=rowIndex; ++j)//行数，以1，1为第一行，修改6次
			for (int i = j / 2 ; i >= 0; --i)//每行修改前 行数/2+1 个元素
			{
				if (i == 0)
					re[i] = 1;
				else if (i == 1)
					re[i] = (j);
				else if (i == j / 2)//我们从尾巴开始修改元素
				{
					if (j  % 2 == 0)//奇数行
						re[i] = 2 * re[i - 1];
					else
						re[i] = re[i] + re[i - 1];
				}
				else
					re[i] = re[i] + re[i - 1];
			}
        vector<int> temp;
        if(rowIndex%2==1)
        {
            temp=re;
        }
        else
        {
            copy(re.begin(),re.end()-1,back_inserter(temp));
        }
        reverse(temp.begin(),temp.end());
        for(auto elem:temp)
            re.push_back(elem);
		return re;
	}
};
