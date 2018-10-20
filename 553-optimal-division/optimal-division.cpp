// Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.
//
// However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.
//
// Example:
//
// Input: [1000,100,10,2]
// Output: "1000/(100/10/2)"
// Explanation:
// 1000/(100/10/2) = 1000/((100/10)/2) = 200
// However, the bold parenthesis in "1000/((100/10)/2)" are redundant, since they don't influence the operation priority. So you should return "1000/(100/10/2)". 
//
// Other cases:
// 1000/(100/10)/2 = 50
// 1000/(100/(10/2)) = 50
// 1000/100/10/2 = 0.5
// 1000/100/(10/2) = 2
//
//
//
// Note:
//
// The length of the input array is [1, 10].
// Elements in the given array will be in range [2, 1000].
// There is only one optimal division for each test case.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //每个数字都可以决定直接除以后面的数字，或者递归后面的数字
    //然而这是个数学题。
    //想要最大，显然是a*c*d*..../b
    string optimalDivision(vector<int>& nums)
    {      
        int denominatorCnt = nums.size()-1;
        string numerator = to_string(nums[0]); //被除数
        if(denominatorCnt==0)return numerator; //没有除数的情况
        string denominator = ""; //除数
        int i;
        for(i=1;i<nums.size()-1;i++)
        {
            denominator+=to_string(nums[i]);
            denominator+="/";
        }
        denominator+=to_string(nums[i]);
        if(denominatorCnt>1)
            denominator = "("+denominator+")";
        return numerator+"/"+denominator;
    }
};
