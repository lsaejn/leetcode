// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
//
//
//
// Example 2:
//
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
//
//
// Note:
//
//
// 	Each element in the result must be unique.
// 	The result can be in any order.
//
//
//  
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //遍历nums1，若元素在nums2里，则放到结果
        vector<int> result;
        for(auto elem:nums1)
            for(auto elem2:nums2)
            {
                if(elem==elem2)
                {
                    result.push_back(elem);
                    break;
                }
            }
        sort(result.begin(),result.end());
        auto erase_iter=unique(result.begin(),result.end());
        result.erase(erase_iter,result.end());
        return result;
        
    }
};
