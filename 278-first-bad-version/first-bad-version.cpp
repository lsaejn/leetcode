// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
//
// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//
// You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
//
// Example:
//
//
// Given n = 5, and version = 4 is the first bad version.
//
// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true
//
// Then 4 is the first bad version. 
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

// t t t f f f f f f
class Solution {
public:
    int firstBadVersion(int n) {
        //显然是二分查找
        int begin=1;
        int end=n;
        while(begin<end)
        {
            int mid=(end-begin)/2+begin;
            if(isBadVersion(mid))//是错误版本
            {
                if(!isBadVersion(mid-1))//前面是正确版本
                    return mid;
                else
                end=mid-1;
            }
            else if(!isBadVersion(mid))
            {               
                  if(isBadVersion(mid+1))//后面是f版本
                    return mid+1;
                  else
                    begin=mid+1;
            }
        }
        return 1;//begin==end or begin>end
        
    }
};
