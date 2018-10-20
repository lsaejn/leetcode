// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    //如果要查找的数的右边有序，那我们很快就能找到有多少个比自己少的元素，
    //支持二分查找、自动排序、快速插入的数据结构是multiset
    //但是这里超时了。原因大概是什么？也许是需要反复的调解平衡。这真是出人意料的打击，所以搜索树更适合大量数据的查询？
    //http://www.cnblogs.com/grandyang/p/5078490.html第三种解法非常巧妙，颇有当初java算法书的简洁感
    vector<int> countSmaller(vector<int>& nums) 
    {
        /*
        vector<int> res(nums.size());
        multiset<int> t;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            auto iter=t.lower_bound(nums[i]);
            int d = distance(t.begin(), iter);//不小于nums[i]的迭代器
            res[i] = d;
            t.insert(iter,move(nums[i]));
        }
        return res;
        */
        
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) 
        {
            int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
            res[i] = d;
            t.insert(t.begin() + d, nums[i]);
        }
        return res;
    }
};
